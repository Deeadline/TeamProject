#include "../Include/Enemy.hpp"
#include "../Include/GameManager.hpp"
#include "../Include/TextureManager.hpp"
#include "../Include/EnemyController.hpp"

Enemy::Enemy(const int type) : Player(new EnemyController), moveFlag(0), cycle(0), attackCycle(0), movable(true),
                               direction(false),
                               shoot(true) {
	switch (type) {
	case 1:
		enemyType = TypeEnemy::tutorial;
		sprite.setTexture(*TextureManager::getTexture("Thalia_BowWalking1"));
		sprite.setScale(-1, 1);
		sprite.setOrigin(120, 180);
		Enemy::setDamage(1);
		Enemy::setHealth(20);
		break;
	case 2:
		enemyType = TypeEnemy::rocky;
		sprite.setTexture(*TextureManager::getTexture("Rocky_Walking1"));
		sprite.setScale(1, 1);
		sprite.setOrigin(130, 190);
		Enemy::setDamage(1);
		Enemy::setHealth(20);
		break;
//	case 3:
//		enemyType = TypeEnemy::medusa;
//		sprite.setTexture(*TextureManager::getTexture("Thalia_Walking1"));
//		sprite.setScale(-1, 1);
//		sprite.setOrigin(120, 180);
//		Enemy::setDamage(1);
//		Enemy::setHealth(20);
//		break;
	}
}

void Enemy::draw() {
	if (!GameManager::instance().getPlayer()->isMenu() && !GameManager::instance().getPlayer()->isLoading()) {
		GameManager::instance().getWindow().draw(sprite);
	}

}
void Enemy::setLocation(const grim::Vector2 &location) {
	Player::setLocation(location);
	sprite.setPosition(location.x, location.y);
	healttText.setPosition(location.x, location.y - 100);
}

void Enemy::setDamage(const int damage) {
	Player::setDamage(damage);
}

void Enemy::setHealth(const int healthPoint) {
	Player::setHealth(healthPoint);
}


void Enemy::setSprite(const int dir) {
	dir == 1 ? direction = false : direction = true;
		if (enemyType == tutorial) {
			sprite.setTexture(*TextureManager::getTexture("Thalia_BowWalking" + std::to_string(static_cast<int>(moveFlag / 2.5) + 1)));
			sprite.setScale(static_cast<float>(dir), 1);
		}
		else if(enemyType == rocky) {
			if(!shoot) {
				if(attackCycle > 0 && attackCycle < 3)
					sprite.setTexture(*TextureManager::getTexture("Rocky_Attack1"), true);
				else if (attackCycle > 3 && attackCycle < 6)
					sprite.setTexture(*TextureManager::getTexture("Rocky_Attack2"), true);
				else if (attackCycle > 6 && attackCycle < 9)
					sprite.setTexture(*TextureManager::getTexture("Rocky_Attack3"), true);
				else if (attackCycle > 9 && attackCycle < 12)
					sprite.setTexture(*TextureManager::getTexture("Rocky_Attack4"), true);
				else if (attackCycle > 12 && attackCycle < 15)
					sprite.setTexture(*TextureManager::getTexture("Rocky_Attack5"), true);
				else if(attackCycle > 15 && attackCycle < 18)
					sprite.setTexture(*TextureManager::getTexture("Rocky_Attack6"), true);
				else if(attackCycle > 18) {
					sprite.setTexture(*TextureManager::getTexture("Rocky_Walking1"));
				}
				sprite.setScale(static_cast<float>(dir) * -1, 1);
			}
			else {
				sprite.setTexture(*TextureManager::getTexture("Rocky_Walking" + std::to_string(static_cast<int>(moveFlag / 2.5) + 1)));
				sprite.setScale(static_cast<float>(dir) * -1, 1);
			}
		}
}
