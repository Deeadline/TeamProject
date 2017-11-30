#pragma once
#include "PlayerController.hpp"
class PercyJacksonController :public PlayerController {
public:
	PercyJacksonController();
	virtual void update(const float &deltaTime, sf::Event &event) override;
private:
	float moveSpeed;
	const grim::Vector2f gravity;
	grim::Vector2 velocity;
	unsigned jumpCycle;
	void jump(const float &deltaTime);
};