#pragma once
#include "../Include/Tile.hpp"
#include "../Include/GameManager.hpp"
#include "../Include/TextureManager.hpp"
#include "../Include/TileController.hpp"

Tile::Tile() : Player(new TileController) {
	sprite.setTexture(*TextureManager::getTexture("Klocek"));
	//sprite.setOrigin(32, 32);
}

void Tile::draw() {
	GameManager::instance().getWindow().draw(sprite);
}

void Tile::setLocation(const grim::Vector2& location) {
	Player::setLocation(location);
	sprite.setPosition(location.x, location.y);
}
