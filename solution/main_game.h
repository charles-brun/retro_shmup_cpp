#pragma once
#include <SFML/Graphics.hpp>
#include "actor.h"
#include "actors_manager.h"
#include "assets_manager.h"

class MainGame {
public: 
	sf::RenderWindow* mainWindow;
	bool running;
	AssetsManager* assetsManager;
	ActorsManager* actorsManager;
	Player* player;

	MainGame(sf::RenderWindow* window, AssetsManager* assets);
	void HandleInputs();
	void Update(float deltaTime);
	void Draw();
	void Run();
	~MainGame();
};