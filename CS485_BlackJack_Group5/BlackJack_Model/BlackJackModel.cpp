//*******************************************************************
// File name:  BlackJackModel.cpp
// Author:     Michael Sakai / Josh Napoles
// Date:	     05/01/17
// Class:      CS485
// Assignment: 05_Group
// Purpose:    impliment the BlackJackModel
//*******************************************************************
#include "BlackJackModel.h"
#include <iterator>


//***************************************************************************
// Function:    M_SetNumHuman
//
// Description:	
//
// Parameters:  
//
// Returned:    
//***************************************************************************
bool BlackJackModel::M_SetNumHuman (int numHuman, int &prevValue)
{
	bool bValidHuman = true;

	if (numHuman + mNumCPU > MAX_PLAYERS || numHuman + mNumCPU < 1)
	{
		bValidHuman = false;
		prevValue = mNumHuman;
	}
	else
	{
		mNumHuman = numHuman;
	}
	mTotalPlayers = mNumCPU + mNumHuman;
	
	return bValidHuman;
}

//***************************************************************************
// Function:    M_SetNumCPU
//
// Description:	
//
// Parameters:  
//
// Returned:    
//***************************************************************************
bool BlackJackModel::M_SetNumCPU (int numCPU, int &prevValue)
{
	bool bValidCPU = true;
	if (numCPU + mNumHuman > MAX_PLAYERS || mNumHuman + numCPU < 1)
	{
		bValidCPU = false;
		prevValue = mNumCPU;
	}
	else
	{
		mNumCPU = numCPU;
	}

	mTotalPlayers = mNumCPU + mNumHuman;

	return bValidCPU;
}

//***************************************************************************
// Function:    M_SetNumDeck
//
// Description:	
//
// Parameters:  
//
// Returned:    
//***************************************************************************
bool BlackJackModel::BlackJackModel::M_SetNumDeck (int numDeck, int &prevValue)
{
	bool bValidDeckSize = false;

	if (numDeck <= mcTheDeck.MAX_NUM_DECKS)
	{
		bValidDeckSize = true;
		
		mNumberOfDecks = numDeck;
	}
	else
	{
		prevValue = mNumberOfDecks;
	}

	return bValidDeckSize;
}

//***************************************************************************
// Function:    M_SetBet
//
// Description:	
//
// Parameters:  
//
// Returned:    
//***************************************************************************
bool BlackJackModel::M_SetBet (int playerID, long long amount)
{
	bool bValidBet = false;
	Money cBet (amount, Currency ());
	
	if (cBet < mcaPlayer.at (mPlayersTurn).getBankRoll() || cBet == mcaPlayer.at(mPlayersTurn).getBankRoll())
	{
		bValidBet = true;
		mcaPlayer.at(mPlayersTurn).makeBet(cBet);
	}

	
	return bValidBet;
}

//***************************************************************************
// Function:    M_InitializePlayers
//
// Description: will be called after number of total player is decided 
//							sets default player names and bank according to the number
//							of human players and CPUs
//
// Parameters:  defaultName	- vector wih all the names sent to the builder
//
// Returned:    none
//***************************************************************************
void BlackJackModel::M_InitializePlayers (std::vector <std::string> defaultNames, long long defaultBank, std::string defaultStrategy)
{
	for (int i = 0; i < mNumHuman; i++)
	{
		mcaPlayerBuilder.push_back (PlayerBuilder ());

		mcaPlayerBuilder.at(i).buildName (defaultNames.at (i));
		mcaPlayerBuilder.at(i).buildBank (Money (defaultBank, Currency () ));
	}
	for (int j = 0; j < mNumCPU; j++)
	{
		mcaCPUBuilder.push_back (CPUBuilder ());
		mcaCPUBuilder.at(j).buildName (defaultNames.at (mNumHuman + j));
		mcaCPUBuilder.at (j).buildBank(Money (defaultBank, Currency ()));
		mcaCPUBuilder.at(j).buildStrategy (defaultStrategy);
	}
}

//***************************************************************************
// Function:    M_SetPlayerName
//
// Description:	
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void BlackJackModel::M_SetPlayerName (int thePlayer, std::string theName)
{
	if (thePlayer < mNumHuman)
	{
		mcaPlayerBuilder.at(thePlayer).buildName(theName);
	}
	else
	{
		mcaCPUBuilder.at(thePlayer - mNumHuman).buildName(theName);
	}
}

//***************************************************************************
// Function:    M_SetCPUStrat
//
// Description:	
//
// Parameters:  
//
// Returned:    
//***************************************************************************
bool BlackJackModel::M_SetCPUStrat (int playerID, std::string theStrat, std::string &previousStrategy)
{
	previousStrategy = mcaCPUBuilder.at (playerID).getStrategy ();

	return mcaCPUBuilder.at(playerID).buildStrategy(theStrat);
}

//***************************************************************************
// Function:    M_SetBank
//
// Description:	
//
// Parameters:  
//
// Returned:    
//***************************************************************************
bool BlackJackModel::M_SetBank (int thePlayer, long long amount, std::string &prevValue)
{
	bool bValidInput = false;
	if (amount > 0)
	{
		bValidInput = true;
		if (thePlayer < mNumHuman)
		{
			mcaPlayerBuilder.at(thePlayer).buildBank (Money(amount * 100, Currency()));
			prevValue = mcaPlayerBuilder.at(thePlayer).getBank ();
		}
		else
		{
			mcaCPUBuilder.at(thePlayer - mNumHuman).buildBank(Money(amount * 100, Currency()));
			prevValue = mcaPlayerBuilder.at (thePlayer).getBank ();
		}
	}
	else if (thePlayer < mNumHuman)
	{
		prevValue = mcaPlayerBuilder.at(thePlayer).getBank ();
	}
	else
	{
		prevValue = mcaCPUBuilder.at(thePlayer - mNumHuman).getBank();
	}

	return bValidInput;
}

//***************************************************************************
// Function:    M_StartGame
//
// Description:	
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void BlackJackModel::M_StartGame ()
{
	// put the human players in the player vector
	for (int i = 0; i < mNumHuman; i++)
	{
		mcaPlayer.push_back (mcaPlayerBuilder.at (i).createPlayer ());
	}
	// put the cpu players in the cpu vector
	for (int i = 0; i < mNumCPU; i++)
	{
    mcaCPUBuilder.at (i).buildDeck (&mcTheDeck);
		mcaCPU.push_back (mcaCPUBuilder.at (i).createPlayer ());
	}
	// build a dealer
	mcaCPUBuilder.push_back (CPUBuilder ());
	mcaCPUBuilder.at(mNumCPU).buildName ("Dealer");
	mcaCPUBuilder.at(mNumCPU).buildStrategy ("True Dealer");
	mcaCPUBuilder.at(mNumCPU).buildDeck (&mcTheDeck);

	// push the dealer to the vector
	mcaCPU.push_back (mcaCPUBuilder.at (mNumCPU).createPlayer ());
	mNumCPU++;
	mTotalPlayers = mNumCPU + mNumHuman;

	// build the deck and shuffle/stack
	mcTheDeck.buildNewDeck(mNumberOfDecks);
	mcTheDeck.shuffle ();
	//mcTheDeck.stackDeckTest1 ();
	//mcTheDeck.stackDeckTest2 ();
	//mcTheDeck.stackDeckTest2 ();
}

//***************************************************************************
// Function:    M_Hit
//
// Description:	
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void BlackJackModel::M_Hit (bool &bCPUTurn, bool &bBlackJack, bool &bBust, std::string &HandRepresentation, std::string &cardRepresentation)
{
	bCPUTurn = false;
	bBust = false;
	bBlackJack = false;
	stringstream ss;

	Card hitCard = mcTheDeck.drawCard ();


	ss << hitCard;
	cardRepresentation = ss.str();

	//HandRepresentation = to_string (mPlayersTurn);

	//Checks for bust and blackjack inside here
		mcaPlayer.at(mPlayersTurn).hitHand (hitCard, bBlackJack, bBust);

	//Returns a string with hand information/player id
	HandRepresentation = to_string(mPlayersTurn);
	HandRepresentation.append (" ");
	HandRepresentation.append (mcaPlayer.at(mPlayersTurn).printHand ());

	if (bBust || bBlackJack)
	{
		incrementPlayerTurn();
	}

	//check for cpu turn
	if (mPlayersTurn >= mNumHuman)
	{
		bCPUTurn = true;
	}
}

//***************************************************************************
// Function:    M_Stay
//
// Description:	Execute stay for the player. Checks if all the human players 
//				played their turn 
//
// Parameters:  bCPUTurn - determines if it is the CPU's turn or not
//
// Returned:    none
//***************************************************************************
void BlackJackModel::M_Stay (bool &bCPUTurn)
{
	bCPUTurn = false;
	bool bEndTurn = false;
	mcaPlayer.at(mPlayersTurn).stand(bEndTurn);

  if (bEndTurn)
  {
    incrementPlayerTurn ();
  }
	
	//check for cpu turn
	if (mPlayersTurn >= mNumHuman)
	{
		bCPUTurn = true;
	}
}

//***************************************************************************
// Function:    M_Split
//
// Description:	Splits the player's hand. Return false if hand cannot be split
//
// Parameters:  none
//
// Returned:    true if hand can split
//***************************************************************************
bool BlackJackModel::M_Split ()
{
	bool bSplit = false;

	if (mcaPlayer.at(mPlayersTurn).canSplit())
	{
		mcaPlayer.at(mPlayersTurn).split(mcTheDeck.drawCard(), mcTheDeck.drawCard());
	}

	return bSplit;
}

//***************************************************************************
// Function:    M_CPUTurn
//
// Description:	
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void BlackJackModel::M_CPUTurn(bool &bPlayerTurn, std::string &rCommand, bool &bBlackJack, bool &bBust, std::string &rHand)
{
	bPlayerTurn = true;

	mcaCPU.at(mCPUTurn)->startTurn(bBlackJack);
	mcaCPU.at(mCPUTurn)->makeMove(rCommand, bBlackJack, bBust, rHand);

  
	rHand = to_string(mNumHuman + mCPUTurn);
	rHand += " ";
	rHand += mcaCPU.at(mCPUTurn)->printHand();

	incrementCPUTurn();

	if (mCPUTurn < mNumCPU)
	{
		bPlayerTurn = false;
	}

}

//***************************************************************************
// Function:    M_StartRound
//
// Description:	
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void BlackJackModel::M_StartRound (std::vector<std::string> &cardRepresentation)
{
	Card Temp;

	for (int i = 0; i < mNumHuman; i++)
	{
		Temp = mcTheDeck.drawCard();
		mcaPlayer.at(i).hitHand(Temp);

		Temp = mcTheDeck.drawCard();
		Temp.flipDown ();
		mcaPlayer.at(i).hitHand(Temp);

		cardRepresentation.push_back (mcaPlayer.at(i).printHand ());
	}

	for (int i = 0; i < mNumCPU; i++)
	{
		Temp = mcTheDeck.drawCard();
		mcaCPU.at(i)->hitHand(Temp);

		Temp = mcTheDeck.drawCard();
		Temp.flipDown();
		mcaCPU.at(i)->hitHand(Temp);
		cardRepresentation.push_back(mcaCPU.at(i)->printHand());
	}

	mPlayersTurn = 0;
  auto it = mcaCPU.cend () - 1;
  mcTheDeck.setDealersUpCardValue ((*it)->getCard (0).getCardValue ());
}

//***************************************************************************
// Function:    M_StartTurn
//
// Description:	
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void BlackJackModel::M_StartTurn (std::string &cardRepresentation, bool &bBlackJack)
{
	bBlackJack = false;


	mcaPlayer.at (mPlayersTurn).startTurn (bBlackJack);

  cardRepresentation = to_string (mPlayersTurn);
  cardRepresentation += " ";
  cardRepresentation += mcaPlayer.at (mPlayersTurn).printHand ();

	if (bBlackJack)
	{
		incrementPlayerTurn();
	}
}

//***************************************************************************
// Function:    M_EndRound
//
// Description:	
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void BlackJackModel::M_EndRound (std::vector<std::string> &bankBalance, std::vector <int> &bankruptPlayerID, std::vector <int> &bankruptCPUID)
{
	mPlayersTurn = 0;
	mCPUTurn = 0;

	compareAgainstDealer ();

	if ((int)mcTheDeck.getNumCardsInDeck() <= mTotalPlayers * 10)
	{
		mcTheDeck.resetDeck ();
	}

	for (int i = 0; i < mNumHuman; i++)
	{
		mcaPlayer.at(i).resetHand ();
		if (mcaPlayer.at(i).checkIfBankrupt ())
		{
			bankruptPlayerID.push_back(i);
			mcaPlayer.erase (mcaPlayer.begin() + i);
			mNumHuman--;
		}
	}

	for (int i = 0; i < mNumCPU - 1; i++)
	{
		mcaCPU.at(i)->resetHand();
		if (mcaCPU.at(i)->checkIfBankrupt())
		{
			bankruptCPUID.push_back(i);
			mcaCPU.erase(mcaCPU.begin() + i);
			mNumCPU--;
		}
	}

  //reset the dealer
  mcaCPU.at (mNumCPU - 1)->resetHand ();


	mTotalPlayers = mNumHuman + mNumCPU;

	for (int i = 0; i < mNumHuman; i++)
	{
		bankBalance.push_back (mcaPlayer.at(i).printBankBalance ());
	}
	for (int i = 0; i < mNumCPU; i++)
	{
		bankBalance.push_back(mcaCPU.at(i)->printBankBalance());
	}

	for (int i = 0; i < mNumCPU; i++)
	{
		bankBalance.push_back(mcaCPU.at(i)->printBankBalance());
	}

	//reset cpu "normal" hand

	bCPUMadeBet = false;

}

//***************************************************************************
// Function:    M_RestartRound
//
// Description:	
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void BlackJackModel::M_RestartRound (int &numPlayer)
{

}

//***************************************************************************
// Function:    M_Quit
//
// Description:	
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void BlackJackModel::M_Quit ()
{

}

//***************************************************************************
// Function:    M_Bet
//
// Description:	Validates the given bet. If valid, the bet will be used. If not,
//							bValidInput will return false and the bet will not be used.
//
// Parameters:  bet - the amount of bet inputted
//
// Returned:    bValidInput - true if bet is valid
//***************************************************************************
bool BlackJackModel::M_Bet (long long bet, std::string &moneyBet)
{
	bool bValidInput = false; 


  if (mPlayersTurn < mNumHuman)
	{
		bValidInput = mcaPlayer.at(mPlayersTurn).makeBet (Money(bet * 100, Currency()));

		if (bValidInput)
		{
			moneyBet = mcaPlayer.at (mPlayersTurn).getBetString();
			incrementPlayerTurn();
		}
		if (!bCPUMadeBet)
		{
			bCPUMadeBet = true;

			for (int i = 0; i < mNumCPU; i++)
			{
				mcaCPU.at(i)->makeBet();
			}
		}
	}

	return bValidInput;
}

//***************************************************************************
// Function:    M_resetTable
//
// Description:	
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void BlackJackModel::resetTable ()
{

}

//***************************************************************************
// Function:    M_takeCPUTurn
//
// Description:	
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void BlackJackModel::takeCPUTurn ()
{

}

//***************************************************************************
// Function:    M_compareAgaistDealer
//
// Description:	
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void BlackJackModel::compareAgainstDealer ()
{
	for (int i = 0; i < mNumHuman; i++)
	{
		if (mcaPlayer.at(i).hasSplit())
		{
			if (mcaPlayer.at(i).isBlackJack())
			{
				mcaPlayer.at(i).winBlackJackBet();
			}
			else if (mcaCPU.at(mNumCPU - 1)->getHandValue () >= mcaPlayer.at(i).getHandValue () && mcaCPU.at(mNumCPU - 1)->getHandValue () <= 21)
			{
				mcaPlayer.at(i).loseBet();
			}
			else if (mcaCPU.at(mNumCPU - 1)->getHandValue () < mcaPlayer.at(i).getHandValue () && mcaPlayer.at(i).getHandValue () < 21)
			{
				mcaPlayer.at(i).winBet();
			}

			mcaPlayer.at(i).resetSplitHand ();

			if (mcaPlayer.at(i).isBlackJack())
			{
				mcaPlayer.at(i).winBlackJackBet();
			}
			else if (mcaCPU.at(mNumCPU - 1)->getHandValue () >= mcaPlayer.at(i).getHandValue () && mcaCPU.at(mNumCPU - 1)->getHandValue () <= 21)
			{
				mcaPlayer.at(i).loseBet();
			}
			else if (mcaCPU.at(mNumCPU - 1)->getHandValue () < mcaPlayer.at(i).getHandValue () && mcaPlayer.at(i).getHandValue () < 21)
			{
				mcaPlayer.at(i).winBet();
			}
		}
		else
		{
			if (mcaPlayer.at(i).isBlackJack())
			{
				mcaPlayer.at(i).winBlackJackBet();
			}
			else if (mcaCPU.at(mNumCPU - 1)->getHandValue () >= mcaPlayer.at(i).getHandValue () && mcaCPU.at(mNumCPU - 1)->getHandValue () <= 21)
			{
				mcaPlayer.at(i).loseBet();
			}
			else if (mcaCPU.at(mNumCPU - 1)->getHandValue () < mcaPlayer.at(i).getHandValue () && mcaPlayer.at(i).getHandValue () < 21)
			{
				mcaPlayer.at(i).winBet();
			}
		}
	}

	for (int i = 0; i < (mNumCPU - 1); i++)
	{
		if (mcaCPU.at(i)->hasSplit())
		{
			if (mcaCPU.at(i)->isBlackJack())
			{
				mcaCPU.at(i)->winBlackJackBet();
			}
			else if (mcaCPU.at(mNumCPU - 1)->getHandValue () >= mcaCPU.at(i)->getHandValue () && mcaCPU.at(mNumCPU - 1)->getHandValue() <= 21)
			{
				mcaCPU.at(i)->loseBet();
			}
			else if (mcaCPU.at(mNumCPU - 1)->getHandValue () < mcaCPU.at(i)->getHandValue () && mcaCPU.at(i)->getHandValue() < 21)
			{
				mcaCPU.at(i)->winBet();
			}

			mcaCPU.at(i)->resetSplitHand();

			if (mcaCPU.at(i)->isBlackJack())
			{
				mcaCPU.at(i)->winBlackJackBet();
			}
			else if (mcaCPU.at(mNumCPU - 1)->getHandValue () >= mcaCPU.at(i)->getHandValue () && mcaCPU.at(mNumCPU - 1)->getHandValue () <= 21)
			{
				mcaCPU.at(i)->loseBet();
			}
			else if (mcaCPU.at(mNumCPU - 1)->getHandValue () < mcaCPU.at(i)->getHandValue () && mcaCPU.at(i)->getHandValue () < 21)
			{
				mcaCPU.at(i)->winBet();
			}
		}
		else
		{
			if (mcaCPU.at(i)->isBlackJack())
			{
				mcaCPU.at(i)->winBlackJackBet();
			}
			else if (mcaCPU.at(mNumCPU - 1)->getHandValue () >= mcaCPU.at(i)->getHandValue () && 
        mcaCPU.at(mNumCPU - 1)->getHandValue () <= 21) // BREAKS
			{
				mcaCPU.at(i)->loseBet();
			}
			else if (mcaCPU.at(mNumCPU - 1)->getHandValue () < 
        mcaCPU.at(i)->getHandValue () && mcaCPU.at(i)->getHandValue () < 21)
			{
				mcaCPU.at(i)->winBet();
			}
		}
	}
}

//***************************************************************************
// Function:    M_incrementPlayerTurn
//
// Description:	increments the mPlayersTurn; sets to 0 if > mNumHuman
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************
void BlackJackModel::incrementPlayerTurn ()
{
	if (mPlayersTurn < mNumHuman)
	{
		mPlayersTurn++;
	}
	else if (mPlayersTurn >= mNumHuman)
	{
		mPlayersTurn = 0;
	}
}

//***************************************************************************
// Function:    M_incrementCPUTurn
//
// Description:	increments the mCPUTurn; sets to 0 if > mNumCPU
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************
void BlackJackModel::incrementCPUTurn()
{
	if (mCPUTurn < mNumCPU)
	{
		mCPUTurn++;
	}
	else if (mCPUTurn >= mNumCPU)
	{
		mCPUTurn = 0;
	}
}

//***************************************************************************
// Function:    M_GetPlayerIndex
//
// Description:	returns the index of the Player according to the name
//
// Parameters:  name	- use the name to get a playerID
//
// Returned:    theID	- the playerID
//***************************************************************************
int BlackJackModel::M_GetPlayerIndex (std::string name)
{
	int theID = -1;
	for (int i = 0; i < mTotalPlayers; i++)
	{
		if (i < mNumHuman)
		{
			if (mcaPlayerBuilder.at(i).getName() == name)
			{
				theID = i;
			}
		}
		else
		{
			if (mcaCPUBuilder.at(i - mNumHuman).getName() == name)
			{
				theID = i - mNumHuman;
			}
		}

	}

	return theID;
}
