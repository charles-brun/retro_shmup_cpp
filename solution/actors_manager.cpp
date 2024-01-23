#pragma once
#include "actors_manager.h"
#include "player.h"
#include "utils.h"
#include "shot.h"

ActorsManager::ActorsManager(sf::RenderWindow* window, AssetsManager* assets) : mainWindow(window), assetsManager(assets)
{
	level = new Level();
	player = new Player();
	player->Load(assetsManager);
	sf::Vector2u spriteSize = player->sprite.getTexture()->getSize() * (unsigned)Utils::globalScale;
	
	AddActor(player, { (float)spriteSize.x, Utils::getWindowSize().y / 2 });
	AddEnemy(Enemy::Rocket);
}

void ActorsManager::AddActor(Actor* actor, sf::Vector2f pos)
{
	actors.push_back(actor);
	actor->SetPosition(pos);
}

void ActorsManager::AddEnemy(Enemy::Type type)
{
	Enemy* enemy = level->Spawn(type);
	enemy->Load(assetsManager);
	int rdm = std::rand() % (int)(Utils::getWindowSize().y);
	AddActor(enemy, sf::Vector2f(Utils::getWindowSize().x, rdm));
}

void ActorsManager::AddActorToRemove(Actor* actor)
{
	actorsToRemove.push_back(actor);
}

void ActorsManager::DeleteActorsToRemove()
{
	for (int i = 0; i < actorsToRemove.size(); ++i)
	{
		RemoveActorFromList(actorsToRemove[i]);
		delete actorsToRemove[i];
	}
	actorsToRemove.clear();
}

void ActorsManager::Update(float deltaTime)
{
	if (actors.size() > 30)
	{
		mainWindow->close();
	}
	for (int i = 0; i < actors.size(); ++i)
	{
		actors[i]->Update(deltaTime);
		if (actors[i]->shoot)
		{
			Shot* shot = new Shot();
			shot->Load(assetsManager);
			shot->SetSide(actors[i]->GetSide());
			sf::Vector2f actorPos = actors[i]->GetCenteredPosition();
			AddActor(shot, { actorPos.x, actorPos.y - shot->GetSpriteSize().y / 2});
			actors[i]->ResetShootCD();
		}
		// Check collisions
		for (int j = 0; j < actors.size(); ++j)
		{
			if (actors[i]->GetSide() != actors[j]->GetSide())
			{
				if (actors[i]->GetBounds().intersects(actors[j]->GetBounds()))
				{
					actors[i]->Collide();
					actors[j]->Collide();
				}
			}
		}
		if (actors[i]->toDelete)
		{
			AddActorToRemove(actors[i]);
		}
	}
	DeleteActorsToRemove();
}

void ActorsManager::Draw()
{
	for (int i = 0; i < actors.size(); ++i)
	{
		actors[i]->Draw();
		mainWindow->draw(actors[i]->sprite);
	}
}

void ActorsManager::RemoveActorFromList(Actor* actorToRemove)
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

ActorsManager::~ActorsManager()
{
	for (int i = 0; i < actors.size(); i++)
	{
		AddActorToRemove(actors[i]);
	}
	DeleteActorsToRemove();
	delete level;
}
