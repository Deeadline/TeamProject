#pragma once
#include "Player.hpp"
#include "PercyJacksonController.hpp"
class PercyJackson : public Player { // klasa do poruszania siê graczem.
public: 
	PercyJackson();
	virtual void draw() override;
	virtual void setLocation(const grim::Vector2 &location) override;
	inline void incrementMoveFlag() { std::cout << moveFlag << std::endl; moveFlag++; }
	inline void setMoveFlag() { moveFlag = 0; }
	inline int getMoveFlag() { return moveFlag; }
	void setSprite(bool);
	inline sf::Sprite getSprite() const { return sprite; }
	inline void setIsMenu(bool isMenu) { this->isMenu = isMenu; }
	inline bool getIsMenu() const { return isMenu; }
	inline void setCanMove(bool canMove) { this->canMove = canMove; }
	inline bool getCanMove() const { return canMove; }
	double getTime(clock_t time) { return static_cast <double>(time) / CLOCKS_PER_SEC; }
private:
	sf::Sprite sprite;
	sf::Sprite background;
	int moveFlag;
	bool isMenu;
	bool canMove;
	double time;
};