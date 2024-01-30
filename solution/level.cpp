#pragma once
#include "level.h"
#include "rocket.h"
#include <cassert>

Level::Level()
{
}

void Level::Initialize(int enemyNumber, int _frequency)
{
	frequency = _frequency;
	for (int i = 0; i < enemyNumber; ++i)
	{
		int rdm = std::rand() % Enemy::TYPE_SIZE;
		enemyList.push_back(static_cast<Enemy::Type>(rdm));
	}
}

Enemy::Type Level::GetNextEnemy()
{
	assert(!enemyList.empty());
	return enemyList[0];
}

void Level::Update(float deltaTime)
{
	if (spawnTimer <= 0)
	{
		if (!spawn)
		{
			spawn = true;
		}
	}
	else {
		spawnTimer -= deltaTime * frequency;
	}
}

Enemy* Level::Spawn(Enemy::Type type)
{
	spawnTimer = spawnCD;
	spawn = false;
	if (!enemyList.empty())
	{
		enemyList.erase(enemyList.begin());
	}
	switch (type)
	{
	case Enemy::Rocket:
		return new Rocket();
		break;
	default:
		break;
	}
}

bool Level::CanSpawn()
{
	return (spawn && !enemyList.empty());
}

void Level::ResetSpawnCD()
{

}
