#pragma once
#include "Player.hpp"

class Enemy : public Player { // klasa do poruszania siê graczem.
public:
	explicit Enemy(const int);
	virtual void draw() override;
	virtual void setLocation(const grim::Vector2 &location) override;
	virtual void setDamage(const int damage) override;
	virtual void setHealth(const int healthPoint) override;
	enum TypeEnemy {
		tutorial = 1,
		rocky = 2,
		medusa = 3
	};

	int getMoveFlag() const { return this->moveFlag; }
	int getCycle() const { return this->cycle; }
	int getAttackCycle() const { return this->attackCycle; }
	bool getDirection() const { return this->direction; }
	bool canShoot() const { return this->shoot; }
	bool canMove() const { return this->movable; }
	TypeEnemy getType() const { return enemyType; }

	void setCanMove(const bool move) { this->movable = move; }
	void setCycle(const int cycle) { this->cycle = cycle; }
	void setAttackCycle(const int cycle) { this->attackCycle = cycle; }
	void setSprite(int);
	void setCanShoot(const bool shoot) { this->shoot = shoot; }
	void setDirection(const bool direction) { this->direction = direction; }

	void incrementMoveFlag() { this->moveFlag++; }
	void incrementCycle() { this->cycle++; }
	void incrementAttackCycle() { this->attackCycle++; }
	void setMoveFlag() { this->moveFlag = 0; }

private:
	sf::Text healttText;
	int moveFlag;
	int cycle;
	int attackCycle;
	bool movable;
	bool direction;
	bool shoot;
	TypeEnemy enemyType;
};