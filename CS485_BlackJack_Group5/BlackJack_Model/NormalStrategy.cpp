//*****************************************************************************
// File name:  NormalStrategy.cpp
// Author:     Ernesto DeLeon
// Date:	     05/4/17
// Class:      CS485
// Assignment: BlackJack
// Purpose:    Implementation of a CPU normal strategy
//*****************************************************************************
#include "NormalStrategy.h"
#include <iterator>

//*****************************************************************************
// Constructor: NormalStrategy
//
// Description: Sets the player pointer, deck pointer strams in tables for 
//              the standard BJ play strategy
//
// Parameters:  pcPlayer  - a pointer to a player
//              pcDeck    - a pointer to the deck
//
// Returned:    none
//*****************************************************************************
NormalStrategy::NormalStrategy (Player* pcPlayer, BlackJackDeck* pcDeck) :
	mpcPlayer (pcPlayer), mpcDeck (pcDeck)
{
	double tenPercent = 0.1;
	mcBet = mpcPlayer->getBankRoll () * tenPercent;
	std::string play = "";
	std::vector<char> decision;
	int numStuff;
	char temp;
	mpcPlayer->resetSplitHand ();

	decision.push_back ('\0');
	decision.push_back ('\0');

	mInFile.open ("BasicStrategy.txt");
	if (mInFile.fail ())
	{
		std::cout << "file error" << std::endl;
	}
	mInFile >> numStuff;
	for (int i = 0; i < numStuff; ++i)
	{
		mInFile >> play;
		for (int i = 2; i < NUM_PLAYS; ++i)
		{
			mInFile >> temp;
			decision.push_back (temp);
		}
		mPairSplittingTable.push_back (std::make_pair (play, decision));
		decision.erase (decision.begin (), decision.end ());
		decision.push_back ('\0');
		decision.push_back ('\0');
	}

	decision.erase (decision.begin (), decision.end ());
	decision.push_back ('\0');
	decision.push_back ('\0');

	mInFile >> numStuff;

	for (int i = 0; i < numStuff; ++i)
	{
		mInFile >> play;
		for (int i = 2; i < NUM_PLAYS; ++i)
		{
			mInFile >> temp;
			decision.push_back (temp);
		}
		mSoftDecisions.push_back (std::make_pair (play, decision));
		decision.erase (decision.begin (), decision.end ());
		decision.push_back ('\0');
		decision.push_back ('\0');
	}

	decision.erase (decision.begin (), decision.end ());
	decision.push_back ('\0');
	decision.push_back ('\0');

	mInFile >> numStuff;

	for (int i = 0; i < numStuff; ++i)
	{
		mInFile >> play;
		for (int i = 2; i < NUM_PLAYS; ++i)
		{
			mInFile >> temp;
			decision.push_back (temp);
		}
		mHardDecisions.push_back (std::make_pair (play, decision));
		decision.erase (decision.begin (), decision.end ());
		decision.push_back ('\0');
		decision.push_back ('\0');
	}
	mInFile.close ();
	decision.erase (decision.begin (), decision.end ());
}

//*****************************************************************************
// Destructor:  ~NormalStrategy
//
// Description: destructor that sets the pointers to nullptr
//
// Parameters:  none
//
// Returned:    none
//*****************************************************************************
NormalStrategy::~NormalStrategy ()
{
	mpcPlayer = nullptr;
	mpcDeck = nullptr;
}

//*****************************************************************************
// Method:      executeTurn
//
// Description: makes play based on the standard stragetgy calles play methods
//              based on the type of hand delt
//
// Parameters:  none
//
// Returned:    none
//*****************************************************************************
void NormalStrategy::executeTurn (std::string &rCommand, bool &bBlackJack,
  bool &bBust, std::string &Hand)
{
	mDealersUpCardValue = mpcDeck->getDealerCardValue ();
	Card cardOne = mpcPlayer->getCard(FIRST_CARD);
	Card cardTwo = mpcPlayer->getCard(SECOND_CARD);

	// pair hands
	if (cardOne.getCardValue () == cardTwo.getCardValue ())
	{
		playPairHand ();
	}

	// soft hands
	else if ((cardOne.getCardValue () == 11 && !(cardTwo.getCardValue () == 11)) 
		|| (cardTwo.getCardValue () == 11 && !(cardOne.getCardValue () == 11)))
	{
		playSoftHand (HAND_ONE);
	}

	// for hard hands
	else
	{
		playHardHand (HAND_ONE);
	}
}

//*****************************************************************************
// Method:      executeBet
//
// Description: bets a random percent of the players bank roll
//
// Parameters:  none
//
// Returned:    none
//*****************************************************************************
void NormalStrategy::executeBet ()
{
	double betModifier =  ((rand () % 10) + 2);
	betModifier = 1 / betModifier;
	Money pcTemp = mpcPlayer->getBankRoll ();
	mcBet = pcTemp * betModifier;
	mpcPlayer->makeBet (mcBet);
}

//*****************************************************************************
// Method:      playPairHand
//
// Description: if the player is delt a pair then this method is called to
//              handle the turn
//
// Parameters:  none
//
// Returned:    none
//*****************************************************************************
void NormalStrategy::playPairHand ()
{
	char decision = 'N';

	Card cardOne = mpcPlayer->getCard(FIRST_CARD);
	Card cardTwo = mpcPlayer->getCard(SECOND_CARD);

	std::string play = to_string(cardOne.getCardValue()) + 
										 to_string(cardTwo.getCardValue());

	for (auto it : mPairSplittingTable)
	{
		if (play == it.first)
		{
			decision = it.second[mDealersUpCardValue];
		}
	}

	if ('Y' == decision)
	{
		Card tempCard1 = mpcDeck->drawCard ();
		Card tempCard2 = mpcDeck->drawCard ();
		mpcPlayer->split(tempCard1, tempCard2); // split is called

		if (tempCard1.getCardValue () == 11)
		{
			playSoftHand (HAND_ONE);
		}
		else
		{
			playHardHand (HAND_ONE);
		}

		if (tempCard2.getCardValue () == 11)
		{
			playSoftHand (HAND_TWO);
		}
		else
		{
			playHardHand (HAND_TWO);
		}
	}
	else
	{
		playHardHand (HAND_ONE);
	}
}

//*****************************************************************************
// Method:      playSoftHand
//
// Description: if a player is delt an ace and another card then this method is
//              called to deal with soft hands
//
// Parameters:  whichHand - an integer index for which hand will be played, 
//              a player has more than one hand when a split is called
//
// Returned:    none
//*****************************************************************************
void NormalStrategy::playSoftHand (int whichHand)
{
	bool bEndTurn;
	bool bBlackJack; 
	bool bBust;

	Card cardOne = mpcPlayer->getCard(FIRST_CARD);
	Card cardTwo = mpcPlayer->getCard(SECOND_CARD);

	std::string playCard1 = to_string(cardOne.getCardValue());
	std::string playCard2 = to_string(cardTwo.getCardValue());

	char decision = 'S';

	int originalHandValue = mpcPlayer->getHandValue ();

	//look for first decision
	for (auto it : mSoftDecisions)
	{
		if (("11" + playCard1) == it.first)
		{
			decision = it.second[mDealersUpCardValue];
		}
		else if ((playCard1 + "11") == it.first)
		{
			decision = it.second[mDealersUpCardValue];
		}
	}
	
	// add a card and check for the rest of soft decisions
	while ('H' == decision && *mpcPlayer < STAY_LIMIT)
	{
		decision = '\0'; // Hits hand

		Card tempCard = mpcDeck->drawCard ();

		if (21 > tempCard.getCardValue () + originalHandValue)
		{
			mpcPlayer->hitHand (tempCard, bBlackJack, bBust);
			std::string temp = std::to_string (mpcPlayer->
				getHandValue () - 11);
			for (auto it : mSoftDecisions)
			{
				if (("11" + temp) == it.first)
				{
					decision = it.second[mDealersUpCardValue];
				}
			}
		}

		// if the hand is no longer soft
		else
		{
			mpcPlayer->hitHand (tempCard, bBlackJack, bBust);
			for (auto it : mHardDecisions)
			{
				if (std::to_string  ((mpcPlayer->getHandValue ()))
					== it.first)
				{
					decision = it.second[mDealersUpCardValue];
				}
			}
		}    
	}

	if (STAY_LIMIT <= mpcPlayer->getHandValue () && 'H' == decision)
	{
		mpcPlayer->hitHand (mpcDeck->drawCard (), bBlackJack, bBust);
	}
	else if (17 > mpcPlayer->getHandValue () && 'H' == decision)
	{
		mpcPlayer->hitHand (mpcDeck->drawCard (), bBlackJack, bBust);

		std::string temp = std::to_string (mpcPlayer->getHandValue ());

		for (auto it : mHardDecisions)
		{
			if ((temp + std::to_string (mDealersUpCardValue)) == it.first)
			{
				decision = it.second[mDealersUpCardValue];
			}
		}
	}

	mpcPlayer->stand (bEndTurn);
}

//*****************************************************************************
// Method:      playHardHand
//
// Description: this method is called when a player has no aces and no doubles
//              at the deal stage of play
//
// Parameters:  whichHand - an integer index for which hand will be played, 
//              a player has more than one hand when a split is called
//
// Returned:    none
//*****************************************************************************
void NormalStrategy::playHardHand (int whichHand)
{
	bool bEndTurn;
	bool bBlackJack;
	bool bBust = false;

	Card cardOne = mpcPlayer->getCard(FIRST_CARD);
	Card cardTwo = mpcPlayer->getCard(SECOND_CARD);
	char decision = 'S';

	// get First Decision
	for (auto it : mHardDecisions)
	{
		if (std::to_string (mpcPlayer->getHandValue ()) == it.first)
		{
			decision = it.second[mDealersUpCardValue];
		}
	}


	// while the decision is to hit do this
	while ('H' == decision && STAY_LIMIT > mpcPlayer->getHandValue ())
	{
		decision = '\0';

		mpcPlayer->hitHand (mpcDeck->drawCard (), bBlackJack, bBust);

		std::string temp = std::to_string (mpcPlayer->getHandValue ());

		for (auto it : mHardDecisions)
		{
			if (std::to_string (mpcPlayer->getHandValue ()) == it.first)
			{
				decision = it.second[mDealersUpCardValue];
			}
			else
			{
				decision = 'S';
			}
		}
	}

	if (!bBust) // check if you need to stand if black jack is true as well
	{
		mpcPlayer->stand(bEndTurn);
	}
}