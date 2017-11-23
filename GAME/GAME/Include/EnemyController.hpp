#pragma once
#include "PlayerController.hpp"
#include "Enemy.hpp"

class EnemyController :public PlayerController {
public:
	EnemyController();
	virtual void update(const float &deltaTime) override;
private:
	float moveSpeed;
};