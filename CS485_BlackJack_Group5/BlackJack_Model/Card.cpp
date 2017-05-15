//****************************************************************************
// File name:		Card.cpp
// Author:			Kyle Pestka
// Date:				4/27/2017
// Class:				CS485
// Assignment:	BlackJack_Group5
// Purpose:			Implementation of Card.h
//****************************************************************************

#include "Card.h"

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
Card::Card ()
{
  mValue = 0;
  mRank = '?';
  mSuit = '?';
  mbFlippedUp = true;
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
Card::Card (char rank, char suit, bool filppedUp)
{
  mRank = rank;
  mSuit = suit;
  mbFlippedUp = filppedUp;

  switch (mRank)
  {
    case '2':
      mValue = 2;
      break;
    case '3':
      mValue = 3;
      break;
    case '4':
      mValue = 4;
      break;
    case '5':
      mValue = 5;
      break;
    case '6':
      mValue = 6;
      break;
    case '7':
      mValue = 7;
      break;
    case '8':
      mValue = 8;
      break;
    case '9':
      mValue = 9;
      break;
    case 'T':
      mValue = 10;
      break;
    case 'J':
      mValue = 10;
      break;
    case 'Q':
      mValue = 10;
      break;
    case 'K':
      mValue = 10;
      break;
    case 'A':
      mValue = 11;
      break;
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
void Card::flip ()
{
	mbFlippedUp = true;
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
void Card::flipDown()
{
	mbFlippedUp = false;
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
int Card::getCardValue ()
{
	int value = 0;

	if (mbFlippedUp)
	{
		value = mValue;
	}

  return value;
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
const char Card::getRank ()
{
  return mRank;
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
const char Card::getSuit ()
{
  return mSuit;
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
void Card::setCard (char r, char s, bool b)
{
	mRank = r;
	mSuit = s;
	mbFlippedUp = b;
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
bool Card::operator>(Card & rcRight) const
{
	return mValue > rcRight.mValue;
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
bool Card::operator<(Card & rcRight) const
{
	return mValue > rcRight.mValue;
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
bool Card::operator==(Card & rcRight) const
{
	return mValue > rcRight.mValue;
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
bool Card::operator>=(Card & rcRight) const
{
	return mValue > rcRight.mValue;
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
bool Card::operator<=(Card & rcRight) const
{
	return mValue > rcRight.mValue;
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
bool Card::operator>(int right) const
{
	return mValue > right;
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
bool Card::operator<(int right) const
{
	return mValue < right;
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
bool Card::operator==(int right) const
{
	return mValue == right;
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
bool Card::operator>=(int right) const
{
	return mValue >= right;
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
bool Card::operator<=(int right) const
{
	return mValue <= right;
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
std::ostream & operator<<(std::ostream & output, Card & cCard)
{
//	if (cCard.mbFlippedUp)
	//{
		output << "(" << cCard.mRank << cCard.mSuit << ")";
//	}
	//else
	//{
		//output << "? " << cCard.mRank << cCard.mSuit;
	//}

		// testing
  return output;
}
