#pragma once
#include "PlayerController.hpp"

class MenuManagerController : public PlayerController {
public:
	explicit MenuManagerController();
	virtual void update(const float &deltaTime) override;

private:

};