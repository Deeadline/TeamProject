#pragma once
//tutaj b�d� wykonywane g��wne akcje postaci, poruszanie si� oraz interakcja z otoczeniem.
#include "PlayerController.hpp"
#include "PercyJackson.hpp"
class PercyJacksonController :public PlayerController {
public:
	PercyJacksonController();
	virtual void update(const float &deltaTime) override;
	void jump(const grim::Vector2 &delta);
private:
	float moveSpeed;
	const grim::Vector2 gravity;
	grim::Vector2 jumpForce;
};