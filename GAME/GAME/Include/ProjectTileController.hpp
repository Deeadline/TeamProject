#pragma once
#include "Includers.hpp"
#include "PlayerController.hpp"

class ProjectTileController : public PlayerController {
public:
	ProjectTileController();
	virtual void update(const float &deltaTime) override;
private:
	float moveSpeed;
};

