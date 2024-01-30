#pragma once
#include "ui_manager.h"

class ScoreManager
{
public:
	ScoreManager(UIManager* ui);
	void IncreaseScore(int delta);
	int score = 0;
	UIManager* uiManager;
};

