//****************************************************************************
// File name:		Hand.h
// Author:			Josh Napoles
// Date:				4/27/2017
// Class:				CS485
// Assignment:	BlackJack_Group5
// Purpose:			Contains the object data for a Hand
//****************************************************************************
#pragma once
#include <string>
#include "Card.h"
#include <vector>

class Hand
{

	public:
		Hand ();
		~Hand();

		int calculateHand ();

		void addCard (Card);

		bool isBust();
		bool isBlackJack();

		void deleteCard (char rank, char suite);
		void deleteCard(int position);
		bool isIn (char rank, char suit);
		void splitHand (Hand &rcHand);
		bool canSplit();
		int getCardValue (int cardIndex);

		Card getCard(int cardIndex);

		void clearHand ();

		bool operator< (int) const;
		bool operator> (int) const;
		bool operator== (int) const;
		bool operator<= (int) const;
		bool operator>= (int) const;

		friend bool operator< (const Hand &rcLeft, const Hand &rcRight);
		friend bool operator> (const Hand &rcLeft, const Hand &rcRight);
		friend bool operator== (const Hand &rcLeft, const Hand &rcRight);
		friend bool operator<= (const Hand &rcLeft, const Hand &rcRight);
		friend bool operator>= (const Hand &rcLeft, const Hand &rcRight);

		Hand& operator= (const Hand&);


		std::string printHandValue();

		void startTurn ();

		friend std::ostream  &operator<<(std::ostream &rcOut, Hand rcHand);

	private:
		const int MAX_CARDS_IN_HAND = 10;
		const int ACE_DROP = 21;

		int mCardsInHand = 0;
		int mHandValue = 0;
		std::vector <Card> mcvTheHand;

};