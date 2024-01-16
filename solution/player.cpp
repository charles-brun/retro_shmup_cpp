#pragma once
#include <iostream>
#include "main_game.h"
#include "player.h"
#include "utils.h"

Player::Player() : Actor{}
{
	texture_name = "player";
	speed = 40.0;
}

void Player::Load(AssetsManager* assetsManager)
{
	Actor::Load(assetsManager);
}

void Player::Update(float deltaTime)
{
	Actor::Update(deltaTime);
}

void Player::Draw()
{
}

void Player::Move(sf::Vector2f dir)
{
	sf::Vector2f newDir = dir;
	sf::Vector2u size = sprite.getTexture()->getSize() * (unsigned)Utils::globalScale;
	if ((dir.x < 0 && position.x <= 0) || (dir.x > 0 && position.x + size.x >= Utils::getWindowSize().x))
	{
		newDir.x = 0;
	}
	if ((dir.y < 0 && position.y <= 0) || (dir.y > 0 && position.y + size.y >= Utils::getWindowSize().y))
	{
		newDir.y = 0;
	}
	velocity = newDir;
}
