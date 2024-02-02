#include "shot.h"
#include "utils.h"

Shot::Shot()
{
	textureNameNormal = "shot";
	speed = 100.0f;
	damage = 1;
}

void Shot::Update(float deltaTime)
{
	Actor::Update(deltaTime);
	if (position.x < 0 || position.x > Utils::getWindowSize().x)
	{
		toDelete = true;
	}
}

void Shot::SetSide(Actor::Side _side)
{
	Actor::SetSide(_side);
	switch (_side)
	{
	case Ally:
		velocity = { 1.0, 0 };
		break;
	case Enemy:
		velocity = { -1.0, 0 };
	}
}
