#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "actor.h"
#include "assets_manager.h"
#include "player.h"

class Spawner
{
public:
	Spawner(sf::RenderWindow* window, AssetsManager* assets);
	sf::RenderWindow* mainWindow;
	AssetsManager* assetsManager;
	std::vector<Actor*> actors;
	std::vector<Actor*> actorsToRemove;
	Player* player;
	void AddActor(Actor* actor, sf::Vector2f pos);
	void AddActorToRemove(Actor* actor);
	void DeleteActors();
	void Update(float deltaTime);
	void Draw();
	void RemoveActorFromList(Actor* actorToRemove);
	~Spawner();
};

