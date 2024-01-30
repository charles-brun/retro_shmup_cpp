#pragma once
#include <SFML/Graphics.hpp>
#include "actor.h"
#include "actors_manager.h"
#include "assets_manager.h"
#include "score_manager.h"
#include "ui_manager.h"
#include "main_menu.h"
#include "game_over_menu.h"
#include "pause_menu.h"

class MainGame {
public: 
	sf::RenderWindow* mainWindow;
	AssetsManager* assetsManager;
	ActorsManager* actorsManager;
	UIManager* uiManager;
	ScoreManager* scoreManager;
	Player* player;
	int score = 0;
	bool canNavigate;
	enum GameState {
		StartMenu,
		GamePlay,
		Pause,
		GameOver,
	};
	GameState currentState;
	Menu* currentMenu;
	MainMenu* mainMenu;
	GameOverMenu* gameOverMenu;
	PauseMenu* pauseMenu;
	MainGame(sf::RenderWindow* window, AssetsManager* assets, ScoreManager* score);
	void HandleInputs();
	void Update(float deltaTime);
	void Draw();
	void Run();
	void NewGame();
	void HandleEvents();
	~MainGame();
};