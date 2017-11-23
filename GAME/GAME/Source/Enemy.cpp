#include "..\Include\Enemy.hpp"
#include "..\Include\GameManager.hpp"
#include "..\Include\TextureManager.hpp"

Enemy::Enemy() : Player(new EnemyController), canMove(true) {
	setLocation(grim::Vector2(1000, 800));
	sprite.setTexture(*(TextureManager::getTexture("Sprite_Side")));
	sprite.setOrigin(120, 180);
	sprite.setScale(-1, 1);
}
void Enemy::draw() {
	if(!GameManager::instance().getPlayer()->getIsMenu())
		GameManager::instance().getWindow().draw(sprite);

}
void Enemy::setLocation(const grim::Vector2 &location) {
	Player::setLocation(location);
	sprite.setPosition(location.x, location.y);
}
void Enemy::setSprite() {
	if (canMove) {
		if (moveFlag == 0) {
			sprite.setTexture(*(TextureManager::getTexture("Sprite_Side")));
		}
		else if (moveFlag == static_cast<int>(400 / 60.f)) {
			sprite.setTexture(*(TextureManager::getTexture("Sprite_Side1")));
		}
		else if (moveFlag == static_cast<int>(800 / 60.f)) {
			sprite.setTexture(*(TextureManager::getTexture("Sprite_Side2")));
		}
	}
}