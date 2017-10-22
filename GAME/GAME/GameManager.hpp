#pragma once
#include "Includers.hpp"
#include "Level.hpp"
class GameManager {
public:
	enum Status {
		initializing = 0,
		running = 1,
		paused = 2,
		cleaningUp = 3
	};
	~GameManager();
	inline static GameManager& instance() {
		static GameManager instance;
		return instance;
	}
	inline sf::RenderWindow& getWindow() { return currentWindow; }
	inline Status getStatus() const { return gameStatus; }
	inline Level* getLevel() const { return currentLevel; }
	void GameManager::runGame();
private:
	GameManager();
	GameManager(const GameManager&) = delete;
	void operator=(const GameManager&) = delete;

	sf::RenderWindow currentWindow;
	Status gameStatus;
	Level* currentLevel;

};