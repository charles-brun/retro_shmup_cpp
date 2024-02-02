#include "rocket.h"
#include "utils.h"
#include <algorithm>

Rocket::Rocket()
{
	textureNameNormal = "rocket";
	textureNameDamaged = "rocket_damaged";
	speed = 90.0f;
	hitPoints = 2;
	scoreValue = 10;
	Move(sf::Vector2f(-1, 0));
}

void Rocket::TakeDamage(int _damage, AssetsManager* assetsManager)
{
	Actor::TakeDamage(_damage, assetsManager);
	if (hitPoints <= 1)
	{
		SetSprite(assetsManager->textures[textureNameDamaged], { 0, 0 });
	}
}