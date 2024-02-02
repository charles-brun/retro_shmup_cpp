#include "win_menu.h"
#include "utils.h"

void WinMenu::Draw()
{
	Menu::Draw();
	mainWindow->draw(score);
	mainWindow->draw(winText);
}

WinMenu::WinMenu(sf::RenderWindow* window, AssetsManager* assets) : Menu(window, assets)
{
	score.setFillColor(sf::Color::Black);
	score.setCharacterSize(42);
	score.setFont(assets->font);

	winText.setString("Level complete!");
	winText.setFillColor(sf::Color::Black);
	winText.setCharacterSize(56);
	winText.setFont(assets->font);

	sf::Vector2f textSize = winText.getGlobalBounds().getSize();
	float textPosX = (Utils::getWindowSize().x - textSize.x) / 2;
	float textPosY = (Utils::getWindowSize().y - (textSize.y * 3)) / 2;

	winText.setPosition({ textPosX, textPosY });

	float scale = Utils::globalScale;
	float spacing = 7;
	float margin = 15;
	nextLevel.Initialize("Next level", GetNextLinePos(winText, margin, spacing + 3), MenuChoice::NextLevel, assets);
	choices.push_back(&nextLevel);
	quit.Initialize("Quit", GetNextLinePos(nextLevel.text, 0, spacing), MenuChoice::Quit, assets);
	choices.push_back(&quit);
	SetCursorOnChoice();
}

void WinMenu::SetScore(int _score)
{
	score.setString("Score: " + std::to_string(_score));
	float rectSize = score.getGlobalBounds().getSize().x + (5 * Utils::globalScale);
	score.setPosition({ Utils::getWindowSize().x - rectSize, 0 });
}

