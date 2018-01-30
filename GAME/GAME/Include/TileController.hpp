#pragma once
#include "PlayerController.hpp"

class TileController : public PlayerController {
public:
	TileController();
	virtual void update(const float &deltaTime) override;
private:

};

