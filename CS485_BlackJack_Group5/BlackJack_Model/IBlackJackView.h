//*******************************************************************
// File name:  IBlackJackView.h
// Author:     Ernesto DeLeon
// Date:	     04/28/17
// Class:      CS485
// Assignment: BlackJack
// Purpose:    Definition of an IBlackJackView
//*******************************************************************
#pragma once
#include <iostream>

class IBlackJackView
{
  public:
    virtual ~IBlackJackView () {};

    virtual void V_SetNumPlayer (std::string numPlayer) = 0;
    virtual void V_SetNumCPU (std::string numCPU) = 0;
    virtual void V_SetNumDeck (std::string numDeck) = 0;
    virtual void V_SetPlayerName (std::string playerName, std::string playerNewName) = 0;
    virtual void V_SetBankAccount (std::string playerName, std::string amount) = 0;
    virtual void V_SetCPUStrat (std::string playerName, std::string CPUStrat) = 0;
    virtual void V_onSetBet (std::string amount) = 0;
    virtual void V_Hit (std::string handRepresentation, std::string cardRepresentatio) = 0;
    virtual void V_Stay () = 0;
    virtual void V_Split () = 0;
    virtual void V_StartRound (std::vector<std::string> cardRepresentation) = 0;
		virtual void V_StartTurn (std::string cardRepresentation) = 0;
		virtual void V_EndTurn() = 0;
    virtual void V_EndRound (std::vector<std::string> bankBalance, std::vector <int> bankruptPlayerID, std::vector <int> bankruptCPUID) = 0;
    virtual void V_CPUStartTurn (std::string cardRepresentation) = 0;
    virtual void V_EndPlayersTurn () = 0;
    virtual void V_RestartRound (int &numPlayer) = 0;

    virtual void redrawUI () = 0;

};