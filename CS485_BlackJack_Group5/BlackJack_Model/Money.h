//*******************************************************************
// File name:  Money.h
// Author:     Josh Napoles
// Date:	     04/17/17
// Class:      CS485
// Assignment: 04_Bank
// Purpose:    Define the class Money
//*******************************************************************
#pragma once
#include <iostream>
#include <iomanip>
#include "Currency.h"
#include "CurrencyException.h"
#include "CurrencyConversion.h"

using namespace std;

class Money
{
	public:
		Money ();
		Money (long long, Currency);
		Money operator+ (const Money &);
		Money operator- (const Money &);

		bool operator== (Money &);
		bool operator< ( Money &);
		bool operator> ( Money &);

		void conversion (Currency, double);

		bool positiveBalance ();
		Currency getCurrency (); 

		Money operator* (double Rate);

		friend istream& operator >> (istream &rInput, Money &rcMoney);
		friend ostream& operator << (ostream &rOut, Money &rcMoney);

	private:
		long long mAmount;
		Currency mcCurrency;
};
