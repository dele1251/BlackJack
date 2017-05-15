//*******************************************************************
// File name:  BlackJackPresenter.h
// Author:     Ernesto DeLeon
// Date:	     04/28/17
// Class:      CS485
// Assignment: BlackJack
// Purpose:    Definition of an BlackJackPresenter
//*******************************************************************
#pragma once
#include "IBlackJackPresenter.h"
#include "IBlackJackView.h"
#include "BlackJackModel.h"

class BlackJackPresenter : public IBlackJackPresenter
{
	public:

		BlackJackPresenter () = default;
		BlackJackPresenter (IBlackJackView* pcView);
		virtual ~BlackJackPresenter () = default;

		virtual void P_SetNumPlayer (std::string sNumPlayer);
		virtual void P_SetNumCPU (std::string sNumCPU);
		virtual void P_SetNumDecks (std::string sNumdecks);
		virtual void P_SetPlayerName (std::string playerName, std::string playerNewName);
		virtual void P_SetBankAccount (std::string playerName, std::string balance);
		virtual void P_StartGame ();
		virtual void P_Hit ();
		virtual void P_Stay ();
		virtual void P_Split ();
		virtual void P_CPUTurn();
		void P_StartRound();
		virtual void P_EndRound ();
		virtual void P_RestartRound ();
		virtual void P_StartTurn ();
		virtual void P_Quit ();
		virtual void P_Bet (std::string sBet);
		void P_SetCPUStrategy(std::string playerName, std::string strategy);
		virtual void P_InitializePlayers (std::vector<std::string> defaultNames, long long defaultBank, std::string defaultStrategy);

	private:

		IBlackJackView* mpcBlackJackView;
		BlackJackModel mcBlackJackModel;


};