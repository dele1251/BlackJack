//*****************************************************************************
// File name:  CoutnerStrategy.cpp
// Author:     Ernesto DeLeon
// Date:	     05/4/17
// Class:      CS485
// Assignment: BlackJack
// Purpose:    Implementation of a CPU card counting strategy
//*****************************************************************************
#include "CounterStrategy.h"

//*****************************************************************************
// Constructor: CounterStrategy
//
// Description: Sets the player pointer, deck pointer streams in the table for
//              card counting plays
//
// Parameters:  pcPlayer  - a pointer to a player
//              pcDeck    - a pointer to the deck
//
// Returned:    none
//*****************************************************************************
CounterStrategy::CounterStrategy (Player* pcPlayer, BlackJackDeck* pcDeck) : 
	NormalStrategy (pcPlayer, pcDeck)
{
	int index;
	std::string play = "";
	mInFile.open ("DecisionTable.txt");
	if (mInFile.fail ())
	{
		std::cout << "file error" << std::endl;
	}

	mInFile >> play >> index;
 
	while (!mInFile.eof ())
	{
		mTable[play] = index;
		mInFile >> play >> index;
	}
	mInFile.close ();
  mcBet = mpcPlayer->getBankRoll () * .1;
}

//*****************************************************************************
// Destructor:  ~CounterStrategy
//
// Description: destructor for the strategy
//
// Parameters:  none
//
// Returned:    none
//*****************************************************************************
CounterStrategy::~CounterStrategy ()
{
}

//*****************************************************************************
// Method:      executeTurn
//
// Description: makes plays based on illustrious 18 table if exists otherwise
//              the normal strategy plays are implemented
//
// Parameters:  none
//
// Returned:    none
//*****************************************************************************
void CounterStrategy::executeTurn (std::string &rCommand, bool &bBlackJack,
  bool &bBust, std::string &rHand)
{
	bool bEndTurn;
	mDealersUpCardValue = mpcDeck->getDealerCardValue();
	Card cardOne = mpcPlayer->getCard(FIRST_CARD);
	Card cardTwo = mpcPlayer->getCard(SECOND_CARD);
	std::string playCard1 = to_string(cardOne.getCardValue());
	std::string playCard2 = to_string(cardTwo.getCardValue());
	std::string play = to_string(cardOne.getCardValue()) +
		to_string(cardTwo.getCardValue());

	int index;
	char decision = 'N';
  int trueCount;

  double numDecks = (static_cast<int> (mpcDeck->getNumCardsInDeck ()) / 52);
  if (1 > numDecks)
  {
    numDecks = 1;
  }
  
  if (0 != mpcDeck->getRunningCount () && 0 != mpcDeck->getNumCardsInDeck ())
  {
    
    trueCount = mpcDeck->getRunningCount () / static_cast<int> (numDecks);
      
  }
  
	std::string key;

	if ("11" == playCard1 || "11" == playCard2)
	{
		key = playCard1 + playCard2 + "V" + std::to_string (mDealersUpCardValue);
	}
	else if ("10" == playCard1 && "10" == playCard2)
	{
		key = playCard1 + playCard2 + "V" + std::to_string (mDealersUpCardValue);
	}
	else
	{
		key = std::to_string (mpcPlayer->getHandValue ()) + "V" + 
      std::to_string (mDealersUpCardValue);
	}

	// see if the current hand is in the illustrious 18
	auto it = mTable.find (key);

	// if the hand if not in the map then play a normal strategy for this hand
	if (it != mTable.end ())
	{
		index = (it)->second;

		// find the splitting decision from the standard strategy
		for (auto it : mPairSplittingTable)
		{
			if ((playCard1 + playCard2) == it.first)
			{
				decision = it.second[mDealersUpCardValue];
			}
		}

		// if true count meets or exceeds indicies stand/split
		if (trueCount >= index && 'Y' == decision)
		{
			playPairHand ();
		}
		else if (trueCount >= index)
		{
			mpcPlayer->stand (bEndTurn); //stays     
		}

		// if the index is less than the true count then play a hard hand from the
		// normal strategy
		else
		{
			playHardHand (HAND_ONE);
			mpcPlayer->hitHand (mpcDeck->drawCard (), bBlackJack, bBust);
		}
	}

	// any case not covered by the illustrious 18 gets played as a normal 
	// strategy
	else
	{
		NormalStrategy::executeTurn (rCommand, bBlackJack, bBust, rHand);
	}

}

//*****************************************************************************
// Method:      executeBet
//
// Description: previous bet is adjusted based on the true count of the deck
//              a card counting trick
//
// Parameters:  none
//
// Returned:    none
//*****************************************************************************
void CounterStrategy::executeBet ()
{
	double betModifier = 1;

  int trueCount = 0;

  double numDecks = (static_cast<int> (mpcDeck->getNumCardsInDeck ()) / 52);

  if (1 > numDecks)
  {
    numDecks = 1;
  }

  if (0 != mpcDeck->getRunningCount () && 0 != mpcDeck->getNumCardsInDeck ())
  {

    trueCount = mpcDeck->getRunningCount () / static_cast<int> (numDecks);

  }

	//gives a modifier as a relation of the true count
	if (0 != trueCount)
	{
		betModifier = 1 / trueCount;
	}
	
	// if the modifier is positive increase the bet from the last bet
	if (0 < betModifier && 1 > betModifier)
	{
		mcBet = mcBet * (1 + std::abs (betModifier));
	}
	// if the modifier is negative decrease the bet from the last bet
	else if (0 > betModifier && -1 < betModifier)
	{
		mcBet = mcBet * (1 - std::abs (betModifier));
	}
  
	mpcPlayer->makeBet (mcBet);
}