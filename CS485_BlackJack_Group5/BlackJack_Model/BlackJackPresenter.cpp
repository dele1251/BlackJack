//*******************************************************************
// File name:  BlackJackPresenter.cpp
// Author:     Ernesto DeLeon
// Date:	     04/28/17
// Class:      CS485
// Assignment: BlackJack
// Purpose:    Implementation of an BlackJackPresenter
//*******************************************************************
#include "BlackJackPresenter.h"

//***************************************************************************
// Constructor: BlackJackPresenter
//
// Description: Default constructor
//
// Parameters:  none
//
// Returned:    None
//**************************************************************************
BlackJackPresenter::BlackJackPresenter(IBlackJackView * pcView) : mpcBlackJackView(pcView)
{
}

//***************************************************************************
// Method:      
//
// Description:  
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void BlackJackPresenter::P_SetNumPlayer(std::string sNumPlayer)
{
	bool bValidInput;
	int previousValue;
	bValidInput = mcBlackJackModel.M_SetNumHuman(std::stoi(sNumPlayer), previousValue);

	if (bValidInput)
	{
		mpcBlackJackView->V_SetNumPlayer(sNumPlayer);
	}
	else
	{
		mpcBlackJackView->V_SetNumPlayer(to_string(previousValue));
	}
}

//***************************************************************************
// Method:      
//
// Description:  
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void BlackJackPresenter::P_SetNumCPU(std::string sNumCPU)
{
	bool bValidInput;
	int previousValue;
	bValidInput = mcBlackJackModel.M_SetNumCPU(std::stoi(sNumCPU), previousValue);

	if (bValidInput)
	{
		mpcBlackJackView->V_SetNumCPU(sNumCPU);
	}
	else
	{
		mpcBlackJackView->V_SetNumCPU(to_string(previousValue));
	}
}

//***************************************************************************
// Method:      
//
// Description:  
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void BlackJackPresenter::P_SetNumDecks(std::string sNumDecks)
{
	bool bValidInput;
	int previousValue;
	bValidInput = mcBlackJackModel.M_SetNumDeck(std::stoi(sNumDecks), previousValue);

	if (bValidInput)
	{
		mpcBlackJackView->V_SetNumDeck(sNumDecks);
	}
	else
	{
		mpcBlackJackView->V_SetNumPlayer(to_string(previousValue));
	}
}

//***************************************************************************
// Method:      
//
// Description:  
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void BlackJackPresenter::P_SetPlayerName(std::string playerName, std::string playerNewName)
{
	int playerIndex = mcBlackJackModel.M_GetPlayerIndex(playerName);
	mcBlackJackModel.M_SetPlayerName(playerIndex, playerNewName);
	mpcBlackJackView->V_SetPlayerName(playerName, playerNewName);
}

//***************************************************************************
// Method:      
//
// Description:  
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void BlackJackPresenter::P_SetBankAccount(std::string playerName, std::string sAccount)
{
	std::string previousValue;
	int playerIndex = mcBlackJackModel.M_GetPlayerIndex(playerName);

	if (mcBlackJackModel.M_SetBank(playerIndex, stoll(sAccount), previousValue))
	{
		mpcBlackJackView->V_SetBankAccount(playerName, previousValue);
	}
	else
	{
		mpcBlackJackView->V_SetBankAccount(playerName, previousValue);
	}
}

//***************************************************************************
// Method:      
//
// Description:  
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void BlackJackPresenter::P_SetCPUStrategy(std::string CPUName, std::string strategy)
{
	std::string previousValue;
	std::string previousStrategy;

	int playerIndex = mcBlackJackModel.M_GetPlayerIndex(CPUName);

	if (mcBlackJackModel.M_SetCPUStrat(playerIndex, strategy, previousStrategy))
	{
		mpcBlackJackView->V_SetCPUStrat(CPUName, strategy);
	}
	else
	{
		mpcBlackJackView->V_SetCPUStrat(CPUName, previousStrategy);
	}

}

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void BlackJackPresenter::P_StartGame()
{
	mcBlackJackModel.M_StartGame();
}

//***************************************************************************
// Method:      
//
// Description:  
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void BlackJackPresenter::P_Hit()
{
	bool bTwentyOne, bBust;
	bool bCPUTurn = false;
	int playerHandValue = 0;
	std::string sHandRepresentation;
	std::string sCardRepresentation;
	mcBlackJackModel.M_Hit(bCPUTurn, bTwentyOne, bBust, sHandRepresentation, sCardRepresentation);

	mpcBlackJackView->V_Hit(sHandRepresentation, sCardRepresentation);

	if (bBust)
	{
		if (bCPUTurn)
		{
			mpcBlackJackView->V_EndPlayersTurn ();
		}
		else
		{
			mpcBlackJackView->V_EndTurn ();
		}
		
	}
	else if (bTwentyOne)
	{
		if (bCPUTurn)
		{
			mpcBlackJackView->V_EndPlayersTurn ();
		}
		else
		{
			mpcBlackJackView->V_EndTurn ();
		}
	}
	else // turn didn't end
	{

	}

}

//***************************************************************************
// Method:      
//
// Description:  
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void BlackJackPresenter::P_Stay()
{
	bool bCPUTurn = false;
	mcBlackJackModel.M_Stay(bCPUTurn);
	//mpcBlackJackView->V_Stay ();

	if (bCPUTurn)
	{
		mpcBlackJackView->V_EndPlayersTurn();
	}
	else
	{
		mpcBlackJackView->V_EndTurn ();
	}
}

//***************************************************************************
// Method:      
//
// Description:  
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void BlackJackPresenter::P_Split()
{
	bool bCPUTurn = false;

	if (mcBlackJackModel.M_Split())
	{
		// view split

	}
}

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void BlackJackPresenter::P_CPUTurn()
{
	bool bPlayerTurn;
	bool bBlackJack;
	bool bBust;
	std::string hand;
	std::string commands;

	mcBlackJackModel.M_CPUTurn(bPlayerTurn, commands, bBlackJack, bBust, hand);

	if (bPlayerTurn)
	{
		mpcBlackJackView->V_StartTurn(hand);
		P_EndRound();
	}
	else
	{
		mpcBlackJackView->V_StartTurn(hand);
		P_CPUTurn();
	}
}

//***************************************************************************
// Method:      
//
// Description:  
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void BlackJackPresenter::P_StartRound()
{
	std::vector <std::string> cardRepresentation;
	mcBlackJackModel.M_StartRound(cardRepresentation);
	mpcBlackJackView->V_StartRound(cardRepresentation);
}

//***************************************************************************
// Method:      
//
// Description:  
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void BlackJackPresenter::P_EndRound()
{
	std::vector <std::string> bankBalance;
	std::vector <int> bankruptPlayerID;
	std::vector <int> bankruptCPUID;

	mcBlackJackModel.M_EndRound(bankBalance, bankruptPlayerID, bankruptCPUID);
	mpcBlackJackView->V_EndRound(bankBalance, bankruptPlayerID, bankruptCPUID);
} 

//***************************************************************************
// Method:      
//
// Description:  
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void BlackJackPresenter::P_RestartRound()
{
	int numPlayers = 0;
	mcBlackJackModel.M_RestartRound(numPlayers);
	mpcBlackJackView->V_RestartRound(numPlayers);
}

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void BlackJackPresenter::P_StartTurn()
{

	std::string cardRepresentation;
	bool bBlackJack;

	mcBlackJackModel.M_StartTurn(cardRepresentation, bBlackJack);

	if (bBlackJack)
	{
		mpcBlackJackView->V_StartTurn(cardRepresentation);
		mpcBlackJackView->V_EndTurn();
	}
	else
	{
		mpcBlackJackView->V_StartTurn(cardRepresentation);
	}
}

//***************************************************************************
// Method:      
//
// Description:  
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void BlackJackPresenter::P_Quit()
{
	mcBlackJackModel.M_Quit();
}

//***************************************************************************
// Method:      
//
// Description:  
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void BlackJackPresenter::P_Bet(std::string sBet)
{
	std::string moneyBet;

	if (mcBlackJackModel.M_Bet(std::stoi(sBet), moneyBet))
	{
		mpcBlackJackView->V_onSetBet(moneyBet);
	}
	else
	{
		mpcBlackJackView->V_onSetBet("$0.00");
	}

	//std::string previousValue;
	//int playerIndex = mcBlackJackModel.M_GetPlayerIndex(playerName);

	//if (mcBlackJackModel.M_SetBank(playerIndex, stoll(sAccount), previousValue))
	//{
	//	mpcBlackJackView->V_SetBankAccount(playerName, previousValue);
	//}
	//else
	//{
	//	mpcBlackJackView->V_SetBankAccount(playerName, previousValue);
	//}

}

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
void BlackJackPresenter::P_InitializePlayers(vector<std::string> defaultNames, long long defaultBank, std::string defaultStrategy)
{
	mcBlackJackModel.M_InitializePlayers(defaultNames, defaultBank, defaultStrategy);
}

