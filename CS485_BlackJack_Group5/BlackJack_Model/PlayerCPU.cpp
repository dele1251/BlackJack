//*****************************************************************************
// File name:  PlayerCPU.cpp
// Author:     Ernesto DeLeon
// Date:	     05/4/17
// Class:      CS485
// Assignment: BlackJack
// Purpose:    implementation of a CPU player
//*****************************************************************************
#include "PlayerCPU.h"
#include "DealerStrategy.h"
#include "CounterStrategy.h"
#include "NormalStrategy.h"

//*****************************************************************************
// Constructor: PlayerCPU
//
// Description: Constructor for the CPU player takes a deck pointer for the
//              strategy and takes an integer to determine the strategy type
//
// Parameters:  pcDeck       - a pointer to the deck
//              strategyType - an integer that determines the strategy type
//
// Returned:    none
//*****************************************************************************
PlayerCPU::PlayerCPU(std::string name, Money cMoney, std::string strategy, BlackJackDeck *pcDeck) : Player(name, cMoney)
{
	mpcStrategy = mcStratFactory.makeStrategy(this, strategy, pcDeck); 
}

//*****************************************************************************
// Destructor:  ~PlayerCPU
//
// Description: deletes the strategy and sets the pointer to nullptr
//
// Parameters:  none
//
// Returned:    none
//*****************************************************************************
PlayerCPU::~PlayerCPU ()
{
	delete mpcStrategy;
	mpcStrategy = nullptr;
}

//*****************************************************************************
// Method:      makeMove
//
// Description: calls on the strategy to take the player's turn
//
// Parameters:  none
//
// Returned:    none
//*****************************************************************************
void PlayerCPU::makeMove (std::string &rCommand, bool &bBlackJack, bool &bBust, std::string &rHand)
{
	mpcStrategy->executeTurn (rCommand, bBlackJack, bBust, rHand);
}

//*****************************************************************************
// Method:      makeBet
//
// Description: calls on the strategy to make the players bet
//
// Parameters:  none
//
// Returned:    none
//*****************************************************************************
void PlayerCPU::makeBet ()
{
	mpcStrategy->executeBet ();
}