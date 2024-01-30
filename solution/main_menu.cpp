#include "main_menu.h"
#include "utils.h"

MainMenu::MainMenu(sf::RenderWindow* window, AssetsManager* assets) : Menu(window, assets)
{
	float scale = Utils::globalScale;
	float spacing = 7;
	sf::Vector2f margin = { 30 * scale, 30 * scale };
	newGame.Initialize("New game", margin, MenuChoice::NewGame, assets);
	choices.push_back(&newGame);
	quit.Initialize("Quit", GetNextLinePos(newGame.text, 0, spacing), MenuChoice::Quit, assets);
	choices.push_back(&quit);
	SetCursorOnChoice();
}