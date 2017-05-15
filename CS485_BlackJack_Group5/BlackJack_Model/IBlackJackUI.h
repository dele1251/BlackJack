//*******************************************************************
// File name:  IBlackJackUI
// Author:     Michael Sakai / Kyle Pestka
// Date:	     05/01/17
// Class:      CS485
// Assignment: 05_Group
// Purpose:    Define the IBlackJackUI
//*******************************************************************
#pragma once
#include <iostream>
#include <string>

class IBlackJackUI
{
  public:

    virtual void onSetNumPlayer (std::string numPLayer) = 0;
    virtual void onSetNumCPU (std::string numCPU) = 0;
    virtual void onSetNumDeck (std::string numDeck) = 0;
    virtual void onSetPlayerName (std::string command) = 0;
    virtual void onSetBankAccount (std::string command) = 0;
    virtual void onSetCPUStrat (std::string command) = 0;
    virtual void onStartGame () = 0;
    virtual void onSetBet (std::string command) = 0;
    virtual void onRunCPUBets (std::string commands) = 0;
    virtual void onRunCPUCommands () = 0;
    virtual void onClickHit (std::string commands) = 0;
    virtual void onClickStay (std::string commands) = 0;
    virtual void onClickSplit (std::string commands) = 0;


};