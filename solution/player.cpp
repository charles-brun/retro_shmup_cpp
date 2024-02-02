#pragma once
#include <iostream>
#include "main_game.h"
#include "player.h"
#include "utils.h"
#include "math.h"

Player::Player() : Actor{}
{
	SetSide(Side::Ally);
	texture_name = "player";
	speed = 60.0;
	vulnCD = 1.2f;
}

void Player::Load(AssetsManager* assetsManager)
{
	Actor::Load(assetsManager);
}

void Player::Update(float deltaTime)
{
	Actor::Update(deltaTime);
	if (invulnerable)
	{
		float time = ceilf(vulnTimer*10);
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
}

void Player::Draw()
{
	Actor::Draw();
}

void Player::Move(sf::Vector2f dir)
{
	sf::Vector2f newDir = dir;
	sf::Vector2f size = GetSpriteSize();
	if ((dir.x < 0 && position.x <= 0) || (dir.x > 0 && position.x + size.x >= Utils::getWindowSize().x))
	{
		newDir.x = 0;
	}
	if ((dir.y < 0 && position.y <= Utils::getMarginTop()) || (dir.y > 0 && position.y + size.y >= Utils::getMarginBot()))
	{
		newDir.y = 0;
	}
	velocity = newDir;
}

void Player::GainLives(int gain)
{
	hitPoints += gain;
}
