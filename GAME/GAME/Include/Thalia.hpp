#pragma once
#include "Player.hpp"

class Thalia : public Player {
public:
	Thalia();

	virtual void draw() override;
	virtual void setLocation(const grim::Vector2 &location) override;
	virtual void setViewLocation(const grim::Vector2 &viewLocation) override;
	virtual void setDamage(const int damage) override;
	virtual void setHealth(const int healthPoint) override;

	sf::Text getText(const int number) const { return texts[number]; }
	int getMoveFlag() const { return moveFlag; }
	int getJumpCycle() { return jumpCycle; }
	int getAttackCycle() const { return attackCycle; }
	int getWidth() const { return width; }
	int getCheckpoint() const { return checkpoint; }
	bool direction() { return direct; }
	bool isMenu() const { return menu; }
	bool canMove() const { return movable; }
	bool canJump() const { return jump; }
	bool canShoot() const { return shoot; }
	bool canAttack() const { return attack; }
	bool isLoading() const { return loading; }
	bool isCollidingWithAnything();

	void setMoveFlag() { moveFlag = 0; }
	void setCheckpoint(const int checkpoint) { this->checkpoint = checkpoint; }
	void setJumpCycle(const int jumpCycle) { this->jumpCycle = jumpCycle; }
	void setMenu(const bool menu) { this->menu = menu; }
	void setMove(const bool movable) { this->movable = movable; }
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
	sf::Sprite background;
	sf::Sprite loadingScreen;
	sf::Text texts[4];
	sf::Font font;

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

	void setTexts();
};
