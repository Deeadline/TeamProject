#include "..\Include\Enemy.hpp"
#include "..\Include\GameManager.hpp"
#include "..\Include\TextureManager.hpp"
#include "../Include/EnemyController.hpp"

Enemy::Enemy() : Player(new EnemyController), cycle(0), canMove(true) {
	Enemy::setLocation(grim::Vector2(3000, 800));
	sprite.setTexture(*(TextureManager::getTexture("Sprite_Side1")));
	sprite.setOrigin(120, 180);
	sprite.setScale(-1, 1);
//	Enemy::setString();
}
void Enemy::draw() {
	if (!GameManager::instance().getPlayer()->getIsMenu()) {
		GameManager::instance().getWindow().draw(sprite);
		//GameManager::instance().getWindow().draw(healttText);
	}

}
void Enemy::setLocation(const grim::Vector2 &location) {
	Player::setLocation(location);
	sprite.setPosition(location.x, location.y);
	healttText.setPosition(location.x, location.y - 100);
}
void Enemy::setSprite(const int dir) {
	if (canMove) {
		sprite.setTexture(*(TextureManager::getTexture("Sprite_Side" + std::to_string(static_cast<int>(moveFlag / 2.5) + 1))));
		sprite.setScale(static_cast<float>(dir), 1);
	}
}

void Enemy::setString() {
	const sf::String text = std::to_string(Enemy::getHealthPoint());
	healttText.setFont(GameManager::instance().getFont());
	healttText.setCharacterSize(25);
	healttText.setString(text);
}
