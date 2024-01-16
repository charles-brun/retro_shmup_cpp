#pragma once
#include "actor.h"

class Player :
    public Actor
{
public:
    Player();
    void Load(AssetsManager* assetsManager) override;
    void Update(float deltaTime) override;
    void Draw() override;
    void Move(sf::Vector2f dir) override;
};

