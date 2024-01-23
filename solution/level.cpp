#include "level.h"
#include "rocket.h"

Level::Level()
{
}

void Level::Update(float deltaTime)
{
	if (spawnTimer <= 0)
	{
		spawn = true;
	}
}

Enemy* Level::Spawn(Enemy::Type type)
{
	switch (type)
	{
	case Enemy::Rocket:
		return new Rocket();
		break;
	default:
		break;
	}
}

void Level::ResetSpawnCD()
{

}
