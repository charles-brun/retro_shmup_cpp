#include "ui_manager.h"
#include "utils.h"

UIManager::UIManager(sf::RenderWindow* window) : mainWindow(window)
{
	font.loadFromFile("munro.ttf");
	score.setFont(font);
	score.setFillColor(sf::Color::Black);
	score.setCharacterSize(28);
	UpdateScore(0);
}

void UIManager::Draw()
{
	mainWindow->draw(score);
}

void UIManager::UpdateScore(int _score)
{
	score.setString(std::to_string(_score));
	float rectSize = score.getGlobalBounds().getSize().x + (5 * Utils::globalScale);
	score.setPosition({ Utils::getWindowSize().x - rectSize, 0 });

}
