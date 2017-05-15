#include "SDLSelectionButton.h"

SDLSelectionButton::SDLSelectionButton(std::string label, int x, int y, int font, Color cColor)
{
	mLabel = label; 
	mX = x; 
	mY = y; 
	mFont = font; 
	mcColor = cColor;
}


void SDLSelectionButton::draw(SDLApp &rcApp)
{
	rcApp.setColor(Color(255, 255, 255, 255));
	rcApp.displayTextClickable(mX, mY, mLabel, mcColor, mFont, mWidth, mHeight);
	rcApp.drawLine(mX, mY + mHeight, mX + mWidth, mY + mHeight);
  rcApp.drawLine (mX, mY, mX + mWidth, mY);
  rcApp.drawLine (mX, mY + mHeight, mX, mY);
  rcApp.drawLine (mX + mWidth, mY, mX + mWidth, mY + mHeight);
}

int SDLSelectionButton::getLength() const
{
  return mLabel.size();
}

bool SDLSelectionButton::clicked(int x, int y)
{
  bool clicked = false;
  if (x >= mX && x <= mX + mWidth &&
    y >= mY && y <= mY + mHeight)
  {
    clicked = true;
  }

  return clicked;
}