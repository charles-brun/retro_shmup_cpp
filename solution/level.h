#pragma once
#include "enemy.h"

class Level
{
public:
	Level();
	void Update(float deltaTime);
	Enemy* Spawn(Enemy::Type type);
	bool CanSpawn();
	void ResetSpawnCD();
	void Initialize(int _enemyNumber = 15, int _frequency = 60);
	Enemy::Type GetNextEnemy();
	std::vector<Enemy::Type> enemyList;
	int currentSpawnIndex = 0;
	int frequency = 60;
	float spawnTimer = 0;
	float spawnCD = 60.0f;
	bool spawn = false;
};

