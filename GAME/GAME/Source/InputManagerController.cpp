#include "../Include/InputManagerController.hpp"

InputManagerController::InputManagerController() {

}

bool InputManagerController::isKeyPressed(const sf::Keyboard::Key key) {
	if (event.key.code == key && event.type == sf::Event::KeyPressed)
		return true;
	return false;
}
bool InputManagerController::isKeyPressed(std::vector<sf::Keyboard::Key> keys) {
	for (int i = 0; i < keys.size(); i++) {
		if (isKeyPressed(keys[i]))
			return true;
	}
	return false;
}

bool InputManagerController::isKeyReleased(const sf::Keyboard::Key key) {
	if (event.key.code == key && event.type == sf::Event::KeyReleased)
		return true;
	return false;
}
bool InputManagerController::isKeyReleased(const std::vector<sf::Keyboard::Key> keys) {
	for (int i = 0; i < keys.size(); i++) {
		if (isKeyReleased(keys[i]))
			return true;
	}
	return false;
}

void InputManagerController::update(const float &deltaTime, sf::Event& event) {
	this->event = event;
}