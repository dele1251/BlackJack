//***************************************************************************
// File name:  Hand.cpp
// Author:     Josh Napoles
// Date:	     04/27/17
// Class:      CS485
// Assignment: Group 5 Final Project
// Purpose:    Impliment the class Hand
//***************************************************************************
#include "Hand.h"
const int ACE_DROP = 21;

//***************************************************************************
// Constructor: Hand
//
// Description: constructor for Hand
//
// Parameters:  none
//
// Returned:    none
//**************************************************************************
Hand::Hand ()
{
}

//***************************************************************************
// Destructor:  Hand
//
// Description: constructor for Money
//
// Parameters:  none
//
// Returned:    none
//**************************************************************************
Hand::~Hand()
{

}

//***************************************************************************
// Function:		calculateHand
//
// Description: calculates and returns the value of the Hand
//
// Parameters:  none
//
// Returned:    none
//**************************************************************************
int Hand::calculateHand ()
{
	int handValue = 0;
	for (auto it = mcvTheHand.begin (); it < mcvTheHand.end (); it++)
	{
		handValue = handValue + it->getCardValue ();
	}

	// checks for ace in the hand and if handValue is over 21 drops by 10
	for (auto it = mcvTheHand.begin (); it < mcvTheHand.end (); it++)
	{
		if (it->getRank () == 'A' && handValue > ACE_DROP)
		{
			handValue = handValue - 10;
		}
	}

	mHandValue = handValue;

	return handValue;
}

//***************************************************************************
// Function:		addCard
//
// Description: adds a card to the Hand
//
// Parameters:  cTheCard	- card that is added to the hand
//
// Returned:    none
//**************************************************************************
void Hand::addCard (Card cTheCard)
{
	mcvTheHand.push_back (cTheCard);
	calculateHand();
	mCardsInHand++;
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
bool Hand::isBust()
{
	bool bBust = false;
	if (mHandValue > 21)
	{
		bBust = true;
	}
	return bBust;
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
bool Hand::isBlackJack()
{
	bool bBlackJack = false; 
	if (mHandValue == 21)
	{
		bBlackJack = true;
	}

	return bBlackJack;
}

//***************************************************************************
// Function:		deleteCard
//
// Description: deletes the card with the passed in values
//
// Parameters:  rank	- char representation of the card rank
//							suit	- char representation of the card suit
//
// Returned:    none
//**************************************************************************
void Hand::deleteCard (char rank, char suit)
{
	if (isIn(rank, suit))
	{
		for (size_t i = 0; i < mcvTheHand.size (); i++)
		{
			if (mcvTheHand [i].getRank () == rank)
			{
				if (mcvTheHand [i].getSuit () == suit)
				{
					mcvTheHand.erase (mcvTheHand.begin () + i);
				}
			}
		}
	}
}

void Hand::deleteCard(int position)
{

}

//***************************************************************************
// Function:		isIn
//
// Description: sees if a card is in the hand
//
// Parameters:  rank	- char representation of the card rank
//							suit	- char representation of the card suit
//
// Returned:    bool	- ture if card is in Hand; false otherwise
//**************************************************************************
bool Hand::isIn (char rank, char suit)
{
	bool bInHand = false;

	for (size_t i = 0; i < mcvTheHand.size (); i++)
	{
		if (mcvTheHand [i].getRank () == rank)
		{
			if (mcvTheHand [i].getSuit () == suit)
			{
				bInHand = true;
			}
		}
	}
	return bInHand;
}
//***************************************************************************
// Function:		splitHand
//
// Description: returns the second card in the hand
//
// Parameters:  none
//
// Returned:    Card	- the second card in the hand
//**************************************************************************
void Hand::splitHand (Hand &rcHand)
{
	rcHand.addCard(mcvTheHand.at(1));
	deleteCard(1);
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
bool Hand::canSplit()
{
	bool bCanSplit = false;
	if (mcvTheHand.at(0).getRank() == mcvTheHand.at(1).getRank())
	{
		bCanSplit = true;
	}
	return bCanSplit;
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
void Hand::startTurn()
{
	for (auto & element : mcvTheHand)
	{
		element.flip();
	}

	calculateHand();
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
int Hand::getCardValue (int cardIndex)
{
	return mcvTheHand[cardIndex].getCardValue ();
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
void Hand::clearHand()
{
	mcvTheHand.clear ();
	mCardsInHand = 0;
	mHandValue = 0;
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
bool Hand::operator<(int right) const
{
	return mHandValue < right;
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
bool Hand::operator>(int right) const
{
	return mHandValue > right;
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
bool Hand::operator==(int right) const
{
	return mHandValue == right;
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
bool Hand::operator<=(int right) const
{
	return mHandValue <= right;
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
bool Hand::operator>=(int right) const
{
	return mHandValue >= right;
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
Hand & Hand::operator=(const Hand &rcHand)

{
	mCardsInHand = rcHand.mCardsInHand;
	mHandValue = rcHand.mCardsInHand;
	mcvTheHand = rcHand.mcvTheHand;
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
std::string Hand::printHandValue ()

{
	std::string returnString;

	returnString = std::to_string(mHandValue);

	returnString.append(" ");

	return returnString;
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
bool operator< (const Hand & rcLeft, const Hand & rcRight)

{
	return rcLeft.mHandValue < rcRight.mHandValue;
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
bool operator>(const Hand & rcLeft, const Hand & rcRight)

{
	return rcLeft.mHandValue > rcRight.mHandValue;
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
bool operator==(const Hand & rcLeft, const Hand & rcRight)

{
	return rcLeft.mHandValue == rcRight.mHandValue;
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
bool operator<=(const Hand & rcLeft, const Hand & rcRight)
{
	return rcLeft.mHandValue <= rcRight.mHandValue;
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
bool operator>=(const Hand & rcLeft, const Hand & rcRight)
{
	return rcLeft.mHandValue >= rcRight.mHandValue;
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
std::ostream  &operator<<(std::ostream &rcOut, Hand rcHand)
{
	for (int i = 0; i < rcHand.mCardsInHand; i++)
	{
		rcOut << rcHand.mcvTheHand.at(i) << " ";
	}

	return rcOut;
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
Card Hand::getCard (int index)
{
	return mcvTheHand.at (index);
}
//
//int Hand::getCardsInHand ()
//{
//	return mCardsInHand;
//}
