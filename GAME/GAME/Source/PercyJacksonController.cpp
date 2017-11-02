#include "../Include/PercyJackson.hpp"
#include "../Include/GameManager.hpp"
#include "../Include/TextureManager.hpp"
PercyJacksonController::PercyJacksonController() :
	moveSpeed(200)
{

}

void PercyJacksonController::update(const float &deltaTime) {
	auto* tempOwner = dynamic_cast<PercyJackson*>(owner);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && 
		((tempOwner->getSprite().getPosition().x+moveSpeed*deltaTime) < 1440-32)) {
		owner->move(grim::Vector2(moveSpeed * deltaTime, 0));
		tempOwner->incrementMoveFlag();
		tempOwner->setSprite(false);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
		((tempOwner->getSprite().getPosition().x + moveSpeed*deltaTime) > 32)) {
		owner->move(grim::Vector2(-moveSpeed*deltaTime, 0));
		tempOwner->incrementMoveFlag();
		tempOwner->setSprite(true);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		GameManager::instance().setStatus(GameManager::cleaningUp);
	}
}