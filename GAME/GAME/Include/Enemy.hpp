#pragma once
#include "Player.hpp"

class Enemy : public Player { // klasa do poruszania siê graczem.
public:
	Enemy();
	virtual void draw() override;
	virtual void setLocation(const grim::Vector2 &location) override;
	inline void incrementMoveFlag() { moveFlag++; }
	inline void incrementCycle() { cycle++; }
	inline void setMoveFlag() { moveFlag = 0; }
	inline int getMoveFlag() const { return moveFlag; }
	inline void setCanMove(const bool type) { canMove = type; }
	inline bool getCanMove() const { return canMove; }
	inline void setCycle(const int cycle) { this->cycle = cycle; }
	inline int getCycle() const { return cycle; }
	void setSprite(int);
	inline void setCanShoot(const bool canShoot) { this->canShoot = canShoot; }
	inline bool getCanShoot() const { return canShoot; }
	inline sf::Sprite getSprite() const { return sprite; }
private:
	int moveFlag;
	int cycle;
	bool canMove;
	bool canShoot;
	sf::Sprite sprite;
	sf::Text healttText;
	void setString();
};