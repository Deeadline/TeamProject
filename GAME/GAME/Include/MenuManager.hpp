#pragma once
#include "Player.hpp"

class MenuManager : public Player {
public:
	MenuManager();

	virtual void draw() override;
	virtual void setLocation(const grim::Vector2 &location) override;

	enum MenuState {
		newGame,
		load,
	};

	sf::Text menuText(const int number) { return menuTexts[number]; }
	sf::Text loadText(const int number) { return loadTexts[number]; }
	sf::Text gameText(const int number) { return gameTexts[number]; }
	sf::FloatRect getSpriteBounds(const int numberOfSprite) const { return championsChoice[numberOfSprite].getGlobalBounds(); }
	MenuState getStatus() const { return menuStatus; }
	bool getFlag() const { return this->flag; }

	void setStatus(const enum MenuState menuStatus) { this->menuStatus = menuStatus; }
	void setFlag(const bool flag) { this->flag = flag; }

	void updateContent(const sf::Vector2f);
private:
	sf::Font font;
	sf::Sprite background;
	sf::Sprite championsChoice[3];
	sf::Text menuTexts[4];
	sf::Text loadTexts[4];
	sf::Text gameTexts[5];
	MenuState menuStatus;
	bool flag;

	void setContent();
};