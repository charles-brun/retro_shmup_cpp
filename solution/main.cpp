#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "main_game.h"
#include "assets_manager.h"
#include "utils.h"

int WinMain()
{
	sf::Vector2f windowSize = Utils::getWindowSize();
	sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "Retro Shmup", sf::Style::Titlebar+sf::Style::Close);
	AssetsManager assetsManager;
	assetsManager.Load();
	MainGame mainGame(&window, &assetsManager);
	sf::Thread gameThread(&MainGame::Run, &mainGame);

	window.setActive(false);
	gameThread.launch();

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					window.close();
				}
			}
		}
	}
	gameThread.terminate();

	return 0;
}