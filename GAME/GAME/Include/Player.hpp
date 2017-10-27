#pragma once
#include "CharacterMechanic.hpp"
#include "PlayerController.hpp"
class PlayerController;
class Player : public CharacterMechanics { // klasa do poruszania siê graczem.
public:
	Player(PlayerController *controller);
	virtual ~Player();
	void resetController(PlayerController *controller);
	virtual void update(const float &deltaTime);
protected:
	PlayerController* controller;
};