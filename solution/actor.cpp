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
