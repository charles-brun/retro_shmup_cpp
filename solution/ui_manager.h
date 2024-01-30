#pragma once
#include <SFML/Graphics.hpp>

class UIManager
{
public:
	UIManager(sf::RenderWindow* window);
	void Draw();
	void UpdateScore(int _score);
	sf::RenderWindow* mainWindow;
	sf::Font font;
	sf::Text score;
};

