#include "game_over_menu.h"
#include "utils.h"

void GameOverMenu::Draw()
{
	Menu::Draw();
	mainWindow->draw(score);
	mainWindow->draw(gameOverText);
}

GameOverMenu::GameOverMenu(sf::RenderWindow* window, AssetsManager* assets): Menu(window, assets)
{
	score.setFillColor(sf::Color::Black);
	score.setCharacterSize(42);
	score.setFont(assets->font);

	gameOverText.setString("GAME OVER");
	gameOverText.setFillColor(sf::Color::Black);
	gameOverText.setCharacterSize(56);
	gameOverText.setFont(assets->font);

	sf::Vector2f textSize = gameOverText.getGlobalBounds().getSize();
	float textPosX = (Utils::getWindowSize().x - textSize.x) / 2;
	float textPosY = (Utils::getWindowSize().y - (textSize.y * 3)) / 2;

	gameOverText.setPosition({ textPosX, textPosY });

	float scale = Utils::globalScale;
	float spacing = 7;
	float margin = 15;
	newGame.Initialize("New game", GetNextLinePos(gameOverText, margin, spacing + 3), MenuChoice::NewGame, assets);
	choices.push_back(&newGame);
	quit.Initialize("Quit", GetNextLinePos(newGame.text, 0, spacing), MenuChoice::Quit, assets);
	choices.push_back(&quit);
	SetCursorOnChoice();
}

void GameOverMenu::SetScore(int _score)
{
	score.setString("Score: " + std::to_string(_score));
	float rectSize = score.getGlobalBounds().getSize().x + (5 * Utils::globalScale);
	score.setPosition({ Utils::getWindowSize().x - rectSize, 0 });
}
