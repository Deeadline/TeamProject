#include "Player.hpp"

Player::Player(PlayerController *owner) :controller(nullptr) {
	if (controller && controller->isPosses(this)) {
		this->controller = controller;
	}
}

Player::~Player() {
	if (this->controller) {
		delete (this->controller);
	}
}

void Player::resetController(PlayerController *controller) {
	if (controller != this->controller) {
		if (this->controller) {
			delete (this->controller);
		}
		if (controller && controller->isPosses(this)) {
			this->controller = controller;
		}
		else {
			this->controller = nullptr;
		}
	}
}

void Player::update(const float &deltaTime) {
	if (this->controller) {
		this->controller->update(deltaTime);
	}
}