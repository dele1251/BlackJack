//****************************************************************************
// File name:		Player.h
// Author:			Josh Napoles
// Date:				4/27/2017
// Class:				CS485
// Assignment:	BlackJack_Group5
// Purpose:			Contains the object data for a Player
//**************************************************************************** 
#pragma once
#include <string>
#include <sstream>
#include "Money.h"
#include "Hand.h"
#include "Card.h"

class Player
{
public:
	Player ();
	Player(std::string name, Money cMoney);
	Player(Player const &rcPlayer) = default;
	~Player ();

	bool makeBet (Money &);
	void loseBet ();
	void winBet ();

	virtual void hitHand (Card cCard);
	virtual void hitHand(Card cCard, int whichHand);
	virtual void hitHand(Card cCard, bool &bBlackJack, bool &bBust);

	virtual void stand (bool &bEndTurn);
	virtual void split (Card cCard1, Card cCard2);
	virtual bool canSplit();
	void resetSplitHand ();

	Money getBet ();
	bool checkIfBankrupt ();
	Money getBankRoll () const;
	int getHandValue ();
	Card getCard(int whichCard);
	std::string getName ();
	int getCurrentHand ();
	void incrementPlayerHand ();
	bool hasSplit ();
	void winBlackJackBet ();
	void resetHand ();

	bool isBlackJack();

	std::string printHand();
	std::string printHandValue();
	std::string getBetString ();
	std::string printBankBalance ();

	Player operator+ (Money &rcRight);
	Player operator- (Money &rcRight);

	
	bool operator< (int) const;
	bool operator> (int) const;
	bool operator== (int) const;
	bool operator<= (int) const;
	bool operator>= (int) const;

	friend bool operator< (const Player &rcLeft, const Player &rcRight);
	friend bool operator> (const Player &rcLeft, const Player &rcRight) ;
	friend bool operator== (const Player &rcLeft, const Player &rcRight);
	friend bool operator<= (const Player &rcLeft, const Player &rcRight);
	friend bool operator>= (const Player &rcLeft, const Player &rcRight);


	Player & operator= (const Player &);

	void startTurn (bool &bBlackJack);

private:
	std::string mName;
	Hand mcHand [2];
	Money mcBank;
	Money mcCurrentBet;
	bool mBankrupt;
	int mCurrentHand = 0;
	bool mbSplitHand = false;
};