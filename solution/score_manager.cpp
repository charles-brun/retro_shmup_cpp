#include "score_manager.h"

ScoreManager::ScoreManager(UIManager* ui) : uiManager(ui)
{

}

void ScoreManager::IncreaseScore(int delta)
{
	score += delta;
	uiManager->UpdateScore(score);
}
