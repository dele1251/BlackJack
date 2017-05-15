//*****************************************************************************
// File name:  PlayerCPU.h
// Author:     Ernesto DeLeon
// Date:	   05/4/17
// Class:      CS485
// Assignment: BlackJack
// Purpose:    Definition of a CPU player
//*****************************************************************************
#pragma once
#include <iostream>
#include "Player.h"
#include "IPlayStrategy.h"
#include "BlackJackDeck.h"
#include "CPUStrategyFactory.h"

class PlayerCPU : public Player
{
  public:    
		PlayerCPU (std::string name, Money cMoney, std::string strategy, BlackJackDeck *pcDeck);
    virtual ~PlayerCPU ();
    void makeMove (std::string &rCommand, bool &bBlackJack, bool &bBust, std::string &Hand);
    void makeBet ();

  private:
		enum mPlayerType { TRUE_DEALER, DEALER, COUNTER, NORMAL};
		IPlayStrategy* mpcStrategy;
		CPUStrategyFactory mcStratFactory;
};