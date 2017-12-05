#include "..\Include\Enemy.hpp"
#include "..\Include\GameManager.hpp"
#include "..\Include\TextureManager.hpp"
#include "../Include/EnemyController.hpp"

Enemy::Enemy() : Player(new EnemyController), canMove(true) {
	//setLocation(grim::Vector2(1000, 800));
	/*sprite.setTexture(*(TextureManager::getTexture("Sprite_Side1")));
	sprite.setOrigin(120, 180);
	sprite.setScale(-1, 1);*/
	rectangleShape.setSize(sf::Vector2f(200.f, 200.f));
	rectangleShape.setFillColor(sf::Color::Green);
}
void Enemy::draw() {
	if(!GameManager::instance().getPlayer()->getIsMenu())
		//GameManager::instance().getWindow().draw(sprite);
		GameManager::instance().getWindow().draw(rectangleShape);

}
void Enemy::setLocation(const grim::Vector2 &location) {
	Player::setLocation(location);
	//sprite.setPosition(location.x, location.y);
	rectangleShape.setPosition(location.x, location.y);
}
void Enemy::setSprite() {
	if (canMove) {
		sprite.setTexture(*(TextureManager::getTexture("Sprite_Side" + std::to_string(static_cast<int>(moveFlag / 2.5) + 1))));
	}
}