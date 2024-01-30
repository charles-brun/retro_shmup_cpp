#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "main_game.h"
#include <iostream>

MainGame::MainGame(sf::RenderWindow* window, AssetsManager* assets, ScoreManager* score) : mainWindow(window), assetsManager(assets), scoreManager(score)
{
	running = true;
	actorsManager = new ActorsManager(window, assets, score);
	uiManager = score->uiManager;
	player = actorsManager->player;
}

void MainGame::HandleInputs()
{
	if (player != nullptr)
	{
		sf::Vector2f dir = { 0, 0 };
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			dir.x += 1.0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
		{
			dir.x -= 1.0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			dir.y += 1.0;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z))
		{
			dir.y -= 1.0;
		}
		if (abs(dir.x) > 0 && abs(dir.y) > 0)
		{
			dir.x *= 0.7f;
			dir.y *= 0.7f;
		}
		player->Move(dir);

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
		{
			player->TryToShoot();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
		{
			score += 10;
			uiManager->UpdateScore(score);
		}
	}
}

void MainGame::Update(float deltaTime)
{
	actorsManager->Update(deltaTime);
}

void MainGame::Draw()
{
	sf::Color color(119, 146, 114);
	mainWindow->clear(color);
	actorsManager->Draw();
	uiManager->Draw();
	mainWindow->display();
}

void MainGame::Run()
{
	mainWindow->setActive(true);
	sf::Clock dtClock;
	float deltaTime;
	while (running)
	{
		deltaTime = dtClock.restart().asSeconds();
		HandleInputs();
		Update(deltaTime);
		Draw();
	}
}

MainGame::~MainGame()
{
	delete actorsManager;
}
