#pragma once
#include "Player.hpp"

class Enemy : public Player { // klasa do poruszania siê graczem.
public:
	Enemy();
	virtual void draw() override;
	virtual void setLocation(const grim::Vector2 &location) override;

	sf::Sprite getSprite() const { return this->sprite; }
	int getMoveFlag() const { return this->moveFlag; }
	int getCycle() const { return this->cycle; }
	bool getDirection() const { return this->direction; }
	bool canShoot() const { return this->shoot; }
	bool canMove() const { return this->movable; }

	void setCanMove(const bool move) { this->movable = move; }
	void setCycle(const int cycle) { this->cycle = cycle; }
	void setSprite(int);
	void setCanShoot(const bool shoot) { this->shoot = shoot; }
	void setDirection(const bool direction) { this->direction = direction; }

	void incrementMoveFlag() { this->moveFlag++; }
	void incrementCycle() { this->cycle++; }
	void setMoveFlag() { this->moveFlag = 0; }
private:
	sf::Sprite sprite;
	sf::Text healttText;
	int moveFlag;
	int cycle;
	bool movable;
	bool direction;
	bool shoot;
};