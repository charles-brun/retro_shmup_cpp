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
	float speed = 30.0f;
	sf::Vector2f velocity;
	sf::Sprite sprite;
	std::string texture_name;
protected:
	sf::Vector2f position;
};
