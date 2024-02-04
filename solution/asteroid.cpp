#pragma once
#include "asteroid.h"
#include "utils.h"
#include <iostream>


Asteroid::Asteroid()
{
	textureNameNormal = "asteroid";
	textureNameDamaged = "asteroid_damaged";
	speed = 50.0f;
	hitPoints = 3;
	scoreValue = 20;
	Move(sf::Vector2f(-1, 0));
}

void Asteroid::Initialize(sf::Vector2f spawnPos)
{
	float dirY = (float)(1 + std::rand() % 3) / 10.0f;
	if (spawnPos.y > Utils::getWindowSize().y / 2)
	{
		Move(sf::Vector2f(-1, -dirY));
	}
	else {
		Move(sf::Vector2f(-1, dirY));
	}
	std::cout << dirY << std::endl;
}
