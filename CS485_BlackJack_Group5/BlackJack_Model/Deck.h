//****************************************************************************
// File name:		Deck.h
// Author:			Kyle Pestka
// Date:				4/27/2017
// Class:				CS485
// Assignment:	BlackJack_Group5
// Purpose:			Contains the object data for a card
//**************************************************************************** 

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include "Card.h"

class Deck
{
public:
	const int MAX_NUM_DECKS = 6;

	Deck() {};
	Deck(int);
	~Deck() {};

	void buildNewDeck(int amountOfDecks);
	void shuffle();
	bool isIn(char rank, char suit);
	void addCard(Card card);
	void deleteCard(char rank, char suit);
	virtual Card drawCard();
	void resetDeck();

	void stackDeckTest1 ();
	void stackDeckTest2 ();
	void stackDeckTest3 ();

	int getDealerCardValue () const;
	void setDealersUpCardValue(int value);
	size_t getNumCardsInDeck () const;


	friend std::ostream& operator<< (std::ostream &output, Deck &cDeck);

protected:
	std::vector <Card> mDeck;
	std::vector <Card> mDiscardDeck;
	int mDealersUpCardValue;
};