#pragma once
#include "CharacterMechanic.hpp"
#include "PlayerController.hpp"
class PlayerController;
class Player : public CharacterMechanics { // klasa do poruszania siê graczem.
public:
	Player(PlayerController *controller);
	virtual ~Player();
	void resetController(PlayerController *controller);
	void update(const float &deltaTime, sf::Event &event) override;
	int getHealthPoint() const { return healthPoint; }
	int getDamage() const { return damage; }
	void setDamage(const int damage) { this->damage = damage; }
	void setHealth(const int healthPoint) { this->healthPoint = healthPoint; }
protected:
	PlayerController* controller;
	int healthPoint;
	int damage;
};