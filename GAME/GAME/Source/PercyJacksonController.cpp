#include "../Include/PercyJackson.hpp"
#include "../Include/GameManager.hpp"
#include "../Include/TextureManager.hpp"
PercyJacksonController::PercyJacksonController() :
	moveSpeed(300.f){
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
		if (!tempOwner->getCanJump()) { //je¿eli postaæ jest w trakcie skoku, wykona sie funkcja jump
			jump(deltaTime);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && tempOwner->getCanJump()) { //skok
			tempOwner->setCanJump(false);
			jumpCycle = -15;
			jump(deltaTime);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
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
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			GameManager::instance().getWindow().setView(GameManager::instance().getViewMenu());
			tempOwner->setCanMove(false);
			tempOwner->setIsMenu(true);
		}
	}
}

void PercyJacksonController::jump(const float &deltaTime) {
	auto* tempOwner = dynamic_cast<PercyJackson*>(owner);
	float velocity = (float)pow((abs((float)jumpCycle) / 10) + 1, 1.5) ;
	std::cout << jumpCycle << ", " << velocity << std::endl;
	if (jumpCycle < 0) {
		owner->move(grim::Vector2(0, deltaTime * -moveSpeed * velocity));
	}
	else if(jumpCycle > 0){
		owner->move(grim::Vector2(0, deltaTime * moveSpeed * velocity));
	}
	jumpCycle++;
	if (jumpCycle == 16) {
		tempOwner->setCanJump(true);
	}
}