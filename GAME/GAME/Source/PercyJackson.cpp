#include "..\Include\PercyJackson.hpp"
#include "..\Include\GameManager.hpp"
#include "..\Include\TextureManager.hpp"
PercyJackson::PercyJackson(): Player(new PercyJacksonController), isMenu(false), canMove(true), canJump(true), moveFlag(0) {
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

void PercyJackson::setSprite(bool isLeft) {
	if (canMove) {
		(!isLeft) ? sprite.setScale(1, 1) : sprite.setScale(-1, 1);
		sprite.setTexture(*(TextureManager::getTexture("Sprite_Side"+std::to_string((int)(moveFlag / 2.5) + 1))));
		/*if (!isLeft) {
			sprite.setScale(1, 1);
			if (moveFlag == 0) {
				sprite.setTexture(*(TextureManager::getTexture("Sprite_Side1")));	//0
			}
			else if (moveFlag == static_cast<int>(100 / 40.f)) {					//2.5
				sprite.setTexture(*(TextureManager::getTexture("Sprite_Side2")));
			}
			else if (moveFlag == static_cast<int>(200 / 40.f)) {					//5
				sprite.setTexture(*(TextureManager::getTexture("Sprite_Side3")));
			}
			else if (moveFlag == static_cast<int>(300 / 40.f)) {					//7.5
				sprite.setTexture(*(TextureManager::getTexture("Sprite_Side4")));
			}
			else if (moveFlag == static_cast<int>(400 / 40.f)) {					//10
				sprite.setTexture(*(TextureManager::getTexture("Sprite_Side5")));
			}
			else if (moveFlag == static_cast<int>(500 / 40.f)) {					//12.5
				sprite.setTexture(*(TextureManager::getTexture("Sprite_Side6")));
			}
			else if (moveFlag == static_cast<int>(600 / 40.f)) {					//15
				sprite.setTexture(*(TextureManager::getTexture("Sprite_Side7")));
			}
			else if (moveFlag == static_cast<int>(700 / 40.f)) {					//17.5
				sprite.setTexture(*(TextureManager::getTexture("Sprite_Side8")));
			}
			else if (moveFlag == static_cast<int>(800 / 40.f)) {					//20
				sprite.setTexture(*(TextureManager::getTexture("Sprite_Side9")));
			}
			else if (moveFlag == static_cast<int>(900 / 40.f)) {					//22.5
				sprite.setTexture(*(TextureManager::getTexture("Sprite_Side10")));
			}
			else if (moveFlag == static_cast<int>(1000 / 40.f)) {					//25
				sprite.setTexture(*(TextureManager::getTexture("Sprite_Side11")));
			}
			else if (moveFlag == static_cast<int>(1100 / 40.f)) {					//27.5
				sprite.setTexture(*(TextureManager::getTexture("Sprite_Side12")));
			}
		}
		else {
			sprite.setScale(-1, 1);
			if (moveFlag == 0) {
				sprite.setTexture(*(TextureManager::getTexture("Sprite_Side1")));
			}
			else if (moveFlag == static_cast<int>(100 / 40.f)) {
				sprite.setTexture(*(TextureManager::getTexture("Sprite_Side2")));
			}
			else if (moveFlag == static_cast<int>(200 / 40.f)) {
				sprite.setTexture(*(TextureManager::getTexture("Sprite_Side3")));
			}
			else if (moveFlag == static_cast<int>(300 / 40.f)) {
				sprite.setTexture(*(TextureManager::getTexture("Sprite_Side4")));
			}
			else if (moveFlag == static_cast<int>(400 / 40.f)) {
				sprite.setTexture(*(TextureManager::getTexture("Sprite_Side5")));
			}
			else if (moveFlag == static_cast<int>(500 / 40.f)) {
				sprite.setTexture(*(TextureManager::getTexture("Sprite_Side6")));
			}
			else if (moveFlag == static_cast<int>(600 / 40.f)) {
				sprite.setTexture(*(TextureManager::getTexture("Sprite_Side7")));
			}
			else if (moveFlag == static_cast<int>(700 / 40.f)) {
				sprite.setTexture(*(TextureManager::getTexture("Sprite_Side8")));
			}
			else if (moveFlag == static_cast<int>(800 / 40.f)) {
				sprite.setTexture(*(TextureManager::getTexture("Sprite_Side9")));
			}
			else if (moveFlag == static_cast<int>(900 / 40.f)) {
				sprite.setTexture(*(TextureManager::getTexture("Sprite_Side10")));
			}
			else if (moveFlag == static_cast<int>(1000 / 40.f)) {
				sprite.setTexture(*(TextureManager::getTexture("Sprite_Side11")));
			}
			else if (moveFlag == static_cast<int>(1100 / 40.f)) {
				sprite.setTexture(*(TextureManager::getTexture("Sprite_Side12")));
			}
		}*/
	}
}