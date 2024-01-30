#include "pause_menu.h"
#include "utils.h"

PauseMenu::PauseMenu(sf::RenderWindow* window, AssetsManager* assets) : Menu(window, assets)
{
	float scale = Utils::globalScale;
	float spacing = 7;
	sf::Vector2f margin = { 30 * scale, 30 * scale };
	continueGame.Initialize("Continue", margin, MenuChoice::Continue, assets);
	choices.push_back(&continueGame);
	quit.Initialize("Quit", GetNextLinePos(continueGame.text, 0, spacing), MenuChoice::Quit, assets);
	choices.push_back(&quit);
	SetCursorOnChoice();
}