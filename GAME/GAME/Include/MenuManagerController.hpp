#pragma once
#include "PlayerController.hpp"
#include "MenuManager.hpp"

class MenuManagerController : public PlayerController {
public:
	MenuManagerController();
	virtual void update(const float &deltaTime) override;

private:
	
};