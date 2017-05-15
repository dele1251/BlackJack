//****************************************************************************
// File name:		BlackJackView_SDL.h
// Author:			Kyle Pestka
// Date:				5/1/2017
// Class:				CS485
// Assignment:	BlackJack_Group5
// Purpose:			Contains the object data for a BlackJackView_SDL
//**************************************************************************** 
#pragma once

#include <string>
#include <vector>
#include "IBlackJackView.h"
#include "SDLApp.h"
#include "BlackJackPresenter.h"
#include "ISDLWidget.h"
#include "SDLSelectionButton.h"
#include "IBlackJackUI.h"
#include "SDLTextWidget.h"



class BlackJackView_SDL : public IBlackJackView, public IBlackJackUI, public SDLApp
{
  public:
   
    BlackJackView_SDL ();
    virtual ~BlackJackView_SDL ();

    void handleEvent (SDL_Event event);
    void render ();
    void initGame ();
    void update ();

    // Events From UI Widgets
    virtual void onSetNumPlayerWidget (SDLTextWidget *pcWidget);
    virtual void onSetNumCPUWidget (SDLTextWidget *pcWidget);
    virtual void onSetNumDeckWidget (SDLTextWidget *pcWidget);
    virtual void onSetPlayerNameWidget (SDLTextWidget *pcWidget) {};
    virtual void onSetBankAccountWidget (SDLTextWidget *pcWidget) {};
    virtual void onClickHitWidget (SDLTextWidget *pcWidget) {};
    virtual void onClickStayWidget (SDLTextWidget *pcWidget) {};
    virtual void onClickSplitWidget (SDLTextWidget *pcWidget) {};
    /*virtual void onStartRoundWidget (SDLTextWidget *pcWidget);*/
    virtual void onEndRoundWidget (SDLTextWidget *pcWidget) {};
    virtual void onRestartRound (SDLTextWidget *pcWidget) {};
    virtual void onBetWidget (SDLTextWidget *pcWidget) {};
    virtual void onQuitWidget (SDLTextWidget *pcWidget) {};

    // Event From UI
    virtual void onSetNumPlayer (std::string numPlayer);
    virtual void onSetNumCPU (std::string numCPU);
    virtual void onSetNumDeck (std::string numDeck);
    virtual void onSetPlayerName (std::string playerName) {};
    virtual void onSetBankAccount (std::string bankAmount) {};
    virtual void onSetCPUStrat (std::string command) {};
    virtual void onStartGame () {};
    virtual void onSetBet (std::string command) {};
    virtual void onRunCPUBets (std::string commands) {};
    virtual void onRunCPUCommands () {};
    virtual void onClickHit (std::string commands) {};
    virtual void onClickStay (std::string commands) {};
    virtual void onClickSplit (std::string commands) {};
    /*virtual void onStartRound ();*/
    virtual void onEndRound () {};
    virtual void onRestartRound () {};
    virtual void onBet (std::string bet) {};
    virtual void onQuit () {};

    // Events From Presenter
    virtual void V_SetNumPlayer (std::string numPlayer);
    virtual void V_SetNumCPU (std::string numCPU);
    virtual void V_SetNumDeck (std::string numDeck);
    virtual void V_SetPlayerName (std::string playerName, std::string amount) {};
    virtual void V_SetBankAccount (std::string playerName, std::string CPUStrat) {};
    virtual void V_SetCPUStrat (std::string playerName, std::string CPUStrat) {};
    virtual void V_onSetBet (std::string amount) {};
    virtual void V_Hit (std::string handRepresentation, std::string cardRepresentatio) {};
    virtual void V_Stay () {};
    virtual void V_Split () {};
    virtual void V_StartRound (std::vector<std::string> cardRepresentation) {};
    virtual void V_EndRound (std::vector<std::string> bankBalance, std::vector <int> bankruptPlayerID, std::vector <int> bankruptCPUID) {};
    virtual void V_RestartRound (int &numPlayer) {};
		virtual void V_StartTurn (std::string cardRepresentation) {};
    virtual void V_CPUStartTurn (std::string cardRepresentation) {};
		virtual void V_EndTurn() {}
    virtual void V_EndPlayersTurn () {};




    virtual void redrawUI () {};

  private:
    BlackJackPresenter *mpcPresenter;
    std::vector<ISDLWidget*> mcDrawableWidget;
    std::vector<SDLTextWidget*> mcPlayerName;
    std::vector<SDLTextWidget*> mcPlayerBank;



		SDLSelectionButton *mcHit;
		SDLSelectionButton *mcStay;
		SDLSelectionButton *mcSplit;

		SDLSelectionButton *mcNext_Num_Player;
		SDLSelectionButton *mcNext_Set_Bank;
		SDLSelectionButton *mcNext_Strategy;

    SDLTextWidget *mcBet;
		SDLTextWidget mcNumPlayer;
		SDLTextWidget mcNumCPU;
		SDLTextWidget mcNumDecks;

    bool mbCPUTurn;
    bool mbStartOfTurn;
    bool mbAutoEndTurn;
    
    //SDLTableView mcSDLTableView;
};