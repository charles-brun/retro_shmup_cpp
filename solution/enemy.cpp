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
	if (invulnerable && hitPoints > 0)
	{
		float time = ceilf(vulnTimer * 10);
		if ((int)time % 2 == 0)
		{
			sprite.setColor(sf::Color(255, 255, 255, 255));
		}
		else
		{
			sprite.setColor(sf::Color(0, 0, 0, 0));
		}
	}
	else {
		sprite.setColor(sf::Color(255, 255, 255, 255));
	}
	if (position.x + (GetBounds().getSize().x * Utils::globalScale) < 0)
	{
		toDelete = true;
	}
}
