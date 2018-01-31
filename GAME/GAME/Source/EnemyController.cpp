#include "../Include/EnemyController.hpp"
#include "../Include/GameManager.hpp"
#include "../Include/TextureManager.hpp"
#include "../Include/ProjectTile.hpp"
#include "../Include/Enemy.hpp"

EnemyController::EnemyController() :
	moveSpeed(400), attackCycle(0) {

}

void EnemyController::update(const float &deltaTime) {
	auto* tempOwner = dynamic_cast<Enemy*>(owner);
	if (GameManager::instance().getPlayer()->isMenu()) {
		tempOwner->setCanMove(false);
	}
	else {
		if (GameManager::instance().getPlayer()->getLocation().x > tempOwner->getLocation().x)
			tempOwner->setSprite(1);
		else
			tempOwner->setSprite(-1);
		if (!tempOwner->canShoot())
			shoot(deltaTime);
		else if (tempOwner->canMove() && tempOwner->getLocation().Distance(GameManager::instance().getPlayer()->getLocation()) > 650) {
			if (tempOwner->getCycle() < 50) {
				tempOwner->move(grim::Vector2(deltaTime*moveSpeed / 2, 0));
				tempOwner->incrementMoveFlag();
				if (tempOwner->getMoveFlag() == static_cast<int>(1200.f / 40.f))
					tempOwner->setMoveFlag();
				tempOwner->setSprite(1);
			}
			else {
				tempOwner->move(grim::Vector2(-deltaTime*moveSpeed / 2, 0));
				tempOwner->incrementMoveFlag();
				if (tempOwner->getMoveFlag() == static_cast<int>(1200.f / 40.f))
					tempOwner->setMoveFlag();
				tempOwner->setSprite(-1);
			}
			if (tempOwner->getCycle() == 100)
				tempOwner->setCycle(0);
			else
				tempOwner->incrementCycle();
		}
		if (tempOwner->getLocation().Distance(GameManager::instance().getPlayer()->getLocation()) < 650 && tempOwner->getType() != 1) {
			if (tempOwner->canShoot()) {
				tempOwner->setCanMove(false);
				tempOwner->setCanShoot(false);
				tempOwner->setAttackCycle(0);
				shoot(deltaTime);
			}
		}
	}
}
void EnemyController::shoot(const float& deltaTime) {
	auto* tempOwner = dynamic_cast<Enemy*>(owner);

	tempOwner->incrementAttackCycle();
	if (tempOwner->getAttackCycle() == 18) {
		auto* rock = new ProjectTile(tempOwner->getDirection(), 2, tempOwner->getLocation());
		GameManager::instance().getLevel()->addCharacter(rock);
	}
	if(tempOwner->getAttackCycle()==80) {
		tempOwner->setCanMove(true);
		tempOwner->setCanShoot(true);
	}

}