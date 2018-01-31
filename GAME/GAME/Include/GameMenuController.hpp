#pragma once
#include "PlayerController.hpp"

class GameMenuController : public PlayerController {
public:
	explicit GameMenuController();
	virtual void update(const float &deltaTime) override;

private:

};