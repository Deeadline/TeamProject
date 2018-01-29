#pragma once
#include "Includers.hpp"
#include "Level.hpp"
#include "MenuManager.hpp"
#include "Enemy.hpp"
#include "PercyJackson.hpp"
#include "GameMenu.hpp"

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
	inline PercyJackson* getPlayer() const { return player; }
	inline Enemy* getEnemy() const { return enemy; }
	void setLevel(std::string levelContent, bool);
	void runGame();
	inline sf::Font getFont() const { return font; }
	inline void setStatus(const enum Status gameStatus) { this->gameStatus = gameStatus; }
	inline std::string getLevelName() { return levelContent; }
	inline sf::View& getViewGame() { return viewGame; }
	inline sf::View& getViewMenu() { return viewMenu; }
protected:
	MenuManager* content;
	PercyJackson* player;
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
