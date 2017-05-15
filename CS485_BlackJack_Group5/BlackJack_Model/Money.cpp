//*******************************************************************
// File name:  Money.cpp
// Author:     Josh Napoles
// Date:	     04/17/17
// Class:      CS485
// Assignment: 04_Bank
// Purpose:    Impliment the class Money
//*******************************************************************
#include "Money.h"

//***************************************************************************
// Constructor: Money
//
// Description: constructor for Money
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************
Money::Money ()
{

}

//***************************************************************************
// Constructor: Money
//
// Description: constructor for Money
//
// Parameters:  amount	- long long that sets the amount
//
// Returned:    none
//***************************************************************************
Money::Money (long long amount, Currency type)
{
	mAmount = amount;
	mcCurrency = type;
}

//***************************************************************************
// Function:    operator+
//
// Description: adds two Moneys
//
// Parameters:  rcMoney - The money added to the mAmount
//
// Returned:    Money		- the changed amount
//												(may throw an exception)
//***************************************************************************
Money Money::operator+ (const Money &rcMoney)
{
	CurrencyException cException;
	if (mcCurrency != rcMoney.mcCurrency)
	{
		throw cException;
	}

	mAmount = mAmount + rcMoney.mAmount;
	return *this;
}

//***************************************************************************
// Function:    operator-
//
// Description: subtracts money form the mAmount
//
// Parameters:  rcMoney - The money subtracted from the mAmount
//
// Returned:    Money		- the changed amount
//												(may throw an exception)
//***************************************************************************
Money Money::operator- (const Money &rcMoney)
{
	CurrencyException cException;
	if (mcCurrency != rcMoney.mcCurrency)
	{
		throw cException;
	}
	mAmount = mAmount - rcMoney.mAmount;
	return *this;
}

//***************************************************************************
// Function:    operator==
//
// Description: compares two mAmounts
//
// Parameters:  rcMoney - The money compared to mAmount
//
// Returned:    bool		- true if the mAmounts are equal
//												(may throw an exception)
//***************************************************************************
bool Money::operator== (Money &rcMoney)
{
		bool bEquals = false;
		CurrencyException cException;

		if (mcCurrency != rcMoney.mcCurrency)
		{
			CurrencyConversion  &cCurrencyConversion =
				CurrencyConversion::getInstance();

			if (cCurrencyConversion.isConversion (rcMoney.getCurrency (),
				getCurrency ()))
			{
				double conversionRate = cCurrencyConversion.getConversion
				(rcMoney.getCurrency (), getCurrency ());

				rcMoney.conversion(getCurrency (), conversionRate);
			}
			else
			{
				throw cException;
			}
		}

		if (mAmount == rcMoney.mAmount)
		{
				bEquals = true;
		}

		return bEquals;
}

//***************************************************************************
// Function:    operator<
//
// Description: checks to see if the passed amount is less than
//
// Parameters:  rcMoney - The money the mAmount is checked agianst
//
// Returned:    bool	- true if the mAmount is less than
//                      (may throw an exception)
//***************************************************************************
bool Money::operator< ( Money &rcMoney)
{
		bool bLessThan = false;
		CurrencyException cException;

		if (mcCurrency != rcMoney.mcCurrency)
		{
			CurrencyConversion  &cCurrencyConversion =
				CurrencyConversion::getInstance();

			if (cCurrencyConversion.isConversion (rcMoney.getCurrency (),
				getCurrency ()))
			{
				double conversionRate = cCurrencyConversion.getConversion
				(rcMoney.getCurrency (), getCurrency ());

				rcMoney.conversion (getCurrency (), conversionRate);
			}
			else
			{
				throw cException;
			}
		}

		if (mAmount < rcMoney.mAmount)
		{
				bLessThan = true;
		}

		return bLessThan;
}

//***************************************************************************
// Function:    operator>
//
// Description: checks to see if the passed amount is greater than
//
// Parameters:  rcMoney - The money the mAmount is checked agianst 
//
// Returned:    bool		- true if the mAmount is greater than
//												(may throw an exception)
//***************************************************************************
bool Money::operator> (Money &rcMoney)
{
		bool bGreaterThan = false;
		CurrencyException cException;

		if (mcCurrency != rcMoney.mcCurrency)
		{
			CurrencyConversion  &cCurrencyConversion =
				CurrencyConversion::getInstance();

			if (cCurrencyConversion.isConversion (rcMoney.getCurrency(),
				getCurrency()))
			{
				double conversionRate = cCurrencyConversion.getConversion
				(rcMoney.getCurrency (), getCurrency ());

				rcMoney.conversion (getCurrency(), conversionRate);
			}
			else
			{
				throw cException;
			}

		}

		if (mAmount > rcMoney.mAmount)
		{
				bGreaterThan = true;
		}

		return  bGreaterThan;
}

//***************************************************************************
// Function:		conversion
//
// Description: converts the existing currency to the passed in currency
//
// Parameters:  newCurrency		- change the current currency to this
//							conversionRate- the conversion rate of the balance
//
// Returned:    none
//**************************************************************************
void Money::conversion (Currency newCurrency, double conversionRate)
{
	mcCurrency = newCurrency;

	mAmount = static_cast <long long> (mAmount * conversionRate);
}

//***************************************************************************
// Function:    positiveBalance
//
// Description: checks to see if the passed amount is greater than 0
//
// Parameters:  none
//
// Returned:    bool		- true if the mAmount is greater than 0
//***************************************************************************
bool Money::positiveBalance ()
{
		bool bPositive = false;
		if (0 < mAmount)
		{
				bPositive = true;
		}
		return bPositive;
}

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
Currency Money::getCurrency ()
{
	return mcCurrency;
}

//***************************************************************************
// Function:    operator*
//
// Description: multiplies money and interest rate
//
// Parameters:  rate		- the interestRate 
//
// Returned:    Money		- the mAmount * interest Rate
//***************************************************************************
Money Money::operator* (double Rate)
{
	long long amt = static_cast <long long> (Rate * mAmount);
	//long long amt = (Rate * mAmount);
	Money cMoney (amt, this->mcCurrency);
	return cMoney;
}

//***************************************************************************
// Function:    operator >>
//
// Description: reads in the amount from a stream
//
// Parameters:  rInput       - the stream
//              rcMoney			 - the address of the money
//
// Returned:    istream      - the stream
//***************************************************************************
istream & operator >> (istream & rInput, Money & rcMoney)
{
	rInput >> rcMoney.mcCurrency;
	rInput >> rcMoney.mAmount;
	return rInput;
}

//***************************************************************************
// Function:    operator <<
//
// Description: displays the money to the screen
//
// Parameters:  rOut				 - the stream
//              rcMoney			 - the address of the money
//
// Returned:    ostream      - the stream
//***************************************************************************
ostream & operator<< (ostream & rOut, Money & rcMoney)
{
	double displayBalance = rcMoney.mAmount / 100.00;
	rOut << rcMoney.mcCurrency << fixed << setprecision (2) << displayBalance;
	return rOut;
}

