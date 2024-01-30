#include "menu_choice.h"

void MenuChoice::Initialize(std::string _text, sf::Vector2f _pos, Action _action, AssetsManager* assets)
{
	text.setString(_text);
	text.setFillColor(sf::Color::Black);
	text.setCharacterSize(28);
	text.setFont(assets->font);
	position = _pos;
	text.setPosition(_pos);
	action = _action;
}