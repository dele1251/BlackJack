//****************************************************************************
// File name:		BlackJackView_SDL.cpp
// Author:			Kyle Pestka
// Date:				5/1/2017
// Class:				CS485
// Assignment:	BlackJack_Group5
// Purpose:			Contains the object data for a BlackJackView_SDL
//**************************************************************************** 
#include "BlackJackView_SDL.h"

//***************************************************************************
// Function:		
//
// Description: 
//
// Parameters:  
//
// Returned:    
//***************************************************************************
BlackJackView_SDL::BlackJackView_SDL() 
: mcNumPlayer ("Number of Players", "0", 500, 200, 1, Color (255, 255, 255, 255)), 
mcNumCPU ("Number of CPU", "0", 500, 300, 1, Color (255, 255, 255, 255)),
mcNumDecks ("Number of Decks", "0", 500, 400, 1, Color (255, 255, 255, 255))
{
	mpcPresenter = new BlackJackPresenter (this);
	loadFont ("c:/Windows/Fonts/Cour.ttf", 20);
	mpcPresenter->P_SetNumPlayer ("1");
	mpcPresenter->P_SetNumCPU ("0");
	mpcPresenter->P_SetNumDecks ("1");

	/*mcNumPlayer = new SDLTextWidget("Number of Players", "0", 500, 200, 1, Color(255, 255, 255, 255));
	mcNumCPU = new SDLTextWidget("Number of CPU", "0", 500, 300, 1, Color(255, 255, 255, 255));
	mcNumDecks = new SDLTextWidget("Number of Decks", "0", 500, 400, 1, Color(255, 255, 255, 255));*/
	mcNext_Num_Player = new SDLSelectionButton("Next", 500, 800, 1, Color(255, 255, 255, 255));

	mcNumPlayer.registerStateChangeEventHandler (std::bind (&BlackJackView_SDL::onSetNumPlayerWidget, this, &mcNumPlayer));

	





	enableTextInput ();

	registerTextWidget(&mcNumPlayer);
	registerTextWidget(&mcNumCPU);
	registerTextWidget(&mcNumDecks);
	registerClickableWidget(mcNext_Num_Player);


	mcDrawableWidget.push_back(&mcNumPlayer);
	mcDrawableWidget.push_back(&mcNumCPU);
	mcDrawableWidget.push_back(&mcNumDecks);
	mcDrawableWidget.push_back(mcNext_Num_Player);
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
BlackJackView_SDL::~BlackJackView_SDL()
{

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
void BlackJackView_SDL::handleEvent(SDL_Event event)
{

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
void BlackJackView_SDL::render()
{
	for (auto item : mcDrawableWidget)
	{
		item->draw(*this);
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
void BlackJackView_SDL::initGame()
{

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
void BlackJackView_SDL::update()
{

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
void BlackJackView_SDL::onSetNumPlayerWidget (SDLTextWidget * pcWidget)
{
	onSetNumPlayer (pcWidget->getData ());
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
void BlackJackView_SDL::onSetNumCPUWidget (SDLTextWidget * pcWidget)
{
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
void BlackJackView_SDL::onSetNumDeckWidget (SDLTextWidget * pcWidget)
{
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
void BlackJackView_SDL::onSetNumPlayer (std::string numPlayer)
{
	mpcPresenter->P_SetNumPlayer (numPlayer);
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
void BlackJackView_SDL::onSetNumCPU (std::string numCPU)
{
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
void BlackJackView_SDL::onSetNumDeck (std::string numDeck)
{
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
void BlackJackView_SDL::V_SetNumPlayer (std::string numPlayer)
{
	mcNumPlayer.setData (numPlayer);
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
void BlackJackView_SDL::V_SetNumCPU (std::string numCPU)
{
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
void BlackJackView_SDL::V_SetNumDeck (std::string numDeck)
{
}



