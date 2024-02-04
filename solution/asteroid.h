#pragma once
#include "enemy.h"

class Asteroid :
    public Enemy
{
public:
    Asteroid();
    void Initialize(sf::Vector2f spawnPos) override;
};

