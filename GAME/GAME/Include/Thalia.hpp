#pragma once
#include "Player.hpp"

class Thalia : public Player {
public:
	Thalia();

	virtual void draw() override;
	virtual void setLocation(const grim::Vector2 &location) override;
	virtual void setViewLocation(const grim::Vector2 &viewLocation) override;

	sf::Sprite getSprite() const { return sprite; }
	int getMoveFlag() const { return moveFlag; }
	int getJumpCycle() { return jumpCycle; }
	int getAttackCycle() const { return attackCycle; }
	int getWidth() const { return width; }
	bool direction() { return direct; }
	bool isMenu() const { return menu; }
	bool canMove() const { return movable; }
	bool getArrow() const { return isArrow; }
	bool canJump() const { return jump; }
	bool canShoot() const { return shoot; }
	bool canAttack() const { return attack; }
	bool isLoading() const { return loading; }
	bool isCollidingWithAnything();

	void setMoveFlag() { moveFlag = 0; }
	void setJumpCycle(const int jumpCycle) { this->jumpCycle = jumpCycle; }
	void setMenu(const bool menu) { this->menu = menu; }
	void setMove(const bool movable) { this->movable = movable; }
	void setArrow(const bool isArrow) { this->isArrow = isArrow; }
	void setJump(const bool canJump) { this->jump = canJump; }
	void setShoot(const bool shoot) { this->shoot = shoot; }
	void setAttack(const bool attack) { this->attack = attack; }
	void setAttackCycle(const int attackCycle) { this->attackCycle = attackCycle; }
	void setLoading(const bool loading) { this->loading = loading; }
	void setSprite(const bool);

	void incrementMoveFlag() { moveFlag++; }
	void incrementJumpCycle() { jumpCycle++; }
	void incrementAttackCycle() { attackCycle++; }

private:
	sf::Sprite sprite;
	sf::Sprite background;
	sf::Sprite loadingScreen;

	int width;
	int moveFlag;
	int attackCycle;
	int jumpCycle;
	int checkpoint;
	bool isArrow;
	bool loading;
	bool attack;
	bool direct;
	bool menu;
	bool movable;
	bool jump;
	bool shoot;
};