#pragma once
#include "enemy.h"
class Rocket :
    public Enemy
{
public:
    Rocket();
    void TakeDamage(int _damage, AssetsManager* assetsManager) override;
    sf::Sprite spriteDamaged;
};

