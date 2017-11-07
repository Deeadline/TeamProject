#include "..\Include\PercyJackson.hpp"
#include "..\Include\GameManager.hpp"
#include "..\Include\TextureManager.hpp"
PercyJackson::PercyJackson(): Player(new PercyJacksonController), isMenu(false), canMove(true), moveFlag(0) {
	setLocation(grim::Vector2(120, 800));
	background.setTexture(*(TextureManager::getTexture("tlo")));
	sprite.setTexture(*(TextureManager::getTexture("Sprite_Side")));
	sprite.setOrigin(120, 180);
}
void PercyJackson::draw() {
	if (!isMenu) {
		GameManager::instance().getWindow().draw(background);
		GameManager::instance().getWindow().draw(sprite);
	}
	else
		GameManager::instance().getWindow().draw(background);
}
void PercyJackson::setLocation(const grim::Vector2 &location) {
	Player::setLocation(location);
	sprite.setPosition(location.x, location.y);
}

void PercyJackson::setSprite(bool isLeft) {
	if (canMove) {
		if (!isLeft) {
			sprite.setScale(1, 1);
			if (moveFlag == 0) {
				sprite.setTexture(*(TextureManager::getTexture("Sprite_Side")));
			}
			else if (moveFlag == static_cast<int>(400/60.f)) {
				sprite.setTexture(*(TextureManager::getTexture("Sprite_Side1")));
			}
			else if (moveFlag == static_cast<int>(800/60.f)) {
				sprite.setTexture(*(TextureManager::getTexture("Sprite_Side2")));
			}
		}
		else {
			sprite.setScale(-1, 1);
			if (moveFlag == 0) {
				sprite.setTexture(*(TextureManager::getTexture("Sprite_Side")));
			}
			else if (moveFlag == static_cast<int>(400/60.f)) {
				sprite.setTexture(*(TextureManager::getTexture("Sprite_Side1")));
			}
			else if (moveFlag == static_cast<int>(800/60.f)) {
				sprite.setTexture(*(TextureManager::getTexture("Sprite_Side2")));
			}
		}
	}
}