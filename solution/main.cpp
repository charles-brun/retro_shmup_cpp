#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "main_game.h"
#include "assets_manager.h"
#include "utils.h"
#include "score_manager.h"

int WinMain()
{
	sf::Vector2f windowSize = Utils::getWindowSize();
	sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "Retro Shmup", sf::Style::Titlebar+sf::Style::Close);
	AssetsManager assetsManager;
	assetsManager.Load();
	UIManager uiManager(&window, &assetsManager);
	ScoreManager scoreManager(&uiManager);
	MainGame mainGame(&window, &assetsManager, &scoreManager);
	window.setActive(true);
	window.setKeyRepeatEnabled(false);
	mainGame.Run();

	return 0;
}