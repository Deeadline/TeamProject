//#pragma once
//#include "Player.hpp"
//#include "GameMenuController.hpp"
//
//class GameMenu : public Player {
//public:
//	enum menuState {
//		save,
//		exit,
//	};
//
//	explicit GameMenu();
//	virtual void draw() override;
//	virtual void setLocation(const grim::Vector2 &location) override;
//	sf::Text getMenuContent(const int number) { return menuContent[number]; }
//	sf::Text getSaveContent(const int number) { return saveContent[number]; }
//	void updateContent(const sf::Vector2f);
//	inline void setStatus(const enum menuState menuStatus) { this->menuStatus = menuStatus; }
//	inline menuState getStatus() const { return menuStatus; }
//private:
//	sf::Font font;
//	sf::Sprite background;
//	sf::Text menuContent[2];
//	sf::Text saveContent[2];
//	menuState menuStatus;
//	void setContent();
//};