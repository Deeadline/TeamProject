#pragma once
#include "../Include/ProjectTile.hpp"
#include "../Include/ProjectTileController.hpp"
#include "../Include/GameManager.hpp"
#include "../Include/TextureManager.hpp"
ProjectTile::ProjectTile(const bool direction, const bool tOwner) : Player(new ProjectTileController),
direction(direction), tOwner(tOwner), hit(false) {
	if (tOwner) {
		ProjectTile::setLocation(GameManager::instance().getPlayer()->getLocation());
		sprite.setTexture(*TextureManager::getTexture("Arrow"));
	}
	else {
		ProjectTile::setLocation(GameManager::instance().getEnemy()->getLocation());
		sprite.setTexture(*TextureManager::getTexture("RockThrowing"));
	}
}

void ProjectTile::draw() {
	!direction ? sprite.setScale(1, 1) : sprite.setScale(-1, 1);
	GameManager::instance().getWindow().draw(sprite);
}

void ProjectTile::setLocation(const grim::Vector2& location) {
	Player::setLocation(location);
	!direction ? sprite.setPosition(location.x + 100, location.y) : sprite.setPosition(location.x - 100, location.y);
}