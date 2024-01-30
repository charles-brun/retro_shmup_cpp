#pragma once
#include "menu.h"
#include "menu_choice.h"

class PauseMenu :
    public Menu
{
public:
    PauseMenu(sf::RenderWindow* window, AssetsManager* assets);
    MenuChoice continueGame;
    MenuChoice quit;
};

