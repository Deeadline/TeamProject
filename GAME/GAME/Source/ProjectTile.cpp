#pragma once
#include "../Include/ProjectTile.hpp"
#include "../Include/ProjectTileController.hpp"
#include "../Include/GameManager.hpp"
#include "../Include/TextureManager.hpp"
ProjectTile::ProjectTile(const bool direction, const bool tOwner) : Player(new ProjectTileController), direction(direction), hit(false), tOwner(tOwner){
	(tOwner) ? setLocation(GameManager::instance().getPlayer()->getLocation()) : setLocation(GameManager::instance().getEnemy()->getLocation());
	sprite.setTexture(*TextureManager::getTexture("Arrow"));
}

void ProjectTile::draw() {
	(!direction) ? sprite.setScale(1, 1) : sprite.setScale(-1, 1);
		GameManager::instance().getWindow().draw(sprite);
}

void ProjectTile::setLocation(const grim::Vector2& location) {
	Player::setLocation(location);
	(!direction) ? sprite.setPosition(location.x + 100, location.y) : sprite.setPosition(location.x - 100, location.y);
}