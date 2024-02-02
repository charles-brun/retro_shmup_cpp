#include "pause_menu.h"
#include "utils.h"

void PauseMenu::Draw()
{
	Menu::Draw();
	mainWindow->draw(pauseText);
}

PauseMenu::PauseMenu(sf::RenderWindow* window, AssetsManager* assets) : Menu(window, assets)
{
	pauseText.setString("- Pause -");
	pauseText.setFillColor(sf::Color::Black);
	pauseText.setCharacterSize(Utils::getFontSize(Utils::M));
	pauseText.setFont(assets->font);

	sf::Vector2f textSize = pauseText.getGlobalBounds().getSize();
	float textPosX = (Utils::getWindowSize().x - textSize.x) / 2;
	float textPosY = (Utils::getWindowSize().y - (textSize.y * 3)) / 2;

	pauseText.setPosition({ textPosX, textPosY });

	float scale = Utils::globalScale;
	continueGame.Initialize("Continue", GetNextLinePos(pauseText, 2 * (scale + 2), 2 * (scale + 2)), MenuChoice::Continue, assets);
	choices.push_back(&continueGame);
	quit.Initialize("Quit", GetNextLinePos(continueGame.text, 0, scale), MenuChoice::Quit, assets);
	choices.push_back(&quit);
	SetCursorOnChoice();
}