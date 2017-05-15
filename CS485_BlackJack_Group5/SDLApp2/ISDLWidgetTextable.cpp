//****************************************************************************
// File name:	 ISDLWidgetTextable.cpp
// Author:     Chadd Williams
// Date:       4/22/2017
// Class:      CS 485
// Assignment: SDLApp2
// Purpose:    Provider wrapper for SDL
//****************************************************************************

#include "ISDLWidgetTextable.h"

//***************************************************************************
// Function:    setData
//
// Description: Set the data in this widget to the parameter given.
//              Also, carefully handle the generation of a stateChangeEvent()
//
// Parameters:  cData - the data to display
//
// Returned:    None
//***************************************************************************
void ISDLWidgetTextable::setData (std::string cData)
{
  std::string originalData = mData;
  mData = cData;

  // if the data changed
  if (originalData != cData)
  {
    // if we have focus or are in the middle of a change 
    // marke that we changed but don't fire an event
    if (mbStateChangeStarted)
    {
      mbStateChanged = true;
    }
    else
    {
      // we must have called setData() programmatically
      // so fire an event
      stateChangeEvent ();
    }
  }
}

//***************************************************************************
// Function:    setFocus
//
// Description: setFocus to the parameter. 
//              When focus is gained, also set mbStateChangeStarted
//              if we previously did not have focus because now we may
//              get a series of setData()s from text input
//
// Parameters:  bFocus - true if we have focus
//
// Returned:    None
//***************************************************************************
void ISDLWidgetTextable::setFocus (bool bFocus)
{

  if (!mbHasFocus && bFocus)
  {
    mbStateChangeStarted = true;
  }
  else if (!bFocus && mbHasFocus)
  {
    // lost focus, we previously had focus

    if (mbStateChanged)
    {
      // the state changed while we had focus, fire and event
      stateChangeEvent ();
    }
  }

  if (!bFocus)
  {
    // make sure we end the state change if we lose focus
    mbStateChangeStarted = false;
  }

  mbHasFocus = bFocus;
}

//***************************************************************************
// Function:    stateChangeEvent
//
// Description: call the state change handler function
//
// Parameters:  None
//
// Returned:    None
//***************************************************************************

void ISDLWidgetTextable::stateChangeEvent ()
{
  if (nullptr != mcStateChangeHandler)
  {
    mcStateChangeHandler ();
  }
}

//***************************************************************************
// Function:    registerStateChangeEventHandler
//
// Description: set the state change handler function
//
// Parameters:  cFunction - the change handler function
//
// Returned:    None
//***************************************************************************

void ISDLWidgetTextable::registerStateChangeEventHandler (
  std::function<void (void)> cFunction)
{
  mcStateChangeHandler = cFunction;
}