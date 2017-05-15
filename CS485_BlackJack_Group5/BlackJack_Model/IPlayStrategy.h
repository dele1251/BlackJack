//*****************************************************************************
// File name:  IPlayStrategy.h
// Author:     Ernesto DeLeon
// Date:	     05/4/17
// Class:      CS485
// Assignment: BlackJack
// Purpose:    Definition of a CPU play strategy abstract class
//*****************************************************************************
#pragma once
#include <iostream>

class IPlayStrategy
{
  public:

    static const int NUM_PLAYS = 12;
    static const int STAY_LIMIT = 17;
    static const int HAND_ONE = 0;
    static const int HAND_TWO = 1;

    virtual ~IPlayStrategy () {};
    virtual void executeTurn (std::string &rCommand, bool &bBlackJack, bool &bBust, std::string &Hand) = 0;
    virtual void executeBet () = 0;
};