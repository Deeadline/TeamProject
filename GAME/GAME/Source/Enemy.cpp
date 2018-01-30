#include "../Include/Enemy.hpp"
#include "../Include/GameManager.hpp"
#include "../Include/TextureManager.hpp"
#include "../Include/EnemyController.hpp"

Enemy::Enemy() : Player(new EnemyController), cycle(0), movable(true) {
	Enemy::setLocation(grim::Vector2(3000, 800));
	if (GameManager::instance().getLevelName() == "Introduce") {
		sprite.setTexture(*TextureManager::getTexture("Thalia_Walking1"));
		sprite.setScale(-1, 1);
		sprite.setOrigin(120, 180);
	}
	else if (GameManager::instance().getLevelName() == "Medusa") {
		sprite.setTexture(*TextureManager::getTexture("Rocky_Walking1"));
		sprite.setScale(1, 1);
		sprite.setOrigin(130, 190);
	}
}
void Enemy::draw() {
	if (!GameManager::instance().getPlayer()->isMenu()) {
		GameManager::instance().getWindow().draw(sprite);
	}

}
void Enemy::setLocation(const grim::Vector2 &location) {
	Player::setLocation(location);
	sprite.setPosition(location.x, location.y);
	healttText.setPosition(location.x, location.y - 100);
}
void Enemy::setSprite(const int dir) {
	dir == 1 ? direction = false : direction = true;
	if (movable) {
		if (GameManager::instance().getLevelName() == "Introduce") {
			sprite.setTexture(*TextureManager::getTexture("Thalia_Walking" + std::to_string(static_cast<int>(moveFlag / 2.5) + 1)));
			sprite.setScale(static_cast<float>(dir), 1);
		}
		else {
			sprite.setTexture(*TextureManager::getTexture("Rocky_Walking" + std::to_string(static_cast<int>(moveFlag / 2.5) + 1)));
			sprite.setScale(static_cast<float>(dir) * -1, 1);
		}

	}
}