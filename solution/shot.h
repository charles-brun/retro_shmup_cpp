#pragma once
#include "actor.h"

class Shot :
    public Actor
{
public:
    Shot();
    void Update(float deltaTime) override;
    void SetSide(Actor::Side _side) override;
private:
    Shot::Side side;
};

