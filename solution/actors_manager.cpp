#pragma once
#include "actors_manager.h"
#include "player.h"
#include "utils.h"
#include "shot.h"

ActorsManager::ActorsManager(sf::RenderWindow* window, AssetsManager* assets, ScoreManager* score) : mainWindow(window), assetsManager(assets), scoreManager(score)
{
	level = new Level();
	player = new Player();
	player->Load(assetsManager);
	sf::Vector2f spriteSize = player->GetSpriteSize();
	
	AddActor(player, { spriteSize.x, Utils::getWindowSize().y / 2 });
	level->Initialize(50);
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
	int rdm = Utils::getMarginTop() + std::rand() % (int)(Utils::getMarginBot() - enemy->GetSpriteSize().y - Utils::getMarginTop());
	AddActor(enemy, sf::Vector2f(Utils::getWindowSize().x - 50, rdm));
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
	level->Update(deltaTime);
	if (level->CanSpawn())
	{
		AddEnemy(level->GetNextEnemy());
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
					actors[i]->TakeDamage(actors[j]->damage);
					actors[j]->TakeDamage(actors[i]->damage);
				}
			}
		}
		if (actors[i]->toDelete)
		{
			AddActorToRemove(actors[i]);
		}
	}

	for (int i = 0; i < actorsToRemove.size(); ++i)
	{
		if (!actorsToRemove[i]->alive)
		{
			scoreManager->IncreaseScore(actorsToRemove[i]->scoreValue);
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
	delete player;
	delete level;
}
