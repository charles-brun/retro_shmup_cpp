#include "score_manager.h"

ScoreManager::ScoreManager(UIManager* ui) : uiManager(ui)
{

}

void ScoreManager::UpdateLives(int lives)
{
	uiManager->UpdateLives(lives);
}

void ScoreManager::ResetScore()
{
	score = 0;
	uiManager->UpdateScore(score);
}

void ScoreManager::IncreaseScore(int delta)
{
	score += delta;
	uiManager->UpdateScore(score);
}
