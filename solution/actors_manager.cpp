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
	level->Initialize();
}

void ActorsManager::AddActor(Actor* actor, sf::Vector2f pos)
{
	actors.push_back(actor);
	actor->SetPosition(pos);
}

void ActorsManager::AddEnemy(Enemy::Type type)
{
	Enemy* enemy = level->Spawn(type);
	int rdm = Utils::getMarginTop() + std::rand() % (int)(Utils::getMarginBot() - enemy->GetSpriteSize().y - Utils::getMarginTop());
	sf::Vector2f spawnPos = sf::Vector2f(Utils::getWindowSize().x - 50, rdm);
	enemy->Load(assetsManager);
	enemy->Initialize(spawnPos);
	AddActor(enemy, spawnPos);
	enemies.push_back(enemy);
	aliveEnemies++;
}

void ActorsManager::AddActorToRemove(Actor* actor)
{
	if (actor != player)
	{
		actorsToRemove.push_back(actor);
	}
}

void ActorsManager::DeleteActorsToRemove()
{
	for (int i = 0; i < actorsToRemove.size(); ++i)
	{
		RemoveActorFromList(actorsToRemove[i]);
		if (dynamic_cast<Enemy*>(actorsToRemove[i]) != nullptr)
		{
			RemoveEnemyFromList(dynamic_cast<Enemy*>(actorsToRemove[i]));
			aliveEnemies--;
			if (level->enemyList.size() == 0 && aliveEnemies <= 0)
			{
				levelEnded = true;
			}
		}
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
					actors[i]->TakeDamage(actors[j]->damage, assetsManager);
					if (actors[i] == player)
					{
						scoreManager->UpdateLives(player->hitPoints);
					}
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

void ActorsManager::RemoveEnemyFromList(Enemy* enemyToRemove)
{
	int index = -1;
	for (int i = 0; i < enemies.size(); i++)
	{
		if (enemies[i] == enemyToRemove)
		{	
			index = i;
			break;
		}
	}
	if (index != -1)
	{
		enemies.erase(enemies.begin() + index);
	}
}

void ActorsManager::Reset()
{
	for (int i = 0; i < actors.size(); i++)
	{
		AddActorToRemove(actors[i]);
	}
	DeleteActorsToRemove();
	delete level;
	level = new Level();
	level->Initialize();
	player->hitPoints = 3;
	scoreManager->UpdateLives(player->hitPoints);
	player->alive = true;
	player->SetPosition({ player->GetSpriteSize().x, Utils::getWindowSize().y / 2 });
	levelEnded = false;
}

void ActorsManager::NextLevel()
{
	for (int i = 0; i < actors.size(); i++)
	{
		AddActorToRemove(actors[i]);
	}
	DeleteActorsToRemove();
	delete level;
	level = new Level();
	level->Initialize();
	player->GainLives(0);
	scoreManager->UpdateLives(player->hitPoints);
	player->SetPosition({ player->GetSpriteSize().x, Utils::getWindowSize().y / 2 });
	levelEnded = false;
}

ActorsManager::~ActorsManager()
{
	for (int i = 0; i < actors.size(); i++)
	{
		AddActorToRemove(actors[i]);
	}
	DeleteActorsToRemove();
	delete level;
	delete player;
}
