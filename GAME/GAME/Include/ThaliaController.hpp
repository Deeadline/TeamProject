#pragma once
#include "PlayerController.hpp"
class ThaliaController :public PlayerController {
public:
	ThaliaController();
	virtual void update(const float &deltaTime) override;
private:
	void loading(const float &deltaTime);
	void attack(const float &deltaTime);
	void jump(const float &deltaTime);
	void fall(const float &deltaTime);
	void shoot(const float &deltaTime);

	grim::Vector2f velocity;
	int loadingIncrement;
	float moveSpeed;
	const float gravity;
	unsigned jumpCycle;
	unsigned count;
};