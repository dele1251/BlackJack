//*******************************************************************
// File name:  BlackJackModel.h
// Author:     Josh Napoles / Michael Sakai
// Date:	     05/01/17
// Class:      CS485
// Assignment: 05_Group
// Purpose:    Define the BlackJackModel
//*******************************************************************
#pragma once
#include <iostream>
#include <vector>
#include <string>

#include "BlackJackDeck.h"
#include "Player.h"
#include "PlayerBuilder.h"
#include "CPUBuilder.h"

class BlackJackModel
{
public:
	BlackJackModel () = default;
	~BlackJackModel () = default;
	bool M_SetNumHuman (int, int &prevValue);
	bool M_SetNumCPU (int, int &prevValue);
	bool M_SetNumDeck (int, int &prevValue);
	bool M_SetBet (int playerID, long long amount);

	void M_InitializePlayers (std::vector <std::string> defaultNames, long long defautBank, std::string defaultStrategy);

	void M_SetPlayerName(int, std::string);
	bool M_SetCPUStrat(int playerID, std::string, std::string &previousStrategy);
	bool M_SetBank (int, long long amount, std::string &prevValue);
	void M_StartGame();
	void M_StartTurn (std::string &cardRepresentation, bool &bBlackJack);

	void M_Hit (bool &bCPUTurn, bool &bBlackJack, bool &bBust, std::string &HandRepresentation, std::string &cardRepresentation);
	void M_Stay (bool &bCPUTurn);
	bool M_Split ();
	void M_CPUTurn(bool &bPlayerTurn, std::string &rCommand, bool &bBlackJack, bool &bBust, std::string &Hand);
	void M_StartRound (std::vector<std::string> &cardRepresentation);
	void M_EndRound (std::vector<std::string> &bankBalance, std::vector <int> &bankruptplayerID, std::vector <int> &bankruptCPUID);
	void M_RestartRound (int &numPlayer);
	void M_Quit ();
	bool M_Bet (long long, std::string &moneyBet);



	void resetTable();
	void takeCPUTurn();

	void compareAgainstDealer();
	void incrementPlayerTurn();
	void incrementCPUTurn();
	int  M_GetPlayerIndex (std::string);

private:
	static const int MAX_PLAYERS = 5;
	BlackJackDeck mcTheDeck;
	std::vector<Player> mcaPlayer;
	std::vector<PlayerCPU*> mcaCPU;
	std::vector<PlayerBuilder> mcaPlayerBuilder;
	std::vector <CPUBuilder> mcaCPUBuilder;
	int mPlayersTurn = 0;
	int mCPUTurn = 0;
	int mNumHuman;
	int mNumCPU;
	int mTotalPlayers;
	int mNumberOfDecks;
	bool bCPUMadeBet = false;
};
