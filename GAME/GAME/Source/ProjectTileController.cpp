#pragma once
#include "../Include/ProjectTileController.hpp"
#include "../Include/ProjectTile.hpp"
#include "../Include/GameManager.hpp"

ProjectTileController::ProjectTileController() : moveSpeed(600) {
}

void ProjectTileController::update(const float& deltaTime) {
	if (!GameManager::instance().getPlayer()->isLoading()) {
		auto* tempTile = dynamic_cast<ProjectTile*>(owner);
		if (tempTile->getDirection())
			tempTile->move(grim::Vector2(-deltaTime*moveSpeed, 0));
		else
			tempTile->move(grim::Vector2(deltaTime*moveSpeed, 0));
		if (tempTile->getOwner()) {
			if (GameManager::instance().getLevel()->existCharacter(GameManager::instance().getEnemy())) {
				if (tempTile->getSprite().getGlobalBounds().intersects(GameManager::instance().getEnemy()->getSprite().getGlobalBounds())) {
					GameManager::instance().getEnemy()->setHealth(GameManager::instance().getEnemy()->getHealthPoint() - tempTile->getDamage());
					tempTile->setDestroyed(true);
					if (GameManager::instance().getEnemy()->getHealthPoint() <= 0 && GameManager::instance().getLevel()->existCharacter(GameManager::instance().getEnemy())) {
						GameManager::instance().getEnemy()->setDestroyed(true);
					}
				}
			}
		}
		else {
			if (tempTile->getSprite().getGlobalBounds().intersects(GameManager::instance().getPlayer()->getSprite().getGlobalBounds())) {
				GameManager::instance().getPlayer()->setHealth(GameManager::instance().getPlayer()->getHealthPoint() - tempTile->getDamage());
				tempTile->setDestroyed(true);
			}
		}
	}
}