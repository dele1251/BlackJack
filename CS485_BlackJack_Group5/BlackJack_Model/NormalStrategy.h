//*****************************************************************************
// File name:  NormalStrategy.h
// Author:     Ernesto DeLeon
// Date:	     05/4/17
// Class:      CS485
// Assignment: BlackJack
// Purpose:    Definition of a normal play strategy
//*****************************************************************************
#pragma once
#include <iostream>
#include "IPlayStrategy.h"
#include "Player.h"
#include "BlackJackDeck.h"
#include <unordered_map>
#include <vector>

class NormalStrategy : public IPlayStrategy
{
  public:

    static const int FIRST_CARD = 0;
    static const int SECOND_CARD = 1;
    NormalStrategy (Player* pcPlayer, BlackJackDeck* pcDeck);
    virtual ~NormalStrategy ();
    virtual void executeTurn (std::string &rCommand, bool &bBlackJack, bool &bBust, std::string &Hand);
    virtual void executeBet ();

  protected:

    Player* mpcPlayer;
    BlackJackDeck* mpcDeck;
    std::vector <std::pair <std::string, std::vector<char>>> 
      mPairSplittingTable;
    std::vector<std::pair <std::string, std::vector<char>>> mSoftDecisions;
    std::vector <std::pair <std::string, std::vector<char>>> mHardDecisions;
    std::fstream mInFile;
    int mDealersUpCardValue;
    Money mcBet;
    void playPairHand ();
    void playSoftHand (int whichHand);
    void playHardHand (int whichHand);    
};
