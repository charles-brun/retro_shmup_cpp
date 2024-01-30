#pragma once
#include <SFML/Graphics.hpp>
#include "actor.h"
#include "actors_manager.h"
#include "assets_manager.h"
#include "score_manager.h"
#include "ui_manager.h"

class MainGame {
public: 
	sf::RenderWindow* mainWindow;
	bool running;
	AssetsManager* assetsManager;
	ActorsManager* actorsManager;
	UIManager* uiManager;
	ScoreManager* scoreManager;
	Player* player;
	int score = 0;

	MainGame(sf::RenderWindow* window, AssetsManager* assets, ScoreManager* score);
	void HandleInputs();
	void Update(float deltaTime);
	void Draw();
	void Run();
	~MainGame();
};