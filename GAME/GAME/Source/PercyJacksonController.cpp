#include "../Include/PercyJackson.hpp"
#include "../Include/GameManager.hpp"
#include "../Include/TextureManager.hpp"
PercyJacksonController::PercyJacksonController() :
	moveSpeed(200)
{

}

void PercyJacksonController::update(const float &deltaTime) {
	auto* tempOwner = dynamic_cast<PercyJackson*>(owner);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		owner->move(grim::Vector2(moveSpeed * deltaTime, 0));
		tempOwner->incrementMoveFlag();
		tempOwner->setSprite();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		owner->move(grim::Vector2(-moveSpeed*deltaTime, 0));
	}
}