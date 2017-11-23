#pragma once
#include "Player.hpp"
#include "EnemyController.hpp"

class Enemy : public Player { // klasa do poruszania siê graczem.
public:
	Enemy();
	virtual void draw() override;
	virtual void setLocation(const grim::Vector2 &location) override;
	inline void incrementMoveFlag() { moveFlag++; }
	inline void setMoveFlag() { moveFlag = 0; }
	inline int getMoveFlag() { return moveFlag; }
	inline void setCanMove(bool type) { canMove = type; }
	inline bool getCanMove() const { return canMove; }
	void setSprite();
	inline sf::Sprite getSprite() const { return sprite; }
private:
	int moveFlag;
	bool canMove;
	sf::Sprite sprite;
};