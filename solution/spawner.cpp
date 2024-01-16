#pragma once
#include "spawner.h"
#include "player.h"
#include "utils.h"

Spawner::Spawner(sf::RenderWindow* window, AssetsManager* assets) : mainWindow(window), assetsManager(assets)
{
	player = new Player();
	player->Load(assetsManager);
	sf::Vector2u spriteSize = player->sprite.getTexture()->getSize() * (unsigned)Utils::globalScale;
	
	AddActor(player, { (float)spriteSize.x, Utils::getWindowSize().y / 2 });
}

void Spawner::AddActor(Actor* actor, sf::Vector2f pos)
{
	actors.push_back(actor);
	actor->SetPosition(pos);
}

void Spawner::AddActorToRemove(Actor* actor)
{
	actorsToRemove.push_back(actor);
}

void Spawner::DeleteActors()
{
	for (int i = 0; i < actorsToRemove.size(); ++i)
	{
		RemoveActorFromList(actorsToRemove[i]);
		delete actorsToRemove[i];
	}
	actorsToRemove.clear();
}

void Spawner::Update(float deltaTime)
{
	for (int i = 0; i < actors.size(); ++i)
	{
		actors[i]->Update(deltaTime);
	}
}

void Spawner::Draw()
{
	for (int i = 0; i < actors.size(); ++i)
	{
		actors[i]->Draw();
		mainWindow->draw(actors[i]->sprite);
	}
}

void Spawner::RemoveActorFromList(Actor* actorToRemove)
{
	int index = -1;
	for (int i = 0; i < actors.size(); i++)
	{
		if (actors[i] == actorToRemove)
		{
			index = i;
			break;
		}
	}
	if (index != -1)
	{
		actors.erase(actors.begin() + index);
	}
}

Spawner::~Spawner()
{
	while (actors.size() > 0)
	{
		AddActorToRemove(actors[0]);
	}
	DeleteActors();
}
