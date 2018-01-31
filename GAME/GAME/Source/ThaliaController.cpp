#include "../Include/Thalia.hpp"
#include "../Include/GameManager.hpp"
#include "../Include/ProjectTile.hpp"
#include "../Include/ThaliaController.hpp"
#include "../Include/GameMenu.hpp"

ThaliaController::ThaliaController() : velocity(0, 0), loadingIncrement(0), moveSpeed(300.f),
                                       gravity(981.f), jumpCycle(0), count(0) {
}

void ThaliaController::update(const float &deltaTime) {
	auto* tempOwner = dynamic_cast<Thalia*>(owner);
	if (tempOwner->isMenu()) {
//		{
//			auto* gameMenu = new GameMenu();
//			GameManager::instance().getLevel()->addCharacter(gameMenu);
//			if (gameMenu->isDestroyed()) {
//				GameManager::instance().getWindow().setView(GameManager::instance().getViewGame());
//				tempOwner->setMove(true);
//				tempOwner->setMenu(false);
//			}
//		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
			GameManager::instance().getWindow().setView(GameManager::instance().getViewGame());
			tempOwner->setMove(true);
			tempOwner->setMenu(false);
		}
		
	}
	else {
		if (tempOwner->canShoot()) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) &&
				tempOwner->getSprite().getPosition().x + moveSpeed*deltaTime < tempOwner->getWidth()) {
				auto temp = tempOwner->getSprite().getGlobalBounds();
				temp.left += 20;
				temp.top -= 20;
				if (!GameManager::instance().getLevel()->checkCollision(temp)) {
					owner->move(grim::Vector2(moveSpeed * deltaTime, 0));
					if (tempOwner->getSprite().getPosition().x < tempOwner->getWidth() - 300)
						owner->moveView(grim::Vector2(moveSpeed * deltaTime, 0));
				}
				GameManager::instance().getWindow().setView(GameManager::instance().getViewGame());
				tempOwner->incrementMoveFlag();
				if (tempOwner->getMoveFlag() == static_cast<int>(1200.f / 40.f))
					tempOwner->setMoveFlag();
				tempOwner->setSprite(false);
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) &&
				tempOwner->getSprite().getPosition().x + moveSpeed*deltaTime > 95) {
				auto temp = tempOwner->getSprite().getGlobalBounds();
				temp.left -= 20;
				temp.top -= 20;
				if (!GameManager::instance().getLevel()->checkCollision(temp)) {
					owner->move(grim::Vector2(-moveSpeed*deltaTime, 0));
					if (tempOwner->getSprite().getPosition().x < tempOwner->getWidth() - 300)
						owner->moveView(grim::Vector2(-moveSpeed*deltaTime, 0));
				}
				GameManager::instance().getWindow().setView(GameManager::instance().getViewGame());
				tempOwner->incrementMoveFlag();
				if (tempOwner->getMoveFlag() == static_cast<int>(1200.f / 40.f))
					tempOwner->setMoveFlag();
				tempOwner->setSprite(true);
			}
		}
		if (!tempOwner->canJump()) {
			jump(deltaTime);
			tempOwner->setSprite(tempOwner->direction());
		}
		else {
			fall(deltaTime);
			tempOwner->setSprite(tempOwner->direction());
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && tempOwner->canJump()) { //skok
			tempOwner->setJump(false);
			tempOwner->setJumpCycle(0);

			velocity.y = -sqrtf(2.f*gravity*moveSpeed);
			jump(deltaTime);
		}
		if (static_cast<int>(tempOwner->getSprite().getPosition().x) > 3000
			&& sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && GameManager::instance().getLevelName() != "Medusa" || sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
			loadingIncrement = 0;
			tempOwner->setLoading(true);
			loading(deltaTime);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			GameManager::instance().getWindow().setView(GameManager::instance().getViewMenu());
			tempOwner->setMove(false);
			tempOwner->setMenu(true);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && tempOwner->canAttack()) {
			tempOwner->setAttack(false);
			tempOwner->setAttackCycle(0);
			attack(deltaTime);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X) && tempOwner->canShoot() &&
			(GameManager::instance().getLevelName() != "Introduce" || tempOwner->getCheckpoint() > 2)) {
			tempOwner->setShoot(false);
			tempOwner->setAttackCycle(0);
			shoot(deltaTime);
		}
		if (!tempOwner->canShoot()) {
			shoot(deltaTime);
		}
		if (!tempOwner->canAttack()) {
			attack(deltaTime);
		}
		if (tempOwner->isLoading()) {
			loading(deltaTime);
		}
	}
}

void ThaliaController::loading(const float &deltaTime) {
	auto* tempOwner = dynamic_cast<Thalia*>(owner);
	loadingIncrement++;
	if (loadingIncrement == 100) {
		tempOwner->setLoading(false);
		GameManager::instance().setLevel("Medusa", false);
	}
}

void ThaliaController::attack(const float &deltaTime) {
	auto* tempOwner = dynamic_cast<Thalia*>(owner);
	for (auto* enemy : GameManager::instance().getLevel()->getEnemies()) {
		if (GameManager::instance().getLevel()->existCharacter(enemy)) {
			if (tempOwner->getSprite().getGlobalBounds().intersects(enemy->getSprite().getGlobalBounds())) {
				enemy->setHealth(enemy->getHealthPoint() - tempOwner->getDamage());
			}
			if (enemy->getHealthPoint() <= 0) {
				enemy->setDestroyed(true);
			}
		}
	}
	tempOwner->incrementAttackCycle();
	if (tempOwner->getAttackCycle() == 23) {
		tempOwner->setAttack(true);
	}
}

void ThaliaController::jump(const float &deltaTime) {
	auto* tempOwner = dynamic_cast<Thalia*>(owner);
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
		tempOwner->setJump(true);
	}
}

void ThaliaController::fall(const float& deltaTime) {
	auto *tempOwner = dynamic_cast<Thalia*>(owner);
	velocity.y = -sqrtf(2.f*gravity*moveSpeed);
	if (tempOwner->getLocation().y < 800) {
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

void ThaliaController::shoot(const float& deltaTime) {
	auto* tempOwner = dynamic_cast<Thalia*>(owner);
		
	if (tempOwner->getAttackCycle() == 16) {
		auto* arrow = new ProjectTile(tempOwner->direction(), 1 ,tempOwner->getLocation());
		GameManager::instance().getLevel()->addCharacter(arrow);
	}

	tempOwner->incrementAttackCycle();
	if (tempOwner->getAttackCycle() == 27) {
		tempOwner->setShoot(true);
	}
}