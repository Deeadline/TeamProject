#pragma once
#include "Includers.hpp"
#include "Level.hpp"
#include "MenuManager.hpp"
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
	inline sf::View& getView() { return currentView; }
	void setLevel(std::string levelContent);
	void GameManager::runGame();
	inline sf::Font getFont() const { return font; }
	inline void setStatus(enum Status gameStatus) { this->gameStatus = gameStatus; }
	void setResolution(sf::Vector2u &);
private:
	GameManager();
	GameManager(const GameManager&) = delete;
	void operator=(const GameManager&) = delete;
	void loadContent();
	sf::RenderWindow currentWindow;
	sf::View currentView;
	MenuManager* content;
	Status gameStatus;
	Level* currentLevel;
	sf::Font font;
};