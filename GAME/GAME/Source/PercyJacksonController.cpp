#include "../Include/PercyJackson.hpp"
#include "../Include/GameManager.hpp"
PercyJacksonController::PercyJacksonController() :
	moveSpeed(300.f), gravity(0,981.f) {
}

void PercyJacksonController::update(const float &deltaTime, sf::Event &event) {
	auto* tempOwner = dynamic_cast<PercyJackson*>(owner);
	if (tempOwner->getIsMenu()) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
			GameManager::instance().getWindow().setView(GameManager::instance().getViewGame());
			tempOwner->setCanMove(true);
			tempOwner->setIsMenu(false);
		}
	}
	/*else if (tempOwner->getJumpFlag()) {
		if (tempOwner->getJumpFlagUp()) {
			tempOwner->setLocation(grim::Vector2(tempOwner->getLocation().x, tempOwner->getLocation().y - 10));
			if (tempOwner->getLocation().y <= 650) {
				tempOwner->setJumpFlagUp(false);
			}
		}
		else {
			tempOwner->setLocation(grim::Vector2(tempOwner->getLocation().x, tempOwner->getLocation().y + 10));
			if (tempOwner->getLocation().y >= 800) {
				tempOwner->setJumpFlag(false);
			}
		}
	}*/
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
		if (!tempOwner->getCanJump()) { //je¿eli postaæ jest w trakcie skoku, wykona sie funkcja jump
			jump(deltaTime);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && tempOwner->getCanJump()) { //skok
			tempOwner->setCanJump(false);
			jumpCycle = 0;
			jump(deltaTime);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			GameManager::instance().getWindow().setView(GameManager::instance().getViewMenu());
			tempOwner->setCanMove(false);
			tempOwner->setIsMenu(true);
		}
	}
}

void PercyJacksonController::jump(const float &deltaTime) {
	auto* tempOwner = dynamic_cast<PercyJackson*>(owner);
	if (jumpCycle < 20) {
		owner->move(grim::Vector2(0, -moveSpeed*deltaTime * 2));
	}
	else {
		owner->move(grim::Vector2(0, moveSpeed*deltaTime * 2));
	}
	jumpCycle++;
	if (jumpCycle == 40) {
		tempOwner->setCanJump(true);
	}
}