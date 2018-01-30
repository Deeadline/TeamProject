#pragma once
#include "Includers.hpp"
#include "Level.hpp"
#include "MenuManager.hpp"
#include "Enemy.hpp"
#include "Thalia.hpp"
#include "GameMenu.hpp"

class GameManager { // g³ówna klasa gry
public:
	~GameManager();

	static GameManager& instance() {
		static GameManager instance;
		return instance;
	}

	enum Status {
		initializing = 0,
		running = 1,
		paused = 2,
		cleaningUp = 3
	};

	sf::RenderWindow& getWindow() { return currentWindow; }
	sf::Font getFont() const { return font; }
	sf::View& getViewGame() { return viewGame; }
	sf::View& getViewMenu() { return viewMenu; }
	std::string getLevelName() { return levelContent; }
	Status getStatus() const { return gameStatus; }
	Level* getLevel() const { return currentLevel; }
	Thalia* getPlayer() const { return player; }
	Enemy* getEnemy() const { return enemy; }

	void runGame();
	void setLevel(std::string levelContent, bool);
	void setStatus(const enum Status gameStatus) { this->gameStatus = gameStatus; }
protected:
	MenuManager* content;
	Thalia* player;
	Enemy* enemy;
	Status gameStatus;
	Level* currentLevel;
private:
	GameManager();
	GameManager(const GameManager&) = delete;
	void operator=(const GameManager&) = delete;

	void loadContent();
	sf::RenderWindow currentWindow;
	sf::View viewMenu;
	sf::View viewGame;
	sf::Font font;
	std::string levelContent;
};