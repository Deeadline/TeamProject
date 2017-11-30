#pragma once
#include "PlayerController.hpp"
#include "Enemy.hpp"

class EnemyController :public PlayerController {
public:
	EnemyController();
	virtual void update(const float &deltaTime, sf::Event &event) override;
private:
	float moveSpeed;
};