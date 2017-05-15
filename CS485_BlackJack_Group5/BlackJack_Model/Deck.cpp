//*******************************************************************
// File name:  Deck.cpp
// Author:     Kyle Pestka
// Date:	     05/01/17
// Class:      CS485
// Assignment: 05_Group
// Purpose:    impliment the Deck
//*******************************************************************
#include "Deck.h"

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
Deck::Deck (int amountOfDecks)
{
	buildNewDeck (amountOfDecks);
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
void Deck::buildNewDeck (int amountOfDecks)
{
	char suit;
	for (int i = 0; i < amountOfDecks; i++)
	{
		for (int s = 0; s < 4; s++)
		{
			switch (s)
			{
			case 0:
				suit = 'S';
				break;
			case 1:
				suit = 'H';
				break;
			case 2:
				suit = 'C';
				break;
			case 3:
				suit = 'D';
				break;
			}

			for (int v = 2; v < 15; v++)
			{
				char tempRank;

				switch (v)
				{
				case 2:
					tempRank = '2';
					break;
				case 3:
					tempRank = '3';
					break;
				case 4:
					tempRank = '4';
					break;
				case 5:
					tempRank = '5';
					break;
				case 6:
					tempRank = '6';
					break;
				case 7:
					tempRank = '7';
					break;
				case 8:
					tempRank = '8';
					break;
				case 9:
					tempRank = '9';
					break;
				case 10:
					tempRank = 'T';
					break;
				case 11:
					tempRank = 'J';
					break;
				case 12:
					tempRank = 'Q';
					break;
				case 13:
					tempRank = 'K';
					break;
				case 14:
					tempRank = 'A';
					break;
				}

				Card tempCard (tempRank, suit, true);
				addCard (tempCard);
			}
		}
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
void Deck::shuffle ()
{
	srand (unsigned (time (NULL)));
	std::random_shuffle (mDeck.begin (), mDeck.end ());
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
bool Deck::isIn (char rank, char suit)
{
	for (size_t i = 0; i < mDeck.size (); i++)
	{
		if (mDeck[i].getRank () == rank)
		{
			if (mDeck[i].getSuit () == suit)
			{
				return true;
			}
		}
	}
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
void Deck::addCard (Card cCard)
{
	mDeck.push_back (cCard);
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
void Deck::deleteCard (char rank, char suit)
{
	if (isIn (rank, suit))
	{
		for (size_t i = 0; i < mDeck.size (); i++)
		{
			if (mDeck[i].getRank () == rank)
			{
				if (mDeck[i].getSuit () == suit)
				{
					mDeck.erase (mDeck.begin () + i);
				}
			}
		}
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
Card Deck::drawCard ()
{
	auto &it = mDeck.back ();
	Card pcTemp = it;

	mDiscardDeck.push_back (pcTemp);
	mDeck.pop_back ();
	return pcTemp;
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
void Deck::resetDeck ()
{
	int temp = (mDeck.size () / 52);
	mDeck.clear ();
	buildNewDeck (temp);
}

//***************************************************************************
// Function:    M_stackDeckTest1
//
// Description:	player gets blackjack on first two cards
//
// Parameters:  none
//
// Returned:    
//***************************************************************************
void Deck::stackDeckTest1 ()
{
	Card tempCard('K', 'H', true); // player
	addCard (tempCard);

	tempCard.setCard('5', 'C', true); //cpu1
	addCard(tempCard);

	tempCard.setCard('8', 'D', true); //cpu 2
	addCard(tempCard);

	tempCard.setCard('J', 'S', true); // dealer
	addCard(tempCard);

	tempCard.setCard('A', 'H', true); // player
	addCard(tempCard);

	tempCard.setCard('8', 'C', true); //cpu1
	addCard(tempCard);

	tempCard.setCard('9', 'D', true); //cpu 2
	addCard(tempCard);

	tempCard.setCard('7', 'S', true); // dealer
	addCard(tempCard);

	////////////////////////////////////////////////////

	tempCard.setCard('7', 'C', true);
	addCard(tempCard);

	tempCard.setCard('5', 'D', true);
	addCard(tempCard);

	tempCard.setCard('5', 'C', true);
	addCard(tempCard);

	tempCard.setCard('K', 'S', true);
	addCard(tempCard);

	tempCard.setCard('A', 'C', true);
	addCard(tempCard);

	tempCard.setCard('4', 'C', true);
	addCard(tempCard);

	tempCard.setCard('5', 'D', true);
	addCard(tempCard);

	tempCard.setCard('6', 'C', true);
	addCard(tempCard);

	tempCard.setCard('2', 'S', true);
	addCard(tempCard);

	tempCard.setCard('3', 'C', true);
	addCard(tempCard);

	tempCard.setCard('7', 'C', true);
	addCard(tempCard);

	tempCard.setCard('5', 'D', true);
	addCard(tempCard);

	tempCard.setCard('5', 'C', true);
	addCard(tempCard);

	tempCard.setCard('K', 'S', true);
	addCard(tempCard);

	tempCard.setCard('A', 'C', true);
	addCard(tempCard);

	tempCard.setCard('4', 'C', true);
	addCard(tempCard);

	tempCard.setCard('5', 'D', true);
	addCard(tempCard);

	tempCard.setCard('6', 'C', true);
	addCard(tempCard);

	tempCard.setCard('3', 'S', true);
	addCard(tempCard);

	tempCard.setCard('6', 'C', true);
	addCard(tempCard);
}

//***************************************************************************
// Function:    M_stackDeckTest2
//
// Description:	Human has a chance to split hand
//
// Parameters:  none
//
// Returned:    
//***************************************************************************
void Deck::stackDeckTest2 ()
{
	Card tempCard('8', 'H', true); // player
	addCard(tempCard);

	tempCard.setCard('5', 'C', true); //cpu1
	addCard(tempCard);

	tempCard.setCard('8', 'D', true); //cpu 2
	addCard(tempCard);

	tempCard.setCard('J', 'S', true); // dealer
	addCard(tempCard);

	tempCard.setCard('8', 'S', true); // player
	addCard(tempCard);

	tempCard.setCard('8', 'C', true); //cpu1
	addCard(tempCard);

	tempCard.setCard('9', 'D', true); //cpu 2
	addCard(tempCard);

	tempCard.setCard('7', 'S', true); // dealer
	addCard(tempCard);

	/////////////////////////////////////////////////////////

	tempCard.setCard('7', 'C', true);
	addCard(tempCard);

	tempCard.setCard('5', 'D', true);
	addCard(tempCard);

	tempCard.setCard('5', 'C', true);
	addCard(tempCard);

	tempCard.setCard('K', 'S', true);
	addCard(tempCard);

	tempCard.setCard('A', 'C', true);
	addCard(tempCard);

	tempCard.setCard('4', 'C', true);
	addCard(tempCard);

	tempCard.setCard('5', 'D', true);
	addCard(tempCard);

	tempCard.setCard('6', 'C', true);
	addCard(tempCard);

	tempCard.setCard('2', 'S', true);
	addCard(tempCard);

	tempCard.setCard('3', 'C', true);
	addCard(tempCard);

	tempCard.setCard('7', 'C', true);
	addCard(tempCard);

	tempCard.setCard('5', 'D', true);
	addCard(tempCard);

	tempCard.setCard('5', 'C', true);
	addCard(tempCard);

	tempCard.setCard('K', 'S', true);
	addCard(tempCard);

	tempCard.setCard('A', 'C', true);
	addCard(tempCard);

	tempCard.setCard('4', 'C', true);
	addCard(tempCard);

	tempCard.setCard('5', 'D', true);
	addCard(tempCard);

	tempCard.setCard('6', 'C', true);
	addCard(tempCard);

	tempCard.setCard('3', 'S', true);
	addCard(tempCard);

	tempCard.setCard('6', 'C', true);
	addCard(tempCard);

	tempCard.setCard('K', 'S', true);
	addCard(tempCard);

	tempCard.setCard('A', 'C', true);
	addCard(tempCard);

	tempCard.setCard('4', 'C', true);
	addCard(tempCard);

	tempCard.setCard('5', 'D', true);
	addCard(tempCard);

	tempCard.setCard('6', 'C', true);
	addCard(tempCard);
}
//***************************************************************************
// Function:    M_stackDeckTest3
//
// Description:	dealer goes bust
//
// Parameters:  none
//
// Returned:    
//***************************************************************************
void Deck::stackDeckTest3 ()
{
	Card tempCard('7', 'H', true); // player 7
	addCard(tempCard);

	tempCard.setCard('5', 'C', true); //cpu1 5
	addCard(tempCard);

	tempCard.setCard('8', 'D', true); //cpu2 8
	addCard(tempCard);

	tempCard.setCard('J', 'S', true); // dealer 10
	addCard(tempCard);

	tempCard.setCard('8', 'S', true); // player 15
	addCard(tempCard);

	tempCard.setCard('8', 'C', true); //cpu1 13
	addCard(tempCard);

	tempCard.setCard('7', 'D', true); //cpu2 15
	addCard(tempCard);

	tempCard.setCard('6', 'S', true); // dealer 16
	addCard(tempCard);

	tempCard.setCard('5', 'S', true); // player 20
	addCard(tempCard);

	tempCard.setCard('8', 'C', true); //cpu1 21
	addCard(tempCard);

	tempCard.setCard('7', 'D', true); //cpu2 18
	addCard(tempCard);

	tempCard.setCard('K', 'H', true); // dealer bust
	addCard(tempCard);

	tempCard.setCard('4', 'C', true);
	addCard(tempCard);

	tempCard.setCard('5', 'D', true);
	addCard(tempCard);

	tempCard.setCard('6', 'C', true);
	addCard(tempCard);

	tempCard.setCard('3', 'S', true);
	addCard(tempCard);

	tempCard.setCard('6', 'C', true);
	addCard(tempCard);

	tempCard.setCard('K', 'S', true);
	addCard(tempCard);

	tempCard.setCard('A', 'C', true);
	addCard(tempCard);

	tempCard.setCard('4', 'C', true);
	addCard(tempCard);

	tempCard.setCard('5', 'D', true);
	addCard(tempCard);

	tempCard.setCard('6', 'C', true);
	addCard(tempCard);

	tempCard.setCard('5', 'D', true);
	addCard(tempCard);

	tempCard.setCard('6', 'C', true);
	addCard(tempCard);

	tempCard.setCard('3', 'S', true);
	addCard(tempCard);

	tempCard.setCard('6', 'C', true);
	addCard(tempCard);

	tempCard.setCard('K', 'S', true);
	addCard(tempCard);

	tempCard.setCard('A', 'C', true);
	addCard(tempCard);

	tempCard.setCard('4', 'C', true);
	addCard(tempCard);
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
std::ostream & operator<<(std::ostream & output, Deck & cDeck)
{
	int count = 1;

	for (auto i = cDeck.mDeck.begin (); i != cDeck.mDeck.end (); i++)
	{
		if (count % 14 == 0)
		{
			output << std::endl;
			count = 1;
		}

		output << "(" << *i << ")";
		count++;
	}

	output << std::endl;

	return output;
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
size_t Deck::getNumCardsInDeck () const
{
	return mDeck.size ();
}
