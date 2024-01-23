#pragma once
#include "enemy.h"

class Level
{
public:
	Level();
	virtual void Update(float deltaTime);
	virtual Enemy* Spawn(Enemy::Type type);
	virtual void ResetSpawnCD();
	int currentSpawnIndex = 0;
	float spawnTimer = 0;
	float spawnCD = 0.2f;
	bool spawn = false;
};

