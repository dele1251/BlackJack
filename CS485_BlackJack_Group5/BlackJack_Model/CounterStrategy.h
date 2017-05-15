//*****************************************************************************
// File name:  CoutnerStrategy.h
// Author:     Ernesto DeLeon
// Date:	     05/4/17
// Class:      CS485
// Assignment: BlackJack
// Purpose:    Definition of a CPU card counting strategy
//*****************************************************************************
#pragma once
#include "IPlayStrategy.h"
#include "Player.h"
#include "Deck.h"
#include <unordered_map>
#include <fstream>
#include "NormalStrategy.h"

class CounterStrategy : public NormalStrategy
{
  public:

    CounterStrategy (Player* pcPlayer, BlackJackDeck* pcDeck);
    virtual ~CounterStrategy ();
    virtual void executeTurn (std::string &rCommand, bool &bBlackJack, bool &bBust, std::string &Hand);
    virtual void executeBet ();

  private:

    std::unordered_map <std::string, int> mTable;   
};