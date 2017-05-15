//*****************************************************************************
// File name:  DealerStrategy.h
// Author:     Ernesto DeLeon
// Date:	     04/28/17
// Class:      CS485
// Assignment: BlackJack
// Purpose:    Definition of a dealers play strategy
//*****************************************************************************
#pragma once
#include "IPlayStrategy.h"
#include "Player.h"
#include "BlackJackDeck.h"

class DealerStrategy : public IPlayStrategy
{
  public :

    DealerStrategy (Player* pcPlayer, BlackJackDeck* pcDeck, bool isDealer = true);
    ~DealerStrategy ();
    void executeTurn (std::string &rCommand, bool &bBlackJack, bool &bBust, std::string &Hand);
    void executeBet ();

  private:

    bool mbRealDealer;
    Player *mpcPlayer;
    BlackJackDeck *mpcDeck;
};