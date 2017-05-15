//*******************************************************************
// File name:  PlayerBuilder.h
// Author:     Michael Sakai
// Date:	     05/01/17
// Class:      CS485
// Assignment: 05_Group
// Purpose:    Define the PlayerBuilder
//*******************************************************************
#pragma once
#include "Player.h"

class PlayerBuilder
{
public:
	void buildName (std::string name);
	void buildBank (Money cBank);
	Player createPlayer ();

	std::string getName();
	std::string getBank();

private:
	std::string mName; 
	Money mcBank; 
};
