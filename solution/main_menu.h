#pragma once
#include "menu.h"
#include "menu_choice.h"

class MainMenu :
    public Menu
{
public:
    MainMenu(sf::RenderWindow* window, AssetsManager* assets);
    MenuChoice newGame;
    MenuChoice quit;
};

