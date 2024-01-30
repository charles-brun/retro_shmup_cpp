#pragma once
#include <SFML/Graphics.hpp>
#include "menu_choice.h"
#include "assets_manager.h"

class Menu
{
public:
	Menu(sf::RenderWindow* window, AssetsManager* assets);
	virtual void Draw();
	sf::Sprite cursor;
	sf::Texture* cursorTex;
	sf::Vector2f cursorPos;
	std::vector<MenuChoice*> choices;
	void SetCursorOnChoice();
	sf::Vector2f GetNextLinePos(sf::Text text, float offsetX, float offsetY);
	AssetsManager* assetsManager;
	sf::RenderWindow* mainWindow;
	int selectedChoice = 0;
	void PrevChoice();
	void NextChoice();
	MenuChoice::Action GetChoice();
};

