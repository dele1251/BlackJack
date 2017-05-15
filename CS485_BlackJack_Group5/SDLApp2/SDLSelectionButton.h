#pragma once

#include "Color.h"
#include "ISDLWidget.h"
#include "ISDLWidgetClickable.h"

class SDLSelectionButton : public ISDLWidget, public ISDLWidgetClickable
{
public: 
  SDLSelectionButton(std::string label, int x, int y, int font, Color cColor);
  ~SDLSelectionButton() = default;

  void draw(SDLApp &rcApp);
  int getLength() const; 
  bool clicked(int x, int y);
private:
  int mX; 
  int mY; 
  int mHeight = 0; 
  int mWidth = 0; 
  std::string mLabel; 
  Color mcColor; 
	int mFont;
};
