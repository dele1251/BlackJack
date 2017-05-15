//*******************************************************************
// File name:  Currency.cpp
// Author:     Josh Napoles
// Date:	     04/17/17
// Class:      CS485
// Assignment: 04_Bank
// Purpose:    Impliment the class Currency
//*******************************************************************
#include "Currency.h"

//***************************************************************************
// Constructor: Currency
//
// Description: default constructor for currency
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************
Currency::Currency()
{
	meCurrencyType = $;
}

//***************************************************************************
// Function:    operator!=
//
// Description: checks to see if the currencies are not equal
//
// Parameters:  rcCurrency	- the currency being compared
//
// Returned:    true if the currencies dont match
//**************************************************************************
bool Currency::operator!= (const Currency &rcCurrency)
{
	bool bSameCurrency = false;

	if (meCurrencyType != rcCurrency.meCurrencyType)
	{
		bSameCurrency = true;
	}

	return bSameCurrency;
}
bool Currency::operator== (const Currency &cCurrency)
{
	bool bEquals = false;
	if (meCurrencyType == cCurrency.meCurrencyType)
	{
		bEquals = true;
	}
	return bEquals;
}

//***************************************************************************
// Function:    operator>>
//
// Description: insertion operator for currency
//
// Parameters:  rcCurrency	- the currency to be read in
//
// Returned:    istream - the stream
//**************************************************************************
istream & operator >> (istream &rInput, Currency &rcCurrency)
{
	string theCurrency;
	rInput >> theCurrency;

	if ("$" == theCurrency)
	{
		rcCurrency.meCurrencyType = rcCurrency.$;
	}
	/*else if ("GBP" == theCurrency)
	{
		rcCurrency.meCurrencyType = rcCurrency.GBP;
	}
	else if ("YEN" == theCurrency)
	{
		rcCurrency.meCurrencyType = rcCurrency.YEN;
	}
	else if ("EUR" == theCurrency)
	{
		rcCurrency.meCurrencyType = rcCurrency.EUR;
	}*/

	return rInput;
}

//***************************************************************************
// Function:    operator>>
//
// Description: ouput operator for currency
//
// Parameters:  rcCurrency	- the currency to be printed
//
// Returned:    ostream - the stream
//**************************************************************************
ostream & operator<< (ostream &rOut, Currency &rcCurrency)
{
	if (rcCurrency.meCurrencyType == rcCurrency.$)
	{
		rOut << "$";
	}
	/*else if (rcCurrency.meCurrencyType == rcCurrency.GBP)
	{
		rOut << "GBP";
	}
	else if (rcCurrency.meCurrencyType == rcCurrency.EUR)
	{
		rOut << "EUR";
	}
	else if (rcCurrency.meCurrencyType == rcCurrency.YEN)
	{
		rOut << "YEN";
	}*/

	return rOut;
}
