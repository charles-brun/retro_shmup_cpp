#pragma once
#include "menu.h"
#include "menu_choice.h"

class PauseMenu :
    public Menu
{
public:
    void Draw() override;
    PauseMenu(sf::RenderWindow* window, AssetsManager* assets);
    sf::Text pauseText;
    MenuChoice continueGame;
    MenuChoice quit;
};

