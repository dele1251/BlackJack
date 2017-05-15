//****************************************************************************
// File name:		BlackJackView_TextUI.h
// Author:			Kyle Pestka
// Date:				5/1/2017
// Class:				CS485
// Assignment:	BlackJack_Group5
// Purpose:			Contains the object data for a BlackJackView_TextUI
//**************************************************************************** 
#pragma once
#include "IBlackJackPresenter.h"
#include <string>
#include <sstream>
#include <vector>
#include "TextUI.h"
#include "TextUITextWidget.h"
#include "IBlackJackUI.h"
#include "IBlackJackView.h"


class BlackJackView_TextUI : public IBlackJackView, public IBlackJackUI, public TextUI
{
	public:
		static const long long DEFAULT_BANK = 100000;
		static const std::string DEFAULT_STRATEGY;

		BlackJackView_TextUI ();
		virtual ~BlackJackView_TextUI ();
		//Personal TextView Functions
		void onPlay (std::string command);
		void onNextNames (std::string command);
		void onStartBets (std::string command);
		void onStartRound (std::string command);
		void onNetRound (std::string command);
		void onTestRound (std::string command);

		// From UI events to Presenter
		virtual void onSetNumPlayer (std::string numPLayer);
		virtual void onSetNumCPU (std::string numCPU);
		virtual void onSetNumDeck (std::string numDeck);
		virtual void onSetPlayerName (std::string command);
		virtual void onSetBankAccount (std::string command);
		virtual void onSetCPUStrat (std::string command);
		virtual void onStartGame ();
		virtual void onSetBet (std::string command);
		virtual void onRunCPUBets (std::string commands) {};
		virtual void onRunCPUCommands ();
		virtual void onClickHit (std::string commands);
		virtual void onClickStay (std::string commands);
		virtual void onClickSplit (std::string commands);
		// onSetCPUstrat

		// From Presenter to View
		virtual void V_SetNumPlayer (std::string numPlayer);
		virtual void V_SetNumCPU (std::string numCPU);
		virtual void V_SetNumDeck (std::string numDeck);
		virtual void V_SetPlayerName (std::string playerName, std::string playerNewName);
		virtual void V_SetBankAccount (std::string playerName, std::string amount);
		virtual void V_SetCPUStrat (std::string playerName, std::string CPUStrat);
		virtual void V_onSetBet (std::string bet);
		virtual void V_StartRound (std::vector<std::string> cardRepresentation);
		virtual void V_Hit (std::string handRepresentation, std::string cardRepresentation);
		virtual void V_Stay ();
		virtual void V_Split () {};
		virtual void V_EndRound (std::vector<std::string> bankBalance, std::vector <int> bankruptPlayerID, std::vector <int> bankruptCPUID);
		virtual void V_RestartRound (int &numPlayer) {};
		virtual void V_StartTurn (std::string cardRepresentation);
		virtual void V_CPUStartTurn (std::string cardRepresentation) {};
		virtual void V_EndTurn();
		virtual void V_EndPlayersTurn ();
		//V_SetCPUStrat

	private:
		virtual void redrawUI ();

		IBlackJackPresenter* mpcBlackJackPresenter;

		TextUITextWidget *mpGameTitle;

		TextUITextWidget *mpNumPlayers;
		TextUITextWidget *mpNumCPUs;
		TextUITextWidget *mpNumDecks;

		TextUITextWidget *mpCurrentBetter;

		TextUITextWidget *mpCards[6];
		TextUITextWidget *mpPlayersNames[5];
		TextUITextWidget *mpCPUStrats[5];
		TextUITextWidget *mpBets[5];
		TextUITextWidget *mpDealerID;
};
