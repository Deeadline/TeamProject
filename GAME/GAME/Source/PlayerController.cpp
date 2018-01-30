#include "../Include/PlayerController.hpp"

PlayerController::PlayerController() :owner(nullptr) {

}

PlayerController::~PlayerController() {

}

bool PlayerController::isPossess(Player *owner) {
	if (!this->owner) {
		this->owner = owner;
		return true;
	}
	return false;
}