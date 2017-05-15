 //*******************************************************************
// File name:  Currency.h
// Author:     Josh Napoles
// Date:	     04/17/17
// Class:      CS485
// Assignment: 04_Bank
// Purpose:    Define the class Currency
//*******************************************************************
#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Currency
{
public:
	Currency ();

	bool operator!= (const Currency &);
	bool operator == (const Currency &); 

	friend istream& operator >> (istream &rInput, Currency &rcCurrency);
	friend ostream& operator << (ostream &rOut, Currency &rcCurrency);

private:
	enum Currencies { $, GBP, YEN, EUR };
	Currencies meCurrencyType;
};