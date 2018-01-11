#pragma once
#include "Player.hpp"
#include "MenuManagerController.hpp"

class MenuManager : public Player {
public:
	enum menuState {
		newGame,
		load,
		options
	};
	MenuManager();
	virtual void draw() override;
	virtual void setLocation(const grim::Vector2 &location) override;
	sf::Text getMenuContent(const int number) { return menuContent[number]; }
	sf::Text getNewGameContent(const int number) { return newGameContent[number]; }
	sf::Text getLoadContent(const int number) { return loadContent[number]; }
	sf::Text getOptionsContent(const int number) { return optionsContent[number]; }
	void updateContent(sf::Vector2f);
	inline void setStatus(const enum menuState menuStatus) { this->menuStatus = menuStatus; }
	inline menuState getStatus() const { return menuStatus; }
	inline void setFlag(const bool flag) { this->flag = flag; }
	inline bool getFlag() const { return this->flag; }
	inline sf::FloatRect getSpriteBounds(const int numberOfSprite) const { return sprite[numberOfSprite].getGlobalBounds(); }
private:
	sf::Font font;
	sf::Sprite background;
	sf::Sprite sprite[3];
	sf::Text menuContent[4];
	sf::Text optionsContent[4];
	sf::Text loadContent[4];
	sf::Text newGameContent[5];
	menuState menuStatus;
	bool flag = false;
	void setContent();
};