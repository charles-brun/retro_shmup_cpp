#pragma once
#include "actor.h"
class Enemy :
    public Actor
{
public:
    Enemy();
    void Update(float deltaTime) override;
    void TakeDamage(int _damage, AssetsManager* assetsManager) override;
    static enum Type
    {
        Rocket,
        Asteroid,
        TYPE_SIZE,
    };
};

