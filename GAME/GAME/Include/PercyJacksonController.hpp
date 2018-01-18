#pragma once
#include "PlayerController.hpp"
class PercyJacksonController :public PlayerController {
public:
	PercyJacksonController();
	virtual void update(const float &deltaTime, sf::Event &event) override;
private:
	int loadingIncrement;
	float moveSpeed;
	const float gravity;
	grim::Vector2f velocity;
	unsigned jumpCycle;
	unsigned count;
	void loading(const float &deltaTime);
	void attack(const float &deltaTime);
	void jump(const float &deltaTime);
	void fall(const float &deltaTime);
	void shoot(const float &deltaTime);
	void moveLeft(const float &delta);
	void moveRight(const float &delta);
};