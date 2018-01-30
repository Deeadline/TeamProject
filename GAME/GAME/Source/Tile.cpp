#pragma once
#include "../Include/Tile.hpp"
#include "../Include/GameManager.hpp"
#include "../Include/TextureManager.hpp"
#include "../Include/TileController.hpp"
#include <functional>

Tile::Tile(const int x) : Player(new TileController) {
	sprite.setTexture(*TextureManager::getTexture("Rock" + std::to_string(x)));
}

void Tile::draw() {
	if (!GameManager::instance().getPlayer()->isLoading() && !GameManager::instance().getPlayer()->isMenu())
		GameManager::instance().getWindow().draw(sprite);
}

void Tile::setLocation(const grim::Vector2& location) {
	Player::setLocation(location);
	sprite.setPosition(location.x, location.y);
}
