#include "PlayerController.hpp"

PlayerController::PlayerController() :owner(nullptr) {

}

PlayerController::~PlayerController() {

}

bool PlayerController::isPosses(Player *owner) {
	if (!owner) {
		this->owner = owner;
		return true;
	}
	return false;
}