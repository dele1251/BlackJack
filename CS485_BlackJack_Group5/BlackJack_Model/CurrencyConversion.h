//*******************************************************************
// File name:  CurrencyConversion.h
// Author:     Josh Napoles
// Date:	     04/17/17
// Class:      CS485
// Assignment: 04_Bank
// Purpose:    Define the class CurrencyConversion
//*******************************************************************
#pragma once
#include "Currency.h"

class CurrencyConversion
{
public:
	static CurrencyConversion& getInstance ();
	double getConversion (Currency, Currency);

	void open (string ); 
	void close (); 
	void readRates (); 
	bool isConversion (Currency, Currency); 

private:
	Currency maCurrencyChart [6][2];
	double maConversionRates [6]; 
	ifstream mInput;
	int numberOfConversions = 0; 


	CurrencyConversion ();
	~CurrencyConversion (); 
	CurrencyConversion& operator= (CurrencyConversion const&) = delete;
	CurrencyConversion (CurrencyConversion const&) = delete;
};
