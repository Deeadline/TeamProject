#include "../Include/EnemyController.hpp"
#include "../Include/GameManager.hpp"
#include "../Include/TextureManager.hpp"
#include "../Include/ProjectTile.hpp"

EnemyController::EnemyController() :
	moveSpeed(400) {

}

void EnemyController::update(const float &deltaTime, sf::Event &event) {
	auto* tempOwner = dynamic_cast<Enemy*>(owner);
	if (GameManager::instance().getPlayer()->getIsMenu()) {
		tempOwner->setCanMove(false);
	}
	else if (tempOwner->getCanMove()) {
		if (tempOwner->getLocation().Distance(GameManager::instance().getPlayer()->getLocation()) > 800) {
			if(tempOwner->getCycle() < 100) {
				tempOwner->move(grim::Vector2(deltaTime*moveSpeed / 2, 0));
				//std::cout << "Dist: " << tempOwner->getLocation().Distance(GameManager::instance().getPlayer()->getLocation()) << std::endl;
				tempOwner->incrementMoveFlag();
				if (tempOwner->getMoveFlag() == static_cast<int>(1200.f / 40.f))
					tempOwner->setMoveFlag();
				tempOwner->setSprite(1);
			}
			else {
				tempOwner->move(grim::Vector2(-deltaTime*moveSpeed / 2, 0));
				//std::cout << "Dist: " << tempOwner->getLocation().Distance(GameManager::instance().getPlayer()->getLocation()) << std::endl;
				tempOwner->incrementMoveFlag();
				if (tempOwner->getMoveFlag() == static_cast<int>(1200.f / 40.f))
					tempOwner->setMoveFlag();
				tempOwner->setSprite(-1);
			}
			if (tempOwner->getCycle() == 200)
				tempOwner->setCycle(0);
			else
				tempOwner->incrementCycle();
		}
		else {
			shoot(deltaTime);
			if (tempOwner->getCanShoot()) {
				tempOwner->setCanShoot(false);
				count = 0;
			}
		}
	}
}
void EnemyController::shoot(const float& deltaTime) {
	auto* tempOwner = dynamic_cast<Enemy*>(owner);
	if (count == 0) {
		auto* arrow = new ProjectTile(true,false);
		GameManager::instance().getLevel()->addCharacter(arrow);
	}
	count++;
	if (count == 100) {
		tempOwner->setCanShoot(true);
	}
}