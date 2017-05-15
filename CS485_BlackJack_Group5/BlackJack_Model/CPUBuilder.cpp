//*******************************************************************
// File name:  CPUBuilder.cpp
// Author:     Michael Sakai
// Date:	     05/01/17
// Class:      CS485
// Assignment: 05_Group
// Purpose:    impliment the CPUBuilder
//*******************************************************************
#include "CPUBuilder.h"

//***************************************************************************
// Function:		buildName
//
// Description: sets the name in the builder
//
// Parameters:  name	- the name
//
// Returned:    none
//**************************************************************************
void CPUBuilder::buildName(std::string name)
{
	mName = name;
}

//***************************************************************************
// Function:		buildBank
//
// Description: sets the bank in the builder
//
// Parameters:  bank	- the bank
//
// Returned:    none
//**************************************************************************
void CPUBuilder::buildBank(Money cBank)
{
	mcBank = cBank;
}

//***************************************************************************
// Function:		buildStrategy
//
// Description: sets the Strategy in the builder
//
// Parameters:  strategy	- string representation of the strategy
//
// Returned:    none
//**************************************************************************
bool CPUBuilder::buildStrategy(std::string strategy)
{
	bool bValidInput;

	bValidInput = CPUStrategyFactory::validInput(strategy);

	if (bValidInput)
	{
		mStrategy = strategy;
	}

	return bValidInput;
}

//***************************************************************************
// Function:		buildDeck
//
// Description: sets the Deck in the builder
//
// Parameters:  pcDeck	- pointer to the deck
//
// Returned:    none
//**************************************************************************
void CPUBuilder::buildDeck(BlackJackDeck *pcDeck)
{
	mpcDeck = pcDeck;
}

//***************************************************************************
// Function:		createPlayer
//
// Description: creates and returns a playerCPU based on the member data
//
// Parameters:	none
//
// Returned:    PlayerCPU	- a CPU Player
//**************************************************************************
PlayerCPU* CPUBuilder::createPlayer()
{
	return new PlayerCPU(mName, mcBank, mStrategy, mpcDeck);
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
std::string CPUBuilder::getStrategy()
{
	return mStrategy;
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
std::string CPUBuilder::getBank()
{
	std::string bank;
	stringstream ss;

	ss << mcBank;

	bank = ss.str();

	return bank;
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
std::string CPUBuilder::getName()
{
	return mName;
}
