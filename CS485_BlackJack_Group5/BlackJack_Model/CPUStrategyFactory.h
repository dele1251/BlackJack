//*******************************************************************
// File name:  CPUStrategyFactory.h
// Author:     Michael Sakai
// Date:	     05/01/17
// Class:      CS485
// Assignment: 05_Group
// Purpose:    Define the CPUStrategyFacory
//*******************************************************************
#pragma once

#include "CounterStrategy.h"
#include "DealerStrategy.h"
#include "NormalStrategy.h"
#include "IPlayStrategy.h"


class CPUStrategyFactory
{
public:
	static const std::string CHEATER;
	static const std::string TRUE_DEALER; 
	static const std::string DEALER;
	static const std::string NORMAL;
	
	static bool validInput(std::string input);
	IPlayStrategy* makeStrategy(Player *pcPlayer, std::string, BlackJackDeck *pcDeck);
};
