#pragma once
#include "menu.h"
#include "menu_choice.h"

class GameOverMenu :
    public Menu
{
public:
    void Draw() override;
    GameOverMenu(sf::RenderWindow* window, AssetsManager* assets);
    sf::Text gameOverText;
    sf::Text score;
    MenuChoice newGame;
    MenuChoice quit;
    void SetScore(int _score);
};

