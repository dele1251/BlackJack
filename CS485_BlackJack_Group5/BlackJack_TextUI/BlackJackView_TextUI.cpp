//****************************************************************************
// File name:		BlackJackView_TextUI.cpp
// Author:			Kyle Pestka
// Date:				5/1/2017
// Class:				CS485
// Assignment:	BlackJack_Group5
// Purpose:			Impliment the class BlackJackView_TextUI
//****************************************************************************

#include "BlackJackView_TextUI.h"
#include "BlackJackPresenter.h"

const std::string BlackJackView_TextUI::DEFAULT_STRATEGY = "NORMAL";

//***************************************************************************
// Function:		BlackJackView_TextUI
//
// Description: Ctor
//
// Parameters:  std::cout - Standard output
//              std::cin  - Standard input
//
// Returned:    None
//***************************************************************************
BlackJackView_TextUI::BlackJackView_TextUI (): TextUI (std::cout, std::cin)
{

  mpcBlackJackPresenter = new BlackJackPresenter (this);

  mpGameTitle = new TextUITextWidget ("*************\n**Blackjack**\n*************\n", "");

  mpNumPlayers = new TextUITextWidget ("Number of Players", "");
  mpNumCPUs = new TextUITextWidget ("Number of Computers", "");
  mpNumDecks = new TextUITextWidget ("Number of Decks", "");

  mpNumPlayers->setVisible (false);
  mpNumCPUs->setVisible (false);
  mpNumDecks->setVisible (false);

  addWidget (0, 0, mpGameTitle);
  addWidget (0, 1, mpNumPlayers);
  addWidget (0, 3, mpNumCPUs);
  addWidget (0, 5, mpNumDecks);

  registerEvent ("PLAY", std::bind (&BlackJackView_TextUI::onPlay, this, std::placeholders::_1));
  registerEvent ("QUIT", nullptr);
}

//***************************************************************************
// Function:		~BlackJackView_TextUI
//
// Description: Dtor
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
BlackJackView_TextUI::~BlackJackView_TextUI ()
{
  delete mpcBlackJackPresenter;
}

//***************************************************************************
// Function:		onPlay
//
// Description: Allows you to pick players, cpus, and decks
//
// Parameters:  command - The string past after
//
// Returned:    None
//***************************************************************************
void BlackJackView_TextUI::onPlay (std::string command)
{
  unRegisterEvent ("PLAY");

  registerEvent ("PLAYERS", std::bind (&BlackJackView_TextUI::onSetNumPlayer, this, std::placeholders::_1));
  registerEvent ("COMPUTERS", std::bind (&BlackJackView_TextUI::onSetNumCPU, this, std::placeholders::_1));
  registerEvent ("DECKS", std::bind (&BlackJackView_TextUI::onSetNumDeck, this, std::placeholders::_1));
  registerEvent ("NEXT", std::bind (&BlackJackView_TextUI::onNextNames, this, std::placeholders::_1));

  mpGameTitle->setVisible (false);
  mpNumPlayers->setVisible (true);
  mpNumCPUs->setVisible (true);
  mpNumDecks->setVisible (true);

  mpcBlackJackPresenter->P_SetNumPlayer ("1");
  mpcBlackJackPresenter->P_SetNumCPU ("0");
  mpcBlackJackPresenter->P_SetNumDecks ("1");
}

//***************************************************************************
// Function:		onNextNames
//
// Description: Allows you to set names, balances, and strat.
//
// Parameters:  command - The string past after
//
// Returned:    None
//***************************************************************************
void BlackJackView_TextUI::onNextNames (std::string command)
{
  unRegisterEvent ("PLAYERS");
  unRegisterEvent ("COMPUTERS");
  unRegisterEvent ("DECKS");
  unRegisterEvent ("NEXT");

  mpDealerID = new TextUITextWidget ("Dealer", "");
  mpDealerID->setVisible (false);

  mpNumPlayers->setVisible (false);
  mpNumCPUs->setVisible (false);
  mpNumDecks->setVisible (false);

  std::vector <std::string> names;
  for (int i = 0; i < stoll (mpNumPlayers->getData ()); i++)
  {
     names.push_back ("PLAYER" + to_string (i + 1));
     mpPlayersNames[i] = new TextUITextWidget ("PLAYER" + to_string (i + 1), "$1000.00");
  }
  for (int i = 0; i < stoll (mpNumCPUs->getData ()); i++)
  {
    names.push_back ("CPU" + to_string (i + 1));
    mpPlayersNames[i + stoll (mpNumPlayers->getData ())] = new TextUITextWidget ("CPU" + to_string (i + 1), "$1000.00");
    mpCPUStrats[i] = new TextUITextWidget ("STRAT", "NORMAL");
  }

  mpcBlackJackPresenter->P_InitializePlayers (names, DEFAULT_BANK, DEFAULT_STRATEGY);
  
  registerEvent ("NAME", std::bind (&BlackJackView_TextUI::onSetPlayerName, this, std::placeholders::_1));
  registerEvent ("BALANCE", std::bind (&BlackJackView_TextUI::onSetBankAccount, this, std::placeholders::_1));
  registerEvent ("STRAT", std::bind (&BlackJackView_TextUI::onSetCPUStrat, this, std::placeholders::_1));
  registerEvent ("START", std::bind (&BlackJackView_TextUI::onStartBets, this, std::placeholders::_1));

  for (int i = 0; i < stoll (mpNumPlayers->getData ()) + stoll (mpNumCPUs->getData ()); i++)
  {
    addWidget (1, i + 2, mpPlayersNames[i]);
    if (mpPlayersNames[i]->getLabel ().substr (0, 3) == "CPU")
    {
      addWidget (20, i + 2, mpCPUStrats[i - stoll (mpNumPlayers->getData ())]);
    }

    if (i == stoll (mpNumPlayers->getData ()) + stoll (mpNumCPUs->getData ()) - 1)
    {
      addWidget (1, i + 3, mpDealerID);
    }
  }
  
 
}

//***************************************************************************
// Function:		onStartBets
//
// Description: Allows you to bet
//
// Parameters:  command - The amount of the bet
//
// Returned:    None
//***************************************************************************
void BlackJackView_TextUI::onStartBets (std::string command)
{
  unRegisterEvent ("NAME");
  unRegisterEvent ("BALANCE");
  unRegisterEvent ("STRAT");
  unRegisterEvent ("START");

  onStartGame ();

  for (int i = 0; i < stoll (mpNumPlayers->getData ()); i++)
  {
    mpBets[i] = new TextUITextWidget ("Bet amount", "$0.00");
    addWidget (20, i + 2, mpBets[i]);
  }
  for (int i = 0; i < stoll (mpNumCPUs->getData ()); i++)
  {
    mpCPUStrats[i]->setVisible (false);
  }


  mpCurrentBetter = new TextUITextWidget (mpPlayersNames[0]->getLabel (), "Time to bet!!!");
  addWidget (1, 8, mpCurrentBetter);
  registerEvent ("BET", std::bind (&BlackJackView_TextUI::onSetBet, this, std::placeholders::_1));
  registerEvent ("DONE", std::bind (&BlackJackView_TextUI::onStartRound, this, std::placeholders::_1));

}

//***************************************************************************
// Function:		onStartRound
//
// Description: Play screen
//
// Parameters:  command - The string passed with it
//
// Returned:    None
//***************************************************************************
void BlackJackView_TextUI::onStartRound (std::string command)
{
  unRegisterEvent ("BET");
  unRegisterEvent ("DONE");

  mpCurrentBetter->setVisible (false);


  for (int i = 0; i < stoll (mpNumPlayers->getData ()) + stoll (mpNumCPUs->getData ()) + 1; i++)
  {
    mpCards[i] = new TextUITextWidget ("Card Value:", "");
    addWidget (40, i + 2, mpCards[i]);
  }

  registerEvent ("HIT", std::bind (&BlackJackView_TextUI::onClickHit, this, std::placeholders::_1));
  registerEvent ("STAY", std::bind (&BlackJackView_TextUI::onClickStay, this, std::placeholders::_1));
  registerEvent ("SPLIT", std::bind (&BlackJackView_TextUI::onClickSplit, this, std::placeholders::_1));
  mpcBlackJackPresenter->P_StartRound ();
}

//***************************************************************************
// Function:		onNetRound
//
// Description: Select new round bets
//
// Parameters:  command - The string passed with it
//
// Returned:    None
//***************************************************************************
void BlackJackView_TextUI::onNetRound (std::string command)
{

  for (int i = 0; i < stoll (mpNumPlayers->getData ()) + stoll (mpNumCPUs->getData ()) + 1; i++)
  {
    mpCards[i]->setVisible (false);
  }

  mpDealerID->setVisible (false);

  for (int i = 0; i < stoll (mpNumPlayers->getData ()); i++)
  {
    mpBets[i]->setData ("$0.00");
  }

  registerEvent ("BET2", std::bind (&BlackJackView_TextUI::onSetBet, this, std::placeholders::_1));
  registerEvent ("DONE2", std::bind (&BlackJackView_TextUI::onTestRound, this, std::placeholders::_1));
}

//***************************************************************************
// Function:		onTestRound
//
// Description: Trying to play second round
//
// Parameters:  command - The string passed with it
//
// Returned:    None
//***************************************************************************
void BlackJackView_TextUI::onTestRound (std::string command)
{
  unRegisterEvent ("BET2");
  unRegisterEvent ("DONE2");

  //mpCurrentBetter->setVisible (false);


  for (int i = 0; i < stoll (mpNumPlayers->getData ()) + stoll (mpNumCPUs->getData ()) + 1; i++)
  {
    mpCards[i] = new TextUITextWidget ("Card Value:", "");
    addWidget (40, i + 2, mpCards[i]);
  }

  registerEvent ("HIT", std::bind (&BlackJackView_TextUI::onClickHit, this, std::placeholders::_1));
  registerEvent ("STAY", std::bind (&BlackJackView_TextUI::onClickStay, this, std::placeholders::_1));
  registerEvent ("SPLIT", std::bind (&BlackJackView_TextUI::onClickSplit, this, std::placeholders::_1));
  mpcBlackJackPresenter->P_StartRound ();
}

//***************************************************************************
// Function:		onSetNumPlayer
//
// Description: Set number on players
//
// Parameters:  numPlayer - Number of players
//
// Returned:    None
//***************************************************************************
void BlackJackView_TextUI::onSetNumPlayer (std::string numPLayer)
{
  int num;
  std::istringstream cString (numPLayer);
  if (cString >> num)
  {
    mpcBlackJackPresenter->P_SetNumPlayer (numPLayer);
  }
}

//***************************************************************************
// Function:		onSetNumCPU
//
// Description: Sets the number of CPUs
//
// Parameters:  numCPU  - Number of CPUs
//
// Returned:    None
//***************************************************************************
void BlackJackView_TextUI::onSetNumCPU (std::string numCPU)
{
  int num;
  std::istringstream cString (numCPU);
  if (cString >> num)
  {
    mpcBlackJackPresenter->P_SetNumCPU (numCPU);
  }
}

//***************************************************************************
// Function:		onSetNumDeck
//
// Description: Sets the number of decks
//
// Parameters:  numDeck - Number of Decks
//
// Returned:    None
//***************************************************************************
void BlackJackView_TextUI::onSetNumDeck (std::string numDeck)
{
  int num;
  std::istringstream cString (numDeck);
  if (cString >> num)
  {
    mpcBlackJackPresenter->P_SetNumDecks (numDeck);
  }
}

//***************************************************************************
// Function:		onSetPlayerName
//
// Description: Sets a players name
//
// Parameters:  command - The old and new name
//
// Returned:    None
//***************************************************************************
void BlackJackView_TextUI::onSetPlayerName (std::string command)
{
  std::string playerName;
  std::string playerNewName;
  std::istringstream ssPlayerName (command);
  if (ssPlayerName >> playerName)
  {
    if (ssPlayerName >> playerNewName)
    {
      mpcBlackJackPresenter->P_SetPlayerName (playerName, playerNewName);
    }
    else
    {

    }

  }
  else
  {

  }

}

//***************************************************************************
// Function:		onSetBankAccount
//
// Description: Sets a bank account
//
// Parameters:  command - New amount
//
// Returned:    None
//***************************************************************************
void BlackJackView_TextUI::onSetBankAccount (std::string command)
{
  std::string playerName;
  std::string amount;
  std::istringstream ssPlayerName (command);
  if (ssPlayerName >> playerName)
  {
    if (ssPlayerName >> amount)
    {
      mpcBlackJackPresenter->P_SetBankAccount (playerName, amount);
    }
    else
    {

    }

  }
  else
  {

  }
}

//***************************************************************************
// Function:		onSetCPUStrat
//
// Description: Set a CPUs strat
//
// Parameters:  command - New strat
//
// Returned:    None
//***************************************************************************
void BlackJackView_TextUI::onSetCPUStrat (std::string command)
{
  std::string CPUName;
  std::string CPUStrat;
  std::istringstream ssPlayerName (command);
  if (ssPlayerName >> CPUName)
  {
    if (ssPlayerName >> CPUStrat)
    {
      mpcBlackJackPresenter->P_SetCPUStrategy (CPUName, CPUStrat);
    }
    else
    {

    }

  }
  else
  {

  }
}

//***************************************************************************
// Function:		onStartGame
//
// Description: Calls presenter to start
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void BlackJackView_TextUI::onStartGame ()
{
  mpcBlackJackPresenter->P_StartGame ();
}

//***************************************************************************
// Function:		onSetBet
//
// Description: Set a bet
//
// Parameters:  command - The bet amount
//
// Returned:   None 
//***************************************************************************
void BlackJackView_TextUI::onSetBet (std::string command)
{
  int num;
  std::istringstream cString (command);
  if (cString >> num)
  {
    mpcBlackJackPresenter->P_Bet (command);
  }
}

//***************************************************************************
// Function:		onRunCPUCommands
//
// Description: Tells the presenter to run a cpu command
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void BlackJackView_TextUI::onRunCPUCommands ()
{
  mpcBlackJackPresenter->P_CPUTurn ();
}

//***************************************************************************
// Function:		onClickHit
//
// Description: Select Hit
//
// Parameters:  commands - The string passed with it
//
// Returned:    None
//***************************************************************************
void BlackJackView_TextUI::onClickHit (std::string commands)
{
  mpcBlackJackPresenter->P_Hit ();
}

//***************************************************************************
// Function:		onClickStay
//
// Description: Select stay
//
// Parameters:  commands  - The string passed with it
//
// Returned:    None
//***************************************************************************
void BlackJackView_TextUI::onClickStay (std::string commands)
{
  mpcBlackJackPresenter->P_Stay ();
}

//***************************************************************************
// Function:		onClickSplit
//
// Description: Selected split
//
// Parameters:  commands  - The string passed with it
//
// Returned:    None
//***************************************************************************
void BlackJackView_TextUI::onClickSplit (std::string commands)
{
  mpcBlackJackPresenter->P_Split ();
}

//***************************************************************************
// Function:		V_SetNumPlayer
//
// Description: Sets the number of players in view
//
// Parameters:  numPlayers  - The number of players
//
// Returned:    None
//***************************************************************************
void BlackJackView_TextUI::V_SetNumPlayer (std::string numPlayer)
{
  mpNumPlayers->setData (numPlayer);
}

//***************************************************************************
// Function:		V_SetNumCPU
//
// Description: Sets the numbers of CPUs in the view
//
// Parameters:  numCPU  - The number of cpus
//
// Returned:    None
//***************************************************************************
void BlackJackView_TextUI::V_SetNumCPU (std::string numCPU)
{
  mpNumCPUs->setData (numCPU);
}

//***************************************************************************
// Function:		V_SetNumDeck
//
// Description: Sets the number of decks in the view
//
// Parameters:  numDeck - Number of decks
//
// Returned:    None
//***************************************************************************
void BlackJackView_TextUI::V_SetNumDeck (std::string numDeck)
{
  mpNumDecks->setData (numDeck);
}

//***************************************************************************
// Function:		V_SetPlayerName
//
// Description: Sets a players name in the view
//
// Parameters:  playerName    - Old name
//              playerNewName - New name
//
// Returned:    None
//***************************************************************************
void BlackJackView_TextUI::V_SetPlayerName (std::string playerName, std::string playerNewName)
{
  for (int i = 0; i < stoll (mpNumPlayers->getData ()) + stoll (mpNumCPUs->getData ()); i++)
  {
    if (mpPlayersNames[i]->getLabel () == playerName)
    {
      mpPlayersNames[i]->setLabel (playerNewName);
    }
  }
  
}

//***************************************************************************
// Function:		V_SetBankAccount
//
// Description: Sets the bank accounts within the view
//
// Parameters:  playerName  - Players name
//              amount      - Bank account amount
//
// Returned:    None
//***************************************************************************
void BlackJackView_TextUI::V_SetBankAccount (std::string playerName, std::string amount)
{
  for (int i = 0; i < stoll (mpNumPlayers->getData ()) + stoll (mpNumCPUs->getData ()); i++)
  {
    if (mpPlayersNames[i]->getLabel () == playerName)
    {
      mpPlayersNames[i]->setData (amount);
    }
  }
}

//***************************************************************************
// Function:		V_SetCPUStrat
//
// Description: Sets the cpu strat within the view
//
// Parameters:  CPUName   - CPUs name
//              CPUStrat  - New strat
//
// Returned:    None
//***************************************************************************
void BlackJackView_TextUI::V_SetCPUStrat (std::string CPUName, std::string CPUStrat)
{
  for (int i = 0; i < stoll (mpNumCPUs->getData ()); i++)
  {
    if (mpPlayersNames[i + stoll (mpNumPlayers->getData ())]->getLabel () == CPUName)
    {
      mpCPUStrats[i]->setData (CPUStrat);
    }
  }
}

//***************************************************************************
// Function:		V_onSetBet
//
// Description: Sets the bet within the view
//
// Parameters:  bet   - The bet
//
// Returned:    None
//***************************************************************************
void BlackJackView_TextUI::V_onSetBet (std::string bet)
{
  for (int i = 0; i < stoll (mpNumPlayers->getData ()); i++)
  {
    if (mpBets[i]->getData () == "$0.00")
    {
      mpBets[i]->setData (bet);
      if (mpBets[i]->getData () != "$0.00" && i + 1 < stoll (mpNumPlayers->getData ()))
      {
        mpCurrentBetter->setLabel (mpPlayersNames[i + 1]->getLabel ());
      }
      else
      {
        mpCurrentBetter->setVisible (false);
      }
      break;
    }
  }
  

}

//***************************************************************************
// Function:		V_StartRound
//
// Description: Gives the cards at start of game
//
// Parameters:  handRepresentation  - Vector of hands
//
// Returned:    None
//***************************************************************************
void BlackJackView_TextUI::V_StartRound (std::vector<std::string> handRepresentation)
{


  for (int i = 0; i < stoi (mpNumPlayers->getData ()) + stoi (mpNumCPUs->getData ()); i++)
  {

    std::string hand = handRepresentation.at (i).substr (0, handRepresentation.at (i).length () - 5);

    mpCards[i]->setData (hand + "(??)");
    mpCards[i]->setVisible (true);
  }

  mpDealerID->setVisible (true);
 
  std::string hand = handRepresentation.at (stoi (mpNumPlayers->getData ()) + 
    stoi (mpNumCPUs->getData ())).substr (0, handRepresentation.at (stoi (mpNumPlayers->getData ()) + stoi (mpNumCPUs->getData ())).length () - 5);

  mpCards[stoll (mpNumPlayers->getData ()) + stoi (mpNumCPUs->getData ())]->setData (hand + "(??)");

  mpcBlackJackPresenter->P_StartTurn ();
}

//***************************************************************************
// Function:		V_Hit
//
// Description: Adds a new card to a hand in  the view
//
// Parameters:  handRepresentation  - The players hand
//              cardRepresentatio   - The players new card
//
// Returned:    None
//***************************************************************************
void BlackJackView_TextUI::V_Hit (std::string handRepresentation, std::string cardRepresentatio)
{
  std::string index = handRepresentation.substr (0, 1);
  std::string hand = handRepresentation.substr (2, handRepresentation.length () - 2);

  mpCards[stoll (index)]->setData (hand);
  
}

//***************************************************************************
// Function:		V_Stay
//
// Description: Sets stay in the view
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void BlackJackView_TextUI::V_Stay ()
{
  mpcBlackJackPresenter->P_StartTurn ();
}

//***************************************************************************
// Function:		V_EndRound
//
// Description: Sets the end of a round in the view
//
// Parameters:  bankBalance       - Vector of new bank balances
//              bankruptPlayerID  - Vector of indexs of bankrupt players
//              bankruptCPUID     - Vector of indexs of bankrupt CPUs
//
// Returned:    none
//***************************************************************************
void BlackJackView_TextUI::V_EndRound (std::vector<std::string> bankBalance, std::vector <int> bankruptPlayerID, std::vector <int> bankruptCPUID)
{
  /*for (int i = 0; i < stoll (mpNumPlayers->getData ()) + stoll (mpNumCPUs->getData ()); i++)
  {
    if (i < bankBalance.size ())
    {
      mpNumPlayers[i].setData (bankBalance.at (i));
    }
  }*/

  unRegisterEvent ("HIT");
  unRegisterEvent ("STAY");
  unRegisterEvent ("SPLIT");

  registerEvent ("DONE", std::bind (&BlackJackView_TextUI::onNetRound, this, std::placeholders::_1));
}

//***************************************************************************
// Function:		V_StartTurn
//
// Description: Sets the start turn in the view
//
// Parameters:  handRepresentation  - The player hand
//
// Returned:    None
//***************************************************************************
void BlackJackView_TextUI::V_StartTurn (std::string handRepresentation)
{
  std::string index = handRepresentation.substr (0, 1);
  std::string hand = handRepresentation.substr (2, handRepresentation.length () - 2);

  //mpCurrentBetter->setLabel (mpPlayersNames[stoll(index)]->getLabel ());
  //mpCurrentBetter->setData ("It is your turn.");
  //mpCurrentBetter->setVisible (true);

  mpCards[stoll(index)]->setData (hand);

}

//***************************************************************************
// Function:		V_EndTurn
//
// Description: Sets the end turn in the view
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void BlackJackView_TextUI::V_EndTurn ()
{
  mpCurrentBetter->setVisible (false);
  mpcBlackJackPresenter->P_StartTurn ();
}

//***************************************************************************
// Function:		V_EndPlayersTurn
//
// Description: Sets the end of players turn in the view
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void BlackJackView_TextUI::V_EndPlayersTurn ()
{
  onRunCPUCommands ();
}

//***************************************************************************
// Function:		redrawUI
//
// Description: Calls draw
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************
void BlackJackView_TextUI::redrawUI ()
{
  drawScreen ();
}