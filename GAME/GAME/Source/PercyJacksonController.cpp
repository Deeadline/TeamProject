#include "../Include/PercyJackson.hpp"
#include "../Include/GameManager.hpp"
#include "../Include/TextureManager.hpp"
PercyJacksonController::PercyJacksonController() :
	moveSpeed(400) {

}

void PercyJacksonController::update(const float &deltaTime) {
	auto* tempOwner = dynamic_cast<PercyJackson*>(owner);
	if (tempOwner->getIsMenu()) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
			tempOwner->setCanMove(true);
			tempOwner->setIsMenu(false);
		}
	}
	else {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
			((tempOwner->getSprite().getPosition().x + moveSpeed*deltaTime) < 1320)) {
			owner->move(grim::Vector2(moveSpeed * deltaTime, 0));
			tempOwner->incrementMoveFlag();
			tempOwner->setSprite(false);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
			((tempOwner->getSprite().getPosition().x + moveSpeed*deltaTime) > 120)) {
			owner->move(grim::Vector2(-moveSpeed*deltaTime, 0));
			tempOwner->incrementMoveFlag();
			tempOwner->setSprite(true);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			tempOwner->setCanMove(false);
			tempOwner->setIsMenu(true);
		}
	}
}