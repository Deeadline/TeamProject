#pragma once
#include "../Include/ProjectTileController.hpp"
#include "../Include/ProjectTile.hpp"
#include "../Include/GameManager.hpp"

ProjectTileController::ProjectTileController() : moveSpeed(600) {
}

void ProjectTileController::update(const float& deltaTime) {
	if (!GameManager::instance().getPlayer()->isMenu() && !GameManager::instance().getPlayer()->isLoading()) {
		auto* tempTile = dynamic_cast<ProjectTile*>(owner);
		if (tempTile->getDirection())
			tempTile->move(grim::Vector2(-deltaTime*moveSpeed, 0));
		else
			tempTile->move(grim::Vector2(deltaTime*moveSpeed, 0));
		if (tempTile->getType() == 1) {
			for (auto* enemy : GameManager::instance().getLevel()->getEnemies()) {
				if (GameManager::instance().getLevel()->existCharacter(enemy)) {
					if (tempTile->getSprite().getGlobalBounds().intersects(enemy->getSprite().getGlobalBounds())) {
						enemy->setHealth(enemy->getHealthPoint() - tempTile->getDamage());
						tempTile->setDestroyed(true);
						if (enemy->getHealthPoint() <= 0 && GameManager::instance().getLevel()->existCharacter(enemy)) {
							enemy->setDestroyed(true);
						}
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