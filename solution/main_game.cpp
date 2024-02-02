#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "main_game.h"
#include <iostream>

MainGame::MainGame(sf::RenderWindow* window, AssetsManager* assets, ScoreManager* score) : mainWindow(window), assetsManager(assets), scoreManager(score)
{
	canNavigate = true;
	actorsManager = new ActorsManager(window, assets, score);
	scoreManager = score;
	uiManager = score->uiManager;
	mainMenu = new MainMenu(window, assets);
	pauseMenu = new PauseMenu(window, assets);
	winMenu = new WinMenu(window, assets);
	gameOverMenu = new GameOverMenu(window, assets);
	player = actorsManager->player;
	currentState = StartMenu;
	currentMenu = mainMenu;
}

void MainGame::HandleInputs()
{
	if (currentState == GamePlay)
	{
		if (player != nullptr && canMove)
		{
			sf::Vector2f dir = { 0, 0 };
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
			{
				dir.x += 1.0;
				canNavigate = false;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
			{
				dir.x -= 1.0;
				canNavigate = false;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			{
				dir.y += 1.0;
				canNavigate = false;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z))
			{
				dir.y -= 1.0;
				canNavigate = false;
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
				canNavigate = false;
			}
		}
	}
	else
	{
		if (canNavigate) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter))
			{
				MenuChoice::Action action = currentMenu->GetChoice();
				switch (action)
				{
				case MenuChoice::NewGame:
					NewGame();
					break;
				case MenuChoice::Quit:
					mainWindow->close();
					break;
				case MenuChoice::Continue:
					currentState = GamePlay;
					break;
				case MenuChoice::NextLevel:
					StartNextLevel();
					break;
				default:
					break;
				}
				canMove = false;
				canNavigate = false;
				return;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
			{
				currentMenu->NextChoice();
				canMove = false;
				canNavigate = false;
				return;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Z))
			{
				currentMenu->PrevChoice();
				canMove = false;
				canNavigate = false;
				return;
			}
		}
	}
}

void MainGame::Update(float deltaTime)
{
	switch (currentState)
	{
	case MainGame::StartMenu:
		currentMenu = mainMenu;
		break;
	case MainGame::GamePlay:
		actorsManager->Update(deltaTime);
		if (player != nullptr && !player->alive)
		{
			if (currentState != GameOver)
			{
				gameOverMenu->SetScore(scoreManager->score);
			}
			currentState = GameOver;
		} else if (actorsManager->levelEnded)
		{
			if (currentState != NextLevel)
			{
				winMenu->SetScore(scoreManager->score);
			}
			currentState = NextLevel;
		}
		break;
	case MainGame::Pause:
		currentMenu = pauseMenu;
		break;
	case MainGame::NextLevel:
		currentMenu = winMenu;
		break;
	case MainGame::GameOver:
		currentMenu = gameOverMenu;
		break;
	default:
		break;
	}
}

void MainGame::Draw()
{
	sf::Color color(119, 146, 114);
	mainWindow->clear(color);
	switch (currentState)
	{
	case MainGame::StartMenu:
		mainMenu->Draw();
		break;
	case MainGame::GamePlay:
		actorsManager->Draw();
		uiManager->Draw();
		break;
	case MainGame::Pause:
		pauseMenu->Draw();
		break;
	case MainGame::NextLevel:
		winMenu->Draw();
		break;
	case MainGame::GameOver:
		gameOverMenu->Draw();
		break;
	default:
		break;
	}
	mainWindow->display();
}

void MainGame::Run()
{
	sf::Clock dtClock;
	float deltaTime;
	if (!mainWindow)
	{
		return;
	}
	while (mainWindow->isOpen())
	{
		HandleEvents();
		deltaTime = dtClock.restart().asSeconds();
		HandleInputs();
		Update(deltaTime);
		Draw();
	}
}

void MainGame::NewGame()
{
	scoreManager->ResetScore();
	actorsManager->Reset();
	currentState = GamePlay;
}

void MainGame::StartNextLevel()
{
	actorsManager->NextLevel();
	currentState = GamePlay;
}

void MainGame::HandleEvents()
{
	sf::Event event;

	while (mainWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			mainWindow->close();
		}
		else if (event.type == sf::Event::KeyPressed)
		{
			if (event.key.code == sf::Keyboard::Escape)
			{
				currentState = MainGame::Pause;
			}
		}
		else if (event.type == sf::Event::KeyReleased)
		{
			canNavigate = true;
			canMove = true;
		}
	}
}

MainGame::~MainGame()
{
	delete actorsManager;
	delete mainMenu;
	delete pauseMenu;
	delete gameOverMenu;
}
