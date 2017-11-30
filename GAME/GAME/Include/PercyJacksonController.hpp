#pragma once
//tutaj bêd¹ wykonywane g³ówne akcje postaci, poruszanie siê oraz interakcja z otoczeniem.
#include "PlayerController.hpp"
#include "PercyJackson.hpp"
class PercyJacksonController :public PlayerController {
public:
	PercyJacksonController();
	virtual void update(const float &deltaTime) override;
	void jump(const float &deltaTime);
private:
	float moveSpeed;
	int jumpCycle;
};