#pragma once
#include <SFML/Graphics.hpp>
#include "assets_manager.h"

class MenuChoice
{
public:
	sf::Text text;
	sf::Vector2f position;
	enum Action {
		NewGame,
		Continue,
		Quit,
	};
	Action action;
	void Initialize(std::string _text, sf::Vector2f _pos, Action _action, AssetsManager* assets);
};

