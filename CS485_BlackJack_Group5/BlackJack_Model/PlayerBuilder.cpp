//*******************************************************************
// File name:  PlayerBuilder.cpp
// Author:     Michael Sakai
// Date:	     05/01/17
// Class:      CS485
// Assignment: 05_Group
// Purpose:    Impliment the PlayerBuilder
//*******************************************************************
#include "PlayerBuilder.h"

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void PlayerBuilder::buildName(std::string name)
{
	mName = name;
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
void PlayerBuilder::buildBank(Money cBank)
{
	mcBank = cBank;
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
Player PlayerBuilder::createPlayer()
{
	Player cPlayer(mName, mcBank);
	return cPlayer;
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
std::string PlayerBuilder::getName()
{
	return mName;
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
std::string PlayerBuilder::getBank ()
{
	std::string bank;
	stringstream ss;

	ss << mcBank;

	bank = ss.str();

	return bank;
}
