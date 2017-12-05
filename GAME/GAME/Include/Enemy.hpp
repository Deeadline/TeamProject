#pragma once
#include "Player.hpp"

class Enemy : public Player { // klasa do poruszania siê graczem.
public:
	Enemy();
	virtual void draw() override;
	virtual void setLocation(const grim::Vector2 &location) override;
	inline void incrementMoveFlag() { moveFlag++; }
	inline void setMoveFlag() { moveFlag = 0; }
	inline int getMoveFlag() const { return moveFlag; }
	inline void setCanMove(bool type) { canMove = type; }
	inline bool getCanMove() const { return canMove; }
	void setSprite();
	inline sf::RectangleShape getSprite() const { return rectangleShape; }
private:
	int moveFlag;
	bool canMove;
	sf::Sprite sprite;
	sf::RectangleShape rectangleShape;
};