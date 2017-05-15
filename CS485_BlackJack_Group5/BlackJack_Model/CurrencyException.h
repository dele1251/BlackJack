//*******************************************************************
// File name:  CurrencyException.h
// Author:     Josh Napoles
// Date:	     04/17/17
// Class:      CS485
// Assignment: 04_Bank
// Purpose:    Define the class CurrencyException
//*******************************************************************
#pragma once

#include <exception>

class CurrencyException : public std::exception
{
public:
	CurrencyException ();
	CurrencyException (const CurrencyException &rcOther);
	~CurrencyException ();

	//CurrencyException & operator= (CurrencyException &cOther);

	virtual const char* what() const override;
};