#pragma once
#include "actor.h"
class Enemy :
    public Actor
{
public:
    Enemy();
    void Update(float deltaTime) override;
    static enum Type 
    {
        Rocket,
    };
};

