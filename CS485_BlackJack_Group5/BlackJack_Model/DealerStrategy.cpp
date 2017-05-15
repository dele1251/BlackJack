//*****************************************************************************
// File name:  DealerStrategy.cpp
// Author:     Ernesto DeLeon
// Date:	     05/4/17
// Class:      CS485
// Assignment: BlackJack
// Purpose:    implementation of a Dealer strategy
//*****************************************************************************
#include "DealerStrategy.h"

//*****************************************************************************
// Constructor: DealerStrategy
//
// Description: Sets the player pointer, deck pointer, and the boolean that
//              dictates whether or not this strategy is the true dealer for
//              betting purposes
//
// Parameters:  pcPlayer  - a pointer to a player
//              pcDeck    - a pointer to the deck
//              bIsDealer - defaults to true if the arguement is empty
//
// Returned:    none
//*****************************************************************************
DealerStrategy::DealerStrategy (Player* pcPlayer, BlackJackDeck* pcDeck,
  bool bIsDealer) 
  : mbRealDealer ( bIsDealer), mpcPlayer (pcPlayer), mpcDeck (pcDeck)
{
}

//*****************************************************************************
// Destructor:  ~DealerStrategy
//
// Description: destructor that sets the pointers to nullptr
//
// Parameters:  none
//
// Returned:    none
//*****************************************************************************
DealerStrategy::~DealerStrategy ()
{
  mpcDeck = nullptr;
  mpcPlayer = nullptr;
}

//*****************************************************************************
// Method:      executeTurn
//
// Description: the dealer hits until the hand value is 17 and never splits
//
// Parameters:  none
//
// Returned:    none
//*****************************************************************************
void DealerStrategy::executeTurn (std::string &rCommand, bool &bBlackJack,
  bool &bBust, std::string &Hand)
{
	bool bEndTurn;

  while (*mpcPlayer < STAY_LIMIT)
  {
    mpcPlayer->hitHand (mpcDeck->drawCard (), bBlackJack, bBust);
		rCommand.append("Hit ");
  }

	if (!bBust && !bBlackJack)
	{
		mpcPlayer->stand(bEndTurn);
		rCommand.append("Stay ");
	}


}

//*****************************************************************************
// Method:      executeBet
//
// Description: if the strategy is not the true dealer, 1/5 of the bankRoll is
//              bet
//
// Parameters:  none
//
// Returned:    none
//*****************************************************************************
void DealerStrategy::executeBet ()
{
  double oneFifth = 0.2;

  if (false == mbRealDealer)
  {
    mpcPlayer->makeBet (mpcPlayer->getBankRoll () * oneFifth);
  }
}