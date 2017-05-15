//****************************************************************************
// File name:		BlackJack_SDLDriver.cpp
// Author:			Kyle Pestka
// Date:				5/1/2017
// Class:				CS485
// Assignment:	BlackJack_Group5
// Purpose:			Driver for the BlackJack_TextUI
//****************************************************************************
#include <fstream>
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
int main (int argc, char *argv[])
{
  BlackJackView_SDL cTheDisply;

  cTheDisply.createWindow ("BlackJackSDL", 100, 100, 1000, 1000);

  cTheDisply.setWindowBackgroundColor ({ 0, 0, 255, 255 });
  
  cTheDisply.gameLoop ();

  cTheDisply.cleanup ();

  return EXIT_SUCCESS;
}