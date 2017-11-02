#pragma once
#include "Includers.hpp"
#include "Level.hpp"
#include "MenuManager.hpp"
#include "PercyJackson.hpp"
class GameManager { // g³ówna klasa gry
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
	void setLevel(std::string levelContent);
	void GameManager::runGame();
	inline sf::Font getFont() const { return font; }
	inline void setStatus(enum Status tempora) { this->gameStatus = tempora; }
private:
	GameManager();
	GameManager(const GameManager&) = delete;
	void operator=(const GameManager&) = delete;

	sf::RenderWindow currentWindow;
	MenuManager* content;
	Status gameStatus;
	Level* currentLevel;
	sf::Font font;
};