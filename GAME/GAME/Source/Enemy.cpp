#include "..\Include\Enemy.hpp"
#include "..\Include\GameManager.hpp"
#include "..\Include\TextureManager.hpp"
#include "../Include/EnemyController.hpp"

Enemy::Enemy() : Player(new EnemyController), cycle(0), canMove(true) {
	Enemy::setLocation(grim::Vector2(3000, 800));
	if (GameManager::instance().getLevelName() == "Introduce") {
		sprite.setTexture(*(TextureManager::getTexture("Sprite_Side1")));
		sprite.setScale(-1, 1);
	}
	else if (GameManager::instance().getLevelName() == "Medusa") {
		sprite.setTexture(*(TextureManager::getTexture("RockyA")));
		sprite.setScale(1, 1);
	}
	sprite.setOrigin(120, 180);
}
void Enemy::draw() {
	if (!GameManager::instance().getPlayer()->getIsMenu()) {
		GameManager::instance().getWindow().draw(sprite);
	}

}
void Enemy::setLocation(const grim::Vector2 &location) {
	Player::setLocation(location);
	sprite.setPosition(location.x, location.y);
	healttText.setPosition(location.x, location.y - 100);
}
void Enemy::setSprite(const int dir) {
	(dir == 1) ? direction = false : direction = true;
	if (canMove) {
		if (GameManager::instance().getLevelName() == "Introduce") {
			sprite.setTexture(*(TextureManager::getTexture("Sprite_Side" + std::to_string(static_cast<int>(moveFlag / 2.5) + 1))));
			sprite.setScale(static_cast<float>(dir), 1);
		}
		else {
			sprite.setTexture(*(TextureManager::getTexture("RockyA")));
			sprite.setScale(static_cast<float>(dir) * (-1), 1);
		}
		
	}
}
