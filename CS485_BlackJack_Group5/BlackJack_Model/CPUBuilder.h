//*******************************************************************
// File name:  CPUBuilder.h
// Author:     Michael Sakai
// Date:	     05/01/17
// Class:      CS485
// Assignment: 05_Group
// Purpose:    Define the CPUBuilder
//*******************************************************************
#pragma once
#include "PlayerCPU.h"

class CPUBuilder 
{
public:
	void buildName (std::string name);
	void buildBank (Money cBank);
	bool buildStrategy (std::string strategy);
	void buildDeck (BlackJackDeck *pcDeck);
	PlayerCPU* createPlayer ();
	std::string getName();

	std::string getBank();
	std::string getStrategy();

private:
	std::string mName;
	Money mcBank;
	std::string mStrategy;
	BlackJackDeck *mpcDeck;
};