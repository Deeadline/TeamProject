#include "..\Include\Player.hpp"

Player::Player(PlayerController *controller) :controller(nullptr) {
	if (controller && controller->isPossess(this)) {
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
		if (controller && controller->isPossess(this)) {
			this->controller = controller;
		}
		else {
			this->controller = nullptr;
		}
	}
}

void Player::update(const float &deltaTime, sf::Event &event) {
	
	if (this->controller) {
		this->controller->update(deltaTime, event);
	}
}