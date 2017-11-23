#include "../Include/PercyJackson.hpp"
#include "../Include/GameManager.hpp"
#include "../Include/TextureManager.hpp"
PercyJacksonController::PercyJacksonController() :
	moveSpeed(300.f), gravity(0,300) {

}

void PercyJacksonController::update(const float &deltaTime) {
	auto* tempOwner = dynamic_cast<PercyJackson*>(owner);
	if (tempOwner->getIsMenu()) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
			GameManager::instance().getWindow().setView(GameManager::instance().getViewGame());
			tempOwner->setCanMove(true);
			tempOwner->setIsMenu(false);
		}
	}
	else {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
			((tempOwner->getSprite().getPosition().x + moveSpeed*deltaTime))) {
			owner->move(grim::Vector2(moveSpeed * deltaTime, 0));
			owner->moveView(grim::Vector2(moveSpeed * deltaTime, 0));
			GameManager::instance().getWindow().setView(GameManager::instance().getViewGame());
			tempOwner->incrementMoveFlag();
			if (tempOwner->getMoveFlag() == static_cast<int>(1200.f / 40.f))
				tempOwner->setMoveFlag();
			tempOwner->setSprite(false);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			//skok

			jump(grim::Vector2(0,-200));
			jumpForce += gravity * deltaTime;
			if (tempOwner->getLocation().y > 360 && jumpForce.y > 0) {
				jumpForce.y = 0;
				tempOwner->setLocation(grim::Vector2(tempOwner->getLocation().x, 360));
			}
			owner->move(grim::Vector2(jumpForce.x*deltaTime, jumpForce.y*deltaTime));
			

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
			((tempOwner->getSprite().getPosition().x + moveSpeed*deltaTime))>95) {
			owner->move(grim::Vector2(-moveSpeed*deltaTime, 0));
			owner->moveView(grim::Vector2(-moveSpeed*deltaTime, 0));
			GameManager::instance().getWindow().setView(GameManager::instance().getViewGame());
			tempOwner->incrementMoveFlag();
			if (tempOwner->getMoveFlag() == static_cast<int>(1200.f/40.f))
				tempOwner->setMoveFlag();
			tempOwner->setSprite(true);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			GameManager::instance().getWindow().setView(GameManager::instance().getViewMenu());
			tempOwner->setCanMove(false);
			tempOwner->setIsMenu(true);
		}
	}
}
void PercyJacksonController::jump(const grim::Vector2 &delta) {
	jumpForce += delta;
}