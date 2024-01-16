#pragma once
#include "actor.h"
#include "utils.h"

Actor::Actor()
{
}

void Actor::Load(AssetsManager* assetsManager)
{
	SetSprite(assetsManager->textures[texture_name], { 0, 0 });
}

void Actor::Update(float deltaTime)
{
	position += velocity * deltaTime * speed * Utils::globalScale;
	sprite.setPosition(position);
	if (shootTimer > 0)
	{
		shootTimer-=deltaTime;
	}
}

void Actor::Draw()
{
}

void Actor::SetSprite(sf::Texture* texture, sf::Vector2f offset)
{
	sprite.setTexture(*texture);
	sprite.setScale({ Utils::globalScale, Utils::globalScale });
}

void Actor::Move(sf::Vector2f dir)
{
	velocity = dir;
}

void Actor::SetPosition(sf::Vector2f pos)
{
	position = pos;
}

sf::Vector2f Actor::GetPosition()
{
	return position;
}

sf::Vector2f Actor::GetCenteredPosition()
{
	sf::Vector2u spriteSize = sprite.getTexture()->getSize() * (unsigned)Utils::globalScale;
	sf::Vector2f offset = { (float)spriteSize.x/2, (float)spriteSize.y/2 };
	return position + offset;
}

void Actor::TryToShoot()
{
	if (shootTimer <= 0)
	{
		shoot = true;
	}
}

void Actor::ResetShootCD()
{
	shoot = false;
	shootTimer = shootCD;
}

void Actor::SetSide(Actor::Side _side)
{
	side = _side;
}

Actor::Side Actor::GetSide()
{
	return side;
}