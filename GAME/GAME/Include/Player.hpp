#pragma once
#include "CharacterMechanic.hpp"
#include "PlayerController.hpp"
class PlayerController;
class Player : public CharacterMechanics { // klasa do poruszania siê graczem.
public:
	explicit Player(PlayerController *controller);
	virtual ~Player();
	void resetController(PlayerController *controller);
	void update(const float &deltaTime) override;
protected:
	PlayerController* controller;

};