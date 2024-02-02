#pragma once
#include "menu.h"
#include "menu_choice.h"

class WinMenu :
    public Menu
{
public:
    void Draw() override;
    WinMenu(sf::RenderWindow* window, AssetsManager* assets);
    sf::Text winText;
    sf::Text score;
    MenuChoice nextLevel;
    MenuChoice quit;
    void SetScore(int _score);
};

