#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "actor.h"
#include "assets_manager.h"
#include "score_manager.h"
#include "player.h"
#include "level.h"

class ActorsManager
{
public:
	ActorsManager(sf::RenderWindow* window, AssetsManager* assets, ScoreManager* score);
	sf::RenderWindow* mainWindow;
	AssetsManager* assetsManager;
	ScoreManager* scoreManager;
	std::vector<Actor*> actors;
	std::vector<Actor*> actorsToRemove;
	Player* player;
	Level* level;
	void AddActor(Actor* actor, sf::Vector2f pos);
	void AddEnemy(Enemy::Type type);
	void AddActorToRemove(Actor* actor);
	void DeleteActorsToRemove();
	void Update(float deltaTime);
	void Draw();
	void RemoveActorFromList(Actor* actorToRemove);
	void Reset();
	~ActorsManager();
};

