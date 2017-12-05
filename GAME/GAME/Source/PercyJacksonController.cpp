#include "../Include/PercyJackson.hpp"
#include "../Include/GameManager.hpp"
PercyJacksonController::PercyJacksonController() :	moveSpeed(300.f), gravity(981.f),velocity(0,0),jumpCycle(0) {
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
	else {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
			(tempOwner->getSprite().getPosition().x + moveSpeed*deltaTime)){
			//this->moveRight(moveSpeed*deltaTime);
			auto temp = tempOwner->getSprite().getGlobalBounds();
			temp.left += 10;
			if (!GameManager::instance().getLevel()->checkCollision(temp)) {
				owner->move(grim::Vector2(moveSpeed * deltaTime, 0));
				owner->moveView(grim::Vector2(moveSpeed * deltaTime, 0));
			}
			//	std::cout << "X: " << tempOwner->getLocation().x << " Y: " << tempOwner->getLocation().y << std::endl;
			GameManager::instance().getWindow().setView(GameManager::instance().getViewGame());
			tempOwner->incrementMoveFlag();
			if (tempOwner->getMoveFlag() == static_cast<int>(1200.f / 40.f))
				tempOwner->setMoveFlag();
			tempOwner->setSprite(false);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
			((tempOwner->getSprite().getPosition().x + moveSpeed*deltaTime))>95) {
			//this->moveLeft(-moveSpeed*deltaTime);
			auto temp = tempOwner->getSprite().getGlobalBounds();
			temp.left -= 10;
			if (!GameManager::instance().getLevel()->checkCollision(temp)) {
				owner->move(grim::Vector2(-moveSpeed*deltaTime, 0));
				owner->moveView(grim::Vector2(-moveSpeed*deltaTime, 0));
			}
			//	std::cout << "X: " << tempOwner->getLocation().x << " Y: " << tempOwner->getLocation().y << std::endl;
			GameManager::instance().getWindow().setView(GameManager::instance().getViewGame());
			tempOwner->incrementMoveFlag();
			if (tempOwner->getMoveFlag() == static_cast<int>(1200.f/40.f))
				tempOwner->setMoveFlag();
			tempOwner->setSprite(true);
		}
		if (!tempOwner->getCanJump()) { //jeżeli postać jest w trakcie skoku, wykona sie funkcja jump
			jump(deltaTime);
			tempOwner->setSprite(tempOwner->getIsLeft());
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && tempOwner->getCanJump()) { //skok
			tempOwner->setCanJump(false);
			tempOwner->setJumpCycle(0);
			
			velocity.y = -sqrtf(2.f*gravity*moveSpeed);
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
	if (tempOwner->getJumpCycle() > 8 && tempOwner->getJumpCycle() < 23) {
		auto temp = tempOwner->getSprite().getGlobalBounds();
		temp.top -= 10;
		if (!GameManager::instance().getLevel()->checkCollision(temp)) {
			owner->move(velocity*deltaTime);
		}
		else {
			tempOwner->setJumpCycle(23);
		}
	}
	else if (tempOwner->getJumpCycle() > 33 && tempOwner->getJumpCycle() < 48) {
		auto temp = tempOwner->getSprite().getGlobalBounds();
		temp.top += 15;
		if (!GameManager::instance().getLevel()->checkCollision(temp) && tempOwner->getLocation().y < 800) {
			owner->move(-velocity*deltaTime);
		}
		else {
			tempOwner->setJumpCycle(48);
		}
	}

	tempOwner->incrementJumpCycle();

	if (tempOwner->getJumpCycle() == 56) {
		tempOwner->setCanJump(true);
	}
}

void PercyJacksonController::moveLeft(const float& delta) {
	auto* tempOwner = dynamic_cast<PercyJackson*>(owner);
	owner->move(grim::Vector2(-delta, 0));
	owner->moveView(grim::Vector2(-delta, 0));
	if(tempOwner->isCollidingWithAnything()) {
		owner->move(grim::Vector2(delta, 0));
		owner->moveView(grim::Vector2(delta, 0));
	}
	//	std::cout << "X: " << tempOwner->getLocation().x << " Y: " << tempOwner->getLocation().y << std::endl;
	GameManager::instance().getWindow().setView(GameManager::instance().getViewGame());
	tempOwner->incrementMoveFlag();
	if (tempOwner->getMoveFlag() == static_cast<int>(1200.f / 40.f))
	tempOwner->setMoveFlag();
	tempOwner->setSprite(true);
}

void PercyJacksonController::moveRight(const float& delta) {
	auto* tempOwner = dynamic_cast<PercyJackson*>(owner);
	owner->move(grim::Vector2(delta, 0));
	owner->moveView(grim::Vector2(delta, 0));
	if(tempOwner->isCollidingWithAnything()) {
		owner->move(grim::Vector2(-delta, 0));
		owner->moveView(grim::Vector2(-delta, 0));
	}
	//	std::cout << "X: " << tempOwner->getLocation().x << " Y: " << tempOwner->getLocation().y << std::endl;
	GameManager::instance().getWindow().setView(GameManager::instance().getViewGame());
	tempOwner->incrementMoveFlag();
	if (tempOwner->getMoveFlag() == static_cast<int>(1200.f / 40.f))
		tempOwner->setMoveFlag();
	tempOwner->setSprite(false);
}

