//****************************************************************************
// File name:		Card.h
// Author:			Kyle Pestka
// Date:				4/27/2017
// Class:				CS485
// Assignment:	BlackJack_Group5
// Purpose:			Contains the object data for a card
//****************************************************************************    

#pragma once

#include <iostream>

class Card
{
  public:
    Card ();
    Card (char rank, char suit, bool filppedUp);
    ~Card () = default;

    void draw () {};
    void flip ();
		void flipDown();
    int  getCardValue ();
    const char getRank ();
		const char getSuit();
		void setCard (char r, char s, bool b);

		bool operator>(Card &rcRight) const; 
		bool operator<(Card &rcRight) const;
		bool operator==(Card &rcRight) const;
		bool operator>=(Card &rcRight) const;
		bool operator<=(Card &rcRight) const;

		bool operator>(int right) const;
		bool operator<(int right) const;
		bool operator==(int right) const;
		bool operator>=(int right) const;
		bool operator<=(int right) const;


    friend std::ostream& operator<< (std::ostream &output, Card &cCard);

  private:
    int mValue;
    char mRank;
    char mSuit;
    bool mbFlippedUp = true;
};