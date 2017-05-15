//*******************************************************************
// File name:  CurrencyConversion.cpp
// Author:     Josh Napoles
// Date:	     04/17/17
// Class:      CS485
// Assignment: 04_Bank
// Purpose:    Impliment the Account class
//*******************************************************************
#include "CurrencyConversion.h"

//***************************************************************************
// Function:    getInstance
//
// Description: returns the static instance
//
// Parameters:  none
//
// Returned:    instance - the currency conversion instance
//**************************************************************************
CurrencyConversion& CurrencyConversion::getInstance ()
{ 
	static CurrencyConversion instance;
	return instance;
}

//***************************************************************************
// Function:    getConversion
//
// Description: returns the correct conversion
//
// Parameters:  cCurrency1			- the first Currency
//							cCurrency2			- the second currency being compared
//
// Returned:    conversionRate	- the correct conversion rate
//**************************************************************************
double CurrencyConversion::getConversion (Currency cCurrency1, Currency 
	cCurrency2)
{
	double conversionRate = 1.0;

	for (int i = 0; i < numberOfConversions; i++)
	{
		if (maCurrencyChart [i][0] == cCurrency1)
		{
			if (maCurrencyChart [i][1] == cCurrency2)
			{
				conversionRate = maConversionRates[i];
			}
		}
		else if (maCurrencyChart [i][1] == cCurrency1)
		{
			if (maCurrencyChart [i][0] == cCurrency2)
			{
				conversionRate = (1.00 / maConversionRates [i]);
			}
		}
	}

	return conversionRate;
}

//***************************************************************************
// Function:    open
//
// Description: opens the input for write
//
// Parameters:  filename - the name of the file to be opened
//
// Returned:    none
//**************************************************************************
void CurrencyConversion::open (string filename)
{
	mInput.open (filename);
	if (mInput.fail ())
	{
		cout << "File " << filename << " failed to open!\n";

		exit(EXIT_FAILURE);
	}
}

//***************************************************************************
// Function:    close
//
// Description: closes the file
//
// Parameters:  none
//
// Returned:    none
//**************************************************************************
void CurrencyConversion::close ()
{
	mInput.close ();
}

//***************************************************************************
// Function:    readRates
//
// Description: reads the conversion rates from the file
//
// Parameters:  none
//
// Returned:    none
//**************************************************************************
void CurrencyConversion::readRates ()
{

	while (!mInput.eof ())
	{
		for (int j = 0; j < 2; j++)
		{
			mInput >> maCurrencyChart [numberOfConversions][j];
		}
		mInput >> maConversionRates [numberOfConversions];
		numberOfConversions++; 
	}
}

//***************************************************************************
// Function:    isConversion
//
// Description: checks to see if there is an available conversion
//
// Parameters:  none
//
// Returned:    bIsConversion	- true if there is an available conversion
//**************************************************************************
bool CurrencyConversion::isConversion (Currency cCurrency1, Currency cCurrency2)
{
	bool bIsConversion = false;

	for (int i = 0; i < numberOfConversions; i++)
	{
		if (maCurrencyChart[i][0] == cCurrency1)
		{
			if (maCurrencyChart[i][1] == cCurrency2)
			{
				bIsConversion = true;
			}
		}
		else if (maCurrencyChart[i][1] == cCurrency1)
		{
			if (maCurrencyChart[i][0] == cCurrency2)
			{
				bIsConversion = true;
			}
		}
	}


	return bIsConversion;
}

//***************************************************************************
// Constructor: CurrencyConversion
//
// Description: constructs a currency conversion
//
// Parameters:  none
//
// Returned:    none
//**************************************************************************
CurrencyConversion::CurrencyConversion ()
{

}

//***************************************************************************
// Destructor: CurrencyConversion
//
// Description: destructs a currency conversion
//
// Parameters:  none
//
// Returned:    none
//**************************************************************************
CurrencyConversion::~CurrencyConversion ()
{

}
