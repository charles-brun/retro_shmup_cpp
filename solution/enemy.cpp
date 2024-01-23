#include "enemy.h"
#include "utils.h"

Enemy::Enemy()
{
	SetSide(Side::Enemy);
}

void Enemy::Update(float deltaTime)
{
	Actor::Update(deltaTime);
	if (position.x + (sprite.getTexture()->getSize().x * Utils::globalScale) < 0)
	{
		toDelete = true;
	}
}
