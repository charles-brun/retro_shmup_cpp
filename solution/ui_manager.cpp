#include "ui_manager.h"
#include "utils.h"

UIManager::UIManager(sf::RenderWindow* window, AssetsManager* assets) : mainWindow(window), assetsManager(assets)
{
	score.setFont(assets->font);
	score.setFillColor(sf::Color::Black);
	score.setCharacterSize(28);
	UpdateScore(0);
	lives.setFont(assets->font);
	lives.setFillColor(sf::Color::Black);
	lives.setCharacterSize(28);
	lives.setPosition({5 * Utils::globalScale, 0});
}

void UIManager::Draw()
{
	mainWindow->draw(score);
	mainWindow->draw(lives);
}

void UIManager::UpdateScore(int _score)
{
	score.setString(std::to_string(_score));
	float rectSize = score.getGlobalBounds().getSize().x + (5 * Utils::globalScale);
	score.setPosition({ Utils::getWindowSize().x - rectSize, 0 });

}

void UIManager::UpdateLives(int _lives)
{
	lives.setString("Lives: " + std::to_string(_lives));
}
