//*******************************************************************
// File name:  BlackJackDeck.cpp
// Author:     Kyle Pestka
// Date:	     05/01/17
// Class:      CS485
// Assignment: 05_Group
// Purpose:    implement the BlackJackDeck
//*******************************************************************
#include "BlackJackDeck.h"


//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
BlackJackDeck::BlackJackDeck (int numberOfDecks) : Deck (numberOfDecks)
{
	mRunningcount = 0;
  mCardsInDeck = numberOfDecks;
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
bool BlackJackDeck::validateLimit (int)
{
  return false;
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
bool BlackJackDeck::setLimit (int)
{
  return false;
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
int BlackJackDeck::getRunningCount() const
{
	return mRunningcount;
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
Card BlackJackDeck::drawCard()
{
	Card cTemp;

	cTemp = Deck::drawCard();

	if (cTemp > RUNNING_COUNT_SEVEN)
	{
		++mRunningcount;
	}
	else if (cTemp <= RUNNING_COUNT_10)
	{
		--mRunningcount;
	}

	return cTemp;
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
int BlackJackDeck::getDealerCardValue() const
{
	//Card pcTemp = mDiscardDeck.back ();
	//return pcTemp.getCardValue ();
	return mDealersUpCardValue;
  //return 10;
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
void BlackJackDeck::setDealersUpCardValue(int value)
{
	mDealersUpCardValue = value;
}