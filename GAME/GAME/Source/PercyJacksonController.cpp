#include "../Include/PercyJackson.hpp"
#include "../Include/GameManager.hpp"
#include "../Include/ProjectTile.hpp"
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
			(tempOwner->getSprite().getPosition().x + moveSpeed*deltaTime) < 3505){
			auto temp = tempOwner->getSprite().getGlobalBounds();
			temp.left += 20;
			temp.top -= 20;
			if (!GameManager::instance().getLevel()->checkCollision(temp)) {
				owner->move(grim::Vector2(moveSpeed * deltaTime, 0));
				if(tempOwner->getSprite().getPosition().x < 2850)
					owner->moveView(grim::Vector2(moveSpeed * deltaTime, 0));
			}
			GameManager::instance().getWindow().setView(GameManager::instance().getViewGame());
			tempOwner->incrementMoveFlag();
			if (tempOwner->getMoveFlag() == static_cast<int>(1200.f / 40.f))
				tempOwner->setMoveFlag();
			tempOwner->setSprite(false);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
			((tempOwner->getSprite().getPosition().x + moveSpeed*deltaTime))>95) {
			auto temp = tempOwner->getSprite().getGlobalBounds();
			temp.left -= 20;
			temp.top -= 20;
			if (!GameManager::instance().getLevel()->checkCollision(temp)) {
				owner->move(grim::Vector2(-moveSpeed*deltaTime, 0));
				if (tempOwner->getSprite().getPosition().x < 2850)
					owner->moveView(grim::Vector2(-moveSpeed*deltaTime, 0));
			}
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
		else {
			fall(deltaTime);
			tempOwner->setSprite(tempOwner->getIsLeft());
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && tempOwner->getCanJump()) { //skok
			tempOwner->setCanJump(false);
			tempOwner->setJumpCycle(0);
			
			velocity.y = -sqrtf(2.f*gravity*moveSpeed);
			jump(deltaTime);
		}
		if((static_cast<int>(tempOwner->getSprite().getPosition().x) > 3000 
			&& sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) && GameManager::instance().getLevelName() != "Medusa") {
			loadingIncrement = 0;
			tempOwner->setLoading(true);
			loading(deltaTime);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			GameManager::instance().getWindow().setView(GameManager::instance().getViewMenu());
			tempOwner->setCanMove(false);
			tempOwner->setIsMenu(true);
		}
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && tempOwner->getCanAttack()) {
			tempOwner->setCanAttack(false);
			tempOwner->setAttackCycle(0);
			attack(deltaTime);
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::X) && tempOwner->getCanShoot()) {
				tempOwner->setArrow(true);
				tempOwner->setCanShoot(false);
				count = 0;
				shoot(deltaTime);
		}
		if (!tempOwner->getCanShoot()) {
			shoot(deltaTime);
		}
		if(!tempOwner->getCanAttack()) {
			attack(deltaTime);
		}
		if(tempOwner->getLoading()) {
			loading(deltaTime);
		}
	}
}

void PercyJacksonController::loading(const float &deltaTime) {
	auto* tempOwner = dynamic_cast<PercyJackson*>(owner);
	loadingIncrement++;
	if (loadingIncrement == 100) {
		tempOwner->setLoading(false);
		GameManager::instance().setLevel("Medusa");
	}
}

void PercyJacksonController::attack(const float &deltaTime) {
	auto* tempOwner = dynamic_cast<PercyJackson*>(owner);
	if (GameManager::instance().getLevel()->existCharacter(GameManager::instance().getEnemy())) {
		if (tempOwner->getSprite().getGlobalBounds().intersects(GameManager::instance().getEnemy()->getSprite().getGlobalBounds())) {
			GameManager::instance().getEnemy()->setHealth(GameManager::instance().getEnemy()->getHealthPoint() - tempOwner->getDamage());
		}
		if (GameManager::instance().getEnemy()->getHealthPoint() <= 0) {
			GameManager::instance().getEnemy()->setDestroyed(true);
		}
	}
	tempOwner->incrementAttackCycle();
	if(tempOwner->getAttackCycle() == 23) {
		tempOwner->setCanAttack(true);
	}
}

void PercyJacksonController::jump(const float &deltaTime) {
	auto* tempOwner = dynamic_cast<PercyJackson*>(owner);
	if (tempOwner->getJumpCycle() > 8 && tempOwner->getJumpCycle() < 23) {
		auto temp = tempOwner->getSprite().getGlobalBounds();
		temp.top -= 20;
		if (!GameManager::instance().getLevel()->checkCollision(temp)) {
			owner->move(velocity*deltaTime);
		}
		else {	
			tempOwner->setJumpCycle(23);
		}
	}
	else if (tempOwner->getJumpCycle() > 33 && tempOwner->getJumpCycle() < 48) {
		auto temp = tempOwner->getSprite().getGlobalBounds();
		temp.top += 10;
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

void PercyJacksonController::fall(const float& deltaTime) {
	auto *tempOwner = dynamic_cast<PercyJackson*>(owner);
	velocity.y = -sqrtf(2.f*gravity*moveSpeed);
	if(tempOwner->getLocation().y < 800) {
		if (!GameManager::instance().getLevel()->checkCollision(tempOwner->getSprite().getGlobalBounds())) {
			owner->move(-velocity*deltaTime);
		}
	}
	if (tempOwner->getLocation().y > 800) {
		auto temp = owner->getLocation();
		temp.y = 800;
		owner->setLocation(temp);
	}
		
}

void PercyJacksonController::shoot(const float& deltaTime) {
	auto* tempOwner = dynamic_cast<PercyJackson*>(owner);
	if (count == 0) {
		auto* arrow = new ProjectTile(tempOwner->getIsLeft(),true);
		GameManager::instance().getLevel()->addCharacter(arrow);
	}

	count++;
	if (count==20) {
		tempOwner->setCanShoot(true);
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

