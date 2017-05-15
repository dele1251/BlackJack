//***************************************************************************
// File name:  Player.cpp
// Author:     Josh Napoles
// Date:	     04/27/17
// Class:      CS485
// Assignment: Group 5 Final Project
// Purpose:    Impliment the class Player
//***************************************************************************
#include "Player.h"

//***************************************************************************
// Constructor: Player
//
// Description: Constructor for Player
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************
Player::Player()
{

}

//***************************************************************************
// Constructor: Player
//
// Description: Constructor for Player
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************
Player::Player(std::string name, Money cMoney)
{
	mName = name; 
	mcBank = cMoney;
}

//***************************************************************************
// Destructor: Money
//
// Description: Destructor for Player
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************
Player::~Player()
{
	
}

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
Player & Player::operator= (const Player &rcPlayer)
{
	mName = rcPlayer.mName;
	for (int i = 0; i < 2; i++)
	{
		mcHand[i] = rcPlayer.mcHand[i];
	}
	mcBank = rcPlayer.mcBank;
	mcCurrentBet = rcPlayer.mcCurrentBet;
	mBankrupt = rcPlayer.mBankrupt;

	return *this;
}

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void Player::startTurn(bool &bBlackJack)
{
	bool bFlipUp = true;
	mcHand[mCurrentHand].startTurn ();
	bBlackJack = mcHand[mCurrentHand].isBlackJack();
}

//***************************************************************************
// Function:		makeBet
//
// Description: sets CurrentBet
//
// Parameters:  theBet	- the current bet
//
// Returned:    none
//***************************************************************************
bool Player::makeBet (Money &theBet)
{
	bool bValidBet = true;

	if (theBet > mcBank || theBet < Money(1, Currency()))
	{
		bValidBet = false;
	}
	else
	{
		mcCurrentBet = theBet;
	}

	return bValidBet;
}

//***************************************************************************
// Function:		loseBet
//
// Description: when the player loses, the bet is subtracted from their bank
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************
void Player::loseBet ()
{
	mcBank = mcBank - mcCurrentBet;
	checkIfBankrupt ();
}

//***************************************************************************
// Function:		winBet
//
// Description: when the player wins, the bet is added from their bank
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************
void Player::winBet ()
{
	mcBank = mcBank + mcCurrentBet;
}

//***************************************************************************
// Function:		hitHand
//
// Description:	gives a card to the hand
//
// Parameters:  cCard			- the card added to the hand
//							whichHand - the hand that gets the card
//
// Returned:    none
//***************************************************************************
void Player::hitHand (Card cCard, int whichHand)
{
	mcHand [whichHand].addCard (cCard);
}

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void Player::hitHand(Card cCard)
{
	mcHand[mCurrentHand].addCard(cCard);
}

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void Player::hitHand (Card cCard, bool &bBlackJack, bool &bBust)
{
	mcHand[mCurrentHand].addCard (cCard);

	bBlackJack = false;
	bBust = false;

	if (mcHand[mCurrentHand].isBust ())
	{
		if (hasSplit ())
		{
			incrementPlayerHand ();
		}
		else
		{
			resetSplitHand();
			bBust = true;
		}
	}
	else if (mcHand[mCurrentHand].isBlackJack ())
	{
		if (hasSplit ())
		{
			incrementPlayerHand();
		}
		else
		{
			resetSplitHand();
			bBlackJack = true;
		}
	}

}

//***************************************************************************
// Function:		??
//
// Description:	??????
//
// Parameters:  ???????
//
// Returned:    ??????
//***************************************************************************
void Player::stand (bool &bEndTurn)
{
		if (hasSplit())
		{
			incrementPlayerHand();
		}
		else
		{
			resetSplitHand();
			bEndTurn = true;
		}
}

//***************************************************************************
// Function:		split
//
// Description:	splits the hand into two hands
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************
void Player::split (Card cCard1, Card cCard2)
{
	if (canSplit())
	{
		mcHand[0].splitHand(mcHand[1]);
		mcHand[0].addCard(cCard1);
		mcHand[1].addCard(cCard2);
		mbSplitHand = true;
	}
}

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
bool Player::canSplit()
{
	bool bSplitHand = false;

	if (mcHand[0].canSplit())
	{
		bSplitHand = true;
	}

	return bSplitHand;
}

//***************************************************************************
// Function:		getBet
//
// Description: returns the CurrentBet
//
// Parameters:  none
//
// Returned:    mcCurrentBet	- the current bet
//***************************************************************************
Money Player::getBet ()
{
	return mcCurrentBet;
}

//***************************************************************************
// Function:		checkIfBankrupt
//
// Description: checks to see if the player has enoug Money to play
//
// Parameters:  none
//
// Returned:    bool	- true if the player is bankrupt; false otherwise
//***************************************************************************
bool Player::checkIfBankrupt ()
{
	mBankrupt = false;
	long long oneDollar = 100;
	Money cMinimum (oneDollar, Currency ()); // will probably change

	if (cMinimum > mcBank)
	{
		mBankrupt = true;
	}

	return mBankrupt;
}

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
std::string Player::getName ()
{
	return mName;
}

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
int Player::getCurrentHand ()
{
	return mCurrentHand;
}

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void Player::incrementPlayerHand ()
{
	mCurrentHand++;
	mbSplitHand = false;
}

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
bool Player::hasSplit ()
{
	return mbSplitHand;
}

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void Player::winBlackJackBet ()
{
	mcBank = mcBank + (mcCurrentBet * 1.5);
}

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void Player::resetHand()
{
	mcHand[0].clearHand();
	mcHand[1].clearHand();

	resetSplitHand ();
}

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
bool Player::isBlackJack()
{
	return mcHand[mCurrentHand].isBlackJack();
}

//***************************************************************************
// Function:		resetSplitHand
//
// Description: resets the number of player hands to 1
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************
void Player::resetSplitHand ()
{
	mCurrentHand = 0;
	mbSplitHand = false;
}

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
Player Player::operator+(Money &rcRight)
{
	mcBank + rcRight;
	return *this;
}

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
Player Player::operator-(Money &rcRight)
{
	mcBank - rcRight;
	return *this;
}

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
bool Player::operator<(int right) const
{
	return mcHand[mCurrentHand] < right;
}

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
bool Player::operator>(int right) const
{
	return mcHand[mCurrentHand] > right;
}

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
bool Player::operator==(int right) const
{
	return mcHand[mCurrentHand] == right;
}

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
bool Player::operator<=(int right) const
{
	return mcHand[mCurrentHand] <= right;
}

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
bool Player::operator>=(int right) const
{
	return mcHand[mCurrentHand] >= right;
}

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
 bool operator< (const Player &rcLeft, const Player &rcRight)

{
	return rcLeft.mcHand[rcLeft.mCurrentHand] < rcRight.mcHand[rcRight.mCurrentHand];
}

 //***************************************************************************
 // Function:		
 //
 // Description: 
 //
 // Parameters:  
 //
 // Returned:    
 //***************************************************************************
bool operator> (const Player &rcLeft, const Player &rcRight)

{
	return rcLeft.mcHand[rcLeft.mCurrentHand] > rcRight.mcHand[rcRight.mCurrentHand];
}

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
bool operator== (const Player &rcLeft, const Player &rcRight)

{
	return rcLeft.mcHand[rcLeft.mCurrentHand] == rcRight.mcHand[rcRight.mCurrentHand];
}

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
bool operator<=(const Player &rcLeft, const Player &rcRight)

{
	return rcLeft.mcHand[rcLeft.mCurrentHand] <= rcRight.mcHand[rcRight.mCurrentHand];
}

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
bool operator>= (const Player &rcLeft, const Player &rcRight)

{
	return rcLeft.mcHand[rcLeft.mCurrentHand] >= rcRight.mcHand[rcRight.mCurrentHand];
}

//***************************************************************************
// Function:		getBankRoll
//
// Description: retruns the amount of money the player has
//
// Parameters:  none
//
// Returned:    the amount of money a player has as a Money
//***************************************************************************
Money Player::getBankRoll () const
{
	return mcBank;
}

//***************************************************************************
// Function:		getHandValue
//
// Description: retruns the value of a players hand
//
// Parameters:  handIndex - the index of which hands value must be returned
//
// Returned:    the integer value of the hand
//***************************************************************************
int Player::getHandValue ()
{
	return mcHand[mCurrentHand].calculateHand ();
}

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
std::string Player::printHand()
{
	std::stringstream ss;

	ss << mcHand[mCurrentHand].printHandValue();

	ss << " " << mcHand[mCurrentHand];

	return 	ss.str();
}

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
std::string Player::printHandValue()
{
	return mcHand[mCurrentHand].printHandValue();
}

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
std::string Player::getBetString ()
{
	std::string bet;
	stringstream ss;

	ss << mcCurrentBet;

	bet = ss.str();

	return bet;
}

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
std::string Player::printBankBalance()
{
	std::string bank;
	stringstream ss;

	ss << mcBank;

	bank = ss.str();

	return bank;
}

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
Card Player::getCard(int whichCard)
{
	return mcHand[mCurrentHand].getCard(whichCard);
}
