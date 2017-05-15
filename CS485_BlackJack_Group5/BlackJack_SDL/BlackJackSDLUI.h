#pragma once

#include "IBlackJackUI.h"

class BlackJackSDLUI : public IBlackJackUI
{
	void onSetNumPlayer(std::string numPLayer);
	void onSetNumCPU(std::string numCPU);
	void onSetNumDeck(std::string numDeck);
	void onSetPlayerName(std::string command);
	void onSetBankAccount(std::string command);
	void onSetCPUStrat(std::string command);
	void onClickHit(std::string commands);
  void onClickStay(std::string commands);
  void onClickSplit(std::string commands);

};