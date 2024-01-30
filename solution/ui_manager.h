#pragma once
#include <SFML/Graphics.hpp>
#include "assets_manager.h"

class UIManager
{
public:
	UIManager(sf::RenderWindow* window, AssetsManager* assets);
	void Draw();
	void UpdateScore(int _score);
	void UpdateLives(int _lives);
	AssetsManager* assetsManager;
	sf::RenderWindow* mainWindow;
	sf::Text score;
	sf::Text lives;
};

