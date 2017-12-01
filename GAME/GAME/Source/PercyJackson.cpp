#include "..\Include\PercyJackson.hpp"
#include "..\Include\GameManager.hpp"
#include "..\Include\TextureManager.hpp"

PercyJackson::PercyJackson(): Player(new PercyJacksonController), moveFlag(0), canJump(true), isMenu(false), canMove(true) {
	setLocation(grim::Vector2(95, 800));
	setViewLocation(grim::Vector2(420,540));
	background.setTexture(*(TextureManager::getTexture("tlo")));
	sprite.setTexture(*(TextureManager::getTexture("Sprite_Side1")));
	sprite.setOrigin(95, 180);
}
void PercyJackson::draw() {
	if (!isMenu) {
		GameManager::instance().getWindow().draw(background);
		GameManager::instance().getWindow().draw(sprite);
	}
	else {
		GameManager::instance().getWindow().draw(background);
	}
}
void PercyJackson::setLocation(const grim::Vector2 &location) {
	Player::setLocation(location);
	sprite.setPosition(location.x, location.y);
}

void PercyJackson::setViewLocation(const grim::Vector2 & viewLocation)
{
	Player::setViewLocation(viewLocation);
	GameManager::instance().getViewGame().setCenter(viewLocation.x, viewLocation.y);
	GameManager::instance().getWindow().setView(GameManager::instance().getViewGame());
}


void PercyJackson::setSprite(const bool isLeft) {
	this->isLeft = isLeft;
	if (canMove) {
		(!isLeft) ? sprite.setScale(1, 1) : sprite.setScale(-1, 1);
		if (!canJump) {
			sprite.setTexture(*(TextureManager::getTexture("Sprite_Jump" + std::to_string(static_cast<int>(moveFlag / 2.5) + 1))));
		else {
		sprite.setTexture(*(TextureManager::getTexture("Sprite_Side" + std::to_string(static_cast<int>(moveFlag / 2.5) + 1))));
		}
	}
}