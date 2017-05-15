//*******************************************************************
// File name:  IPresenter.h
// Author:     Ernesto DeLeon
// Date:	     04/28/17
// Class:      CS485
// Assignment: BlackJack
// Purpose:    Definition of an IPresenter
//*******************************************************************
#pragma once
#include <iostream>
#include <string>
#include <vector>

class IBlackJackPresenter
{
	public:
		
		virtual ~IBlackJackPresenter () {};
		virtual void P_SetNumPlayer (std::string sNumPlayer) = 0;
		virtual void P_SetNumCPU (std::string sNumCPU) = 0;
		virtual void P_SetNumDecks (std::string sNumdecks) = 0;
		virtual void P_SetPlayerName (std::string playerName, std::string playerNewName) = 0;
		virtual void P_SetBankAccount (std::string playerName, std::string sAccount) = 0;
		virtual void P_StartGame () = 0;
		virtual void P_Hit () = 0;
		virtual void P_Stay () = 0;
		virtual void P_Split () = 0;
		virtual void P_CPUTurn() = 0;
		virtual void P_StartRound() = 0;
		virtual void P_EndRound () = 0;
		virtual void P_RestartRound () = 0;
		virtual void P_StartTurn() = 0;
		virtual void P_Quit () = 0;
		virtual void P_Bet (std::string sBet) = 0;
		virtual void P_InitializePlayers (std::vector<std::string> defaultNames, long long defaultAmount, std::string defaultStrategy) = 0;
		virtual void P_SetCPUStrategy (std::string playerName, std::string strategy) = 0;
};