//****************************************************************************
// File name:		BlackJackDeck.h
// Author:			Kyle Pestka
// Date:				4/27/2017
// Class:				CS485
// Assignment:	BlackJack_Group5
// Purpose:			Contains the object data for a card
//**************************************************************************** 

#pragma once

#include "Deck.h"

class BlackJackDeck : public Deck
{
  public:
    BlackJackDeck () = default;
    BlackJackDeck (int numberOfDecks);
    ~BlackJackDeck () = default;

		static const int RUNNING_COUNT_SEVEN = 7; 
		static const int RUNNING_COUNT_10 = 10;

    bool validateLimit (int);
    bool setLimit (int);
		int getRunningCount() const;

		Card drawCard();

		int getDealerCardValue() const;
		void setDealersUpCardValue(int value);
  private:
    const unsigned int MAX_CARDS = 312;
    unsigned int mCardsInDeck;
		int mRunningcount; // Move this to strategy related class. Doesn't belong here I think
};