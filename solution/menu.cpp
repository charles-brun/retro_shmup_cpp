#include "menu.h"
#include "utils.h"
#include <cassert>

Menu::Menu(sf::RenderWindow* window, AssetsManager* assets) : mainWindow(window), assetsManager(assets)
{
	cursorTex = assetsManager->textures["cursor"];
	cursor.setTexture(*cursorTex);
	cursor.setScale({ Utils::globalScale, Utils::globalScale });
}

void Menu::Draw()
{
	if (!choices.empty())
	{
		mainWindow->draw(cursor);
		for (int i = 0; i < choices.size(); ++i)
		{
			mainWindow->draw(choices[i]->text);
		}
	}
}

void Menu::PrevChoice()
{
	selectedChoice--;
	if (selectedChoice < 0)
	{
		selectedChoice = choices.size() - 1;
	}
	SetCursorOnChoice();
}

void Menu::NextChoice()
{
	selectedChoice++;
	if (selectedChoice >= choices.size())
	{
		selectedChoice = 0;
	}
	SetCursorOnChoice();
}

MenuChoice::Action Menu::GetChoice()
{
	assert(!choices.empty());
	return choices[selectedChoice]->action;
}

void Menu::SetCursorOnChoice()
{
	if (!choices.empty())
	{
		float offsetX = (cursor.getTexture()->getSize().x + 5) * Utils::globalScale;
		cursor.setPosition(choices[selectedChoice]->position - sf::Vector2f(offsetX, 0));
	}
}

sf::Vector2f Menu::GetNextLinePos(sf::Text text, float offsetX, float offsetY)
{
	sf::Vector2f textSize = text.getGlobalBounds().getSize();
	float posX = text.getPosition().x + offsetX * Utils::globalScale;
	float posY = text.getPosition().y + textSize.y + offsetY * Utils::globalScale;
	return { posX, posY };
}


