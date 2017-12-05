#pragma once
#include "PlayerController.hpp"
class PercyJacksonController :public PlayerController {
public:
	PercyJacksonController();
	virtual void update(const float &deltaTime, sf::Event &event) override;
private:
	float moveSpeed;
	const float gravity;
	grim::Vector2f velocity;
	unsigned jumpCycle;
	void jump(const float &deltaTime);
	void moveLeft(const float &delta);
	void moveRight(const float &delta);
};