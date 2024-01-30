#include "enemy.h"
#include "utils.h"

Enemy::Enemy()
{
	SetSide(Side::Enemy);
	damage = 1;
}

void Enemy::Update(float deltaTime)
{
	Actor::Update(deltaTime);
	if (position.x + (GetBounds().getSize().x * Utils::globalScale) < 0)
	{
		toDelete = true;
	}
}
