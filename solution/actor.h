#pragma once
#include <string>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "assets_manager.h"

class Actor
{
public:
	Actor();
	virtual void Load(AssetsManager* assetsManager);
	virtual void Update(float deltaTime);
	virtual void Draw();
	void SetSprite(sf::Texture* texture, sf::Vector2f offset);
	virtual void Move(sf::Vector2f dir);
	virtual void SetPosition(sf::Vector2f pos);
	virtual sf::Vector2f GetPosition();
	virtual sf::Vector2f GetCenteredPosition();
	virtual void TryToShoot();
	virtual void ResetShootCD();
	float shootTimer = 0;
	float shootCD = 0.2f;
	bool shoot = false;
	float speed = 30.0f;
	bool toDelete = false;
	sf::Vector2f velocity = { 0, 0 };
	sf::Sprite sprite;
	std::string texture_name;
	static enum Side {
		Ally,
		Enemy,
	};
	virtual void SetSide(Actor::Side _side);
	Actor::Side GetSide();
protected:
	sf::Vector2f position;
	Actor::Side side;
};
