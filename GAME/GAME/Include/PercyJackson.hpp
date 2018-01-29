#pragma once
#include "Player.hpp"
#include "PercyJacksonController.hpp"
class PercyJackson : public Player { // klasa do poruszania siê graczem.
public: 
	PercyJackson();
	virtual void draw() override;
	virtual void setLocation(const grim::Vector2 &location) override;
	virtual void setViewLocation(const grim::Vector2 &viewLocation) override;
	inline void incrementMoveFlag() { moveFlag++; }
	inline void setMoveFlag() { moveFlag = 0; }
	inline int getMoveFlag() const { return moveFlag; }
	void incrementJumpCycle() { jumpCycle++; }
	int getJumpCycle() { return jumpCycle; }
	void setJumpCycle(const int jumpCycle) { this->jumpCycle = jumpCycle; }
	bool getIsLeft() { return isLeft; }
	void setSprite(const bool);
	inline sf::Sprite getSprite() const { return sprite; }
	inline void setIsMenu(const bool isMenu) { this->isMenu = isMenu; }
	inline bool getIsMenu() const { return isMenu; }
	inline void setCanMove(const bool canMove) { this->canMove = canMove; }
	inline bool getCanMove() const { return canMove; }
	inline bool getArrow() const { return isArrow; }
	inline void setArrow(const bool isArrow) { this->isArrow = isArrow; }
	inline void setCanJump(const bool canJump) { this->canJump = canJump; }
	inline bool getCanJump() const { return canJump; }
	inline void setCanShoot(const bool canShoot) { this->canShoot = canShoot; }
	inline bool getCanShoot() const { return canShoot; }
	bool isCollidingWithAnything();
	bool getCanAttack() { return canAttack; }
	void setCanAttack(const bool attack) { this->canAttack = attack; }
	int getAttackCycle() { return attackCycle; }
	void setAttackCycle(const int attackCycle) { this->attackCycle = attackCycle; }
	bool getLoading() { return loading; }
	int getWidth() { return width; }
	void setLoading(const bool loading) { this->loading = loading; }
	void incrementAttackCycle() { attackCycle++; }
	static double getTime(const clock_t time) { return static_cast <double>(time) / CLOCKS_PER_SEC; }

private:
	sf::Sprite sprite;
	sf::Sprite background;
	sf::Sprite loadingScreen;
	int width;
	int moveFlag;
	bool isLeft;
	bool isMenu;
	bool canMove;
	bool canJump;
	bool canShoot;
	int attackCycle;
	bool isArrow;
	bool loading;
	bool canAttack;
	double time;
	unsigned jumpCycle;
	int checkpoint;
};