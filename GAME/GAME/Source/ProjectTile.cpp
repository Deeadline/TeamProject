#pragma once
#include "../Include/ProjectTile.hpp"
#include "../Include/ProjectTileController.hpp"
#include "../Include/GameManager.hpp"
#include "../Include/TextureManager.hpp"
ProjectTile::ProjectTile(const bool direction, const int type , const grim::Vector2 &location) : Player(new ProjectTileController),
direction(direction), hit(false) {
	switch(type) {
	case 1:
		tile = TileType::arrow;
		ProjectTile::setLocation(location);
		ProjectTile::setDamage(5);
		sprite.setTexture(*TextureManager::getTexture("Arrow"));
		break;
	case 2:
		tile = TileType::rock;
		ProjectTile::setLocation(location);
		ProjectTile::setDamage(1);
		sprite.setTexture(*TextureManager::getTexture("RockThrowing"));
		break;
	}
}

void ProjectTile::setDamage(const int damage) {
	Player::setDamage(damage);
}


void ProjectTile::draw() {
	!direction ? sprite.setScale(1, 1) : sprite.setScale(-1, 1);
	GameManager::instance().getWindow().draw(sprite);
}

void ProjectTile::setLocation(const grim::Vector2& location) {
	Player::setLocation(location);
	if (!direction) {
		if(tile == 1) {
			sprite.setPosition(location.x + 70, location.y - 110);
		}
		else {
			sprite.setPosition(location.x + 50, location.y + 50);
		}
	}
	else {
		if (tile == 1) {
			sprite.setPosition(location.x - 70, location.y - 110);
		}
		else {
			sprite.setPosition(location.x - 50, location.y + 50);
		}
	}
}