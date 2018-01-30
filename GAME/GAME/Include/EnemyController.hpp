#pragma once
#include "PlayerController.hpp"

class EnemyController :public PlayerController {
public:
	EnemyController();
	virtual void update(const float &deltaTime) override;
private:
	void shoot(const float &deltaTime);
	float moveSpeed;
	unsigned count;
};