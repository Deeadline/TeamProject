#include "..\Include\PercyJackson.hpp"
#include "..\Include\GameManager.hpp"
#include "..\Include\TextureManager.hpp"
PercyJackson::PercyJackson(): Player(new PercyJacksonController), isMenu(false), canMove(true) {
	setLocation(grim::Vector2(120, 800));
	background.setTexture(*(TextureManager::getTexture("background")));
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
			if (moveFlag % 3 == 1) {
				sprite.setScale(1, 1);
				sprite.setTexture(*(TextureManager::getTexture("Sprite_Side")));
			}
			else if (moveFlag % 3 == 2) {
				sprite.setScale(1, 1);
				sprite.setTexture(*(TextureManager::getTexture("Sprite_Side1")));
			}
			else if (moveFlag % 3 == 0) {
				sprite.setScale(1, 1);
				sprite.setTexture(*(TextureManager::getTexture("Sprite_Side2")));
			}
		}
		else {
			if (moveFlag % 3 == 1) {
				sprite.setScale(-1, 1);
				sprite.setTexture(*(TextureManager::getTexture("Sprite_Side")));
			}
			else if (moveFlag % 3 == 2) {
				sprite.setScale(-1, 1);
				sprite.setTexture(*(TextureManager::getTexture("Sprite_Side1")));
			}
			else if (moveFlag % 3 == 0) {
				sprite.setScale(-1, 1);
				sprite.setTexture(*(TextureManager::getTexture("Sprite_Side2")));
			}
		}
	}
}