#include "../Include/EnemyController.hpp"
#include "../Include/GameManager.hpp"
#include "../Include/TextureManager.hpp"

EnemyController::EnemyController() :
	moveSpeed(400) {

}

void EnemyController::update(const float &deltaTime, sf::Event &event) {
	auto* tempOwner = dynamic_cast<Enemy*>(owner);
	if (GameManager::instance().getPlayer()->getIsMenu()) {
		tempOwner->setCanMove(false);
	}
	else if(tempOwner->getCanMove()){
		tempOwner->move(grim::Vector2(-deltaTime*moveSpeed, 0));
		if (tempOwner->getSprite().getGlobalBounds().intersects(GameManager::instance().getPlayer()->getSprite().getGlobalBounds())) {
			tempOwner->setCanMove(false);
			//zamiast tego bêdzie atakowanie.
		}
		else {
			tempOwner->setCanMove(true);
		}
		tempOwner->incrementMoveFlag();
		if (tempOwner->getMoveFlag() == static_cast<int>(1200.f / 40.f))
			tempOwner->setMoveFlag();
		tempOwner->setSprite();
	}
}