#pragma once
#include "Player.hpp"

class GameMenu : public Player {
public:
	explicit GameMenu();
	virtual void draw() override;
	virtual void setLocation(const grim::Vector2 &location) override;

	enum MenuState {
		save = 1,
		exit = 2,
	};

	sf::Text getMenuText(const int number) { return menuText[number]; }
	sf::Text getSaveText(const int number) { return saveText[number]; }
	MenuState getStatus() const { return menuStatus; }
	bool getFlag() const { return this->flag; }

	void setStatus(const enum MenuState menuStatus) { this->menuStatus = menuStatus; }
	void setFlag(const bool flag) { this->flag = flag; }

	void updateTexts(const sf::Vector2f);
private:
	sf::Font font;
	sf::Sprite background;
	sf::Text menuText[2];
	sf::Text saveText[2];
	MenuState menuStatus;
	bool flag;

	void setTexts();
};