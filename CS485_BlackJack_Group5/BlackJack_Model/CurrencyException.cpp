//*******************************************************************
// File name:  CurrencyException.h
// Author:     Josh Napoles
// Date:	     04/17/17
// Class:      CS485
// Assignment: 04_Bank
// Purpose:    Impliment the CurrencyException class
//*******************************************************************
#include "CurrencyException.h"

//***************************************************************************
// Constructor: CurrencyException
//
// Description: default constructor for CurrencyException
//
// Parameters:  none
//
// Returned:    none
//***************************************************************************
CurrencyException::CurrencyException ()
{
}

//***************************************************************************
// Function:    CurrencyException
//
// Description: creates currencyException using the passed in 
//              currencyException
//
// Parameters:  rcCurrency					- the currency being copied
//
// Returned:    CurrencyException		- the new currencyException
//**************************************************************************
CurrencyException::CurrencyException (const CurrencyException & rcOther)
{
}

//***************************************************************************
// Destructor:  CurrencyException
//
// Description: default currencyException destructor
//
// Parameters:  none
//
// Returned:    none
//**************************************************************************
CurrencyException::~CurrencyException ()
{
}

//***************************************************************************
// Function:    operator
//
// Description: creates currencyException using the = operator
//
// Parameters:  rcCurrency					- the currency being copied
//
// Returned:    CurrencyException		- the new currencyException
//**************************************************************************
//CurrencyException & CurrencyException::operator= (CurrencyException & cOther)
//{
	//return CurrencyException ();
//}
//***************************************************************************
// Function:    what
//
// Description: returns the currencyException method
//
// Parameters:  none
//
// Returned:    char* - the message
//**************************************************************************
const char * CurrencyException::what () const
{
	return "Currency Exception\n";
}
