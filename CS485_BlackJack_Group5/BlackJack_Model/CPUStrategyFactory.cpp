//*******************************************************************
// File name:  CPUStrategyFactory.cpp
// Author:     Michael Sakai
// Date:	     05/01/17
// Class:      CS485
// Assignment: 05_Group
// Purpose:    impliment the CPUStrategyFacory
//*******************************************************************
#include "CPUStrategyFactory.h"

const std::string CPUStrategyFactory::CHEATER = "CHEATER";
const std::string CPUStrategyFactory::TRUE_DEALER = "True Dealer";
const std::string CPUStrategyFactory::DEALER = "DEALER";
const std::string CPUStrategyFactory::NORMAL = "NORMAL";

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
bool CPUStrategyFactory::validInput(std::string input)
{
	bool bValidInput = false;

	if (input == CHEATER || input == TRUE_DEALER || input == DEALER || input == NORMAL)
	{
		bValidInput = true;
	}

	return bValidInput;
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
IPlayStrategy* CPUStrategyFactory::makeStrategy(Player *pcPlayer, std::string strategy, BlackJackDeck *pcDeck)
{
	IPlayStrategy *pcStrategy;

	if (strategy == CHEATER)
	{
		pcStrategy = new CounterStrategy(pcPlayer, pcDeck);
	}
	else if (strategy == TRUE_DEALER)
	{
		pcStrategy = new DealerStrategy(pcPlayer, pcDeck);
	}
	else if (strategy == DEALER)
	{
		pcStrategy = new DealerStrategy(pcPlayer, pcDeck, false);
	}
	else
	{
		pcStrategy = new NormalStrategy(pcPlayer, pcDeck);
	}

	return pcStrategy;
}