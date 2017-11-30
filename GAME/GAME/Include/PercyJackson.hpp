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
	inline int getMoveFlag() { return moveFlag; }
	inline void setJumpFlagUp(const bool a) { jumpFlagUp = a; }
	inline bool getJumpFlagUp() { return jumpFlagUp; }

	void setCanJump(const bool canJump) { this->canJump = canJump; }
	inline bool getCanJump() { return canJump; }

	void setSprite(bool);
	inline sf::Sprite getSprite() const { return sprite; }
	inline void setIsMenu(const bool isMenu) { this->isMenu = isMenu; }
	inline bool getIsMenu() const { return isMenu; }
	inline bool getIsLeft() const { return isLeft; }
	inline void setCanMove(const bool canMove) { this->canMove = canMove; }
	inline bool getCanMove() const { return canMove; }
  
	inline void setCanJump(bool canJump) { this->canJump = canJump; }
	inline bool getCanJump() const { return canJump; }

	double getTime(clock_t time) { return static_cast <double>(time) / CLOCKS_PER_SEC; }
	static double getTime(const clock_t time) { return static_cast <double>(time) / CLOCKS_PER_SEC; }
private:
	sf::Sprite sprite;
	sf::Sprite background;
	int moveFlag;
	bool jumpFlagUp;
	bool canJump;
	bool isMenu;
	bool canMove;
	bool canJump;
	double time;
	bool isLeft;
};