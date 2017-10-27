#include "..\Include\PercyJackson.hpp"
#include "..\Include\GameManager.hpp"
#include "..\Include\TextureManager.hpp"
PercyJackson::PercyJackson(): Player(new PercyJacksonController) {
	setLocation(grim::Vector2(32, 500));
	sprite.setTexture(*(TextureManager::getTexture("Sprite_Side")));
	sprite.setOrigin(32, 91);
}
void PercyJackson::draw() {
	GameManager::instance().getWindow().draw(sprite);
}
void PercyJackson::setLocation(const grim::Vector2 &location) {
	Player::setLocation(location);
	sprite.setPosition(location.x, location.y);
}

void PercyJackson::setSprite() {
	if(moveFlag%3==1) 
		sprite.setTexture(*(TextureManager::getTexture("Sprite_Side")));
	else if (moveFlag % 3 == 2)
		sprite.setTexture(*(TextureManager::getTexture("Sprite_Side1")));
	else if (moveFlag % 3 == 0)
		sprite.setTexture(*(TextureManager::getTexture("Sprite_Side2")));
}