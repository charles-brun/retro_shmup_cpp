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
	if (hitPoints <= 0)
	{
		Destroy();
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
	sf::Vector2f offset = { GetSpriteSize().x / 2, GetSpriteSize().y / 2};
	return position + offset;
}

sf::Vector2f Actor::GetSpriteSize()
{
	sf::Vector2u spriteSize = { 0, 0 };
	if (sprite.getTexture() != NULL)
	{
		spriteSize = sprite.getTexture()->getSize() * (unsigned)Utils::globalScale;
	}
	return sf::Vector2f((float)spriteSize.x, (float)spriteSize.y);
}

sf::FloatRect Actor::GetBounds()
{
	sf::Vector2f rect = GetSpriteSize();
	return sf::FloatRect(position.x, position.y, rect.x, rect.y);
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

void Actor::TakeDamage(int _damage)
{
	hitPoints -= _damage;
	if (hitPoints < 0)
	{
		hitPoints = 0;
		alive = false;
	}
}

void Actor::Destroy()
{
	toDelete = true;
}

void Actor::SetSide(Actor::Side _side)
{
	side = _side;
}

Actor::Side Actor::GetSide()
{
	return side;
}