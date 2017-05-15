//****************************************************************************
// File name:		BlackJack_TextUIDriver.cpp
// Author:			Kyle Pestka
// Date:				5/1/2017
// Class:				CS485
// Assignment:	BlackJack_Group5
// Purpose:			Driver for the BlackJack_TextUI
//**************************************************************************** 
#include <iostream>
#include <chrono>
#include <thread>
#include "BlackJackView_TextUI.h"

//***************************************************************************
// Function:    main
//
// Description: Launches the TextUI
//
// Parameters:  None
//
// Returned:    EXIT_SUCCESS
//***************************************************************************
int main ()
{
  BlackJackView_TextUI cView;

  cView.UIEventLoop ();

  return EXIT_SUCCESS;
}