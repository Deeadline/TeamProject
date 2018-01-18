#include "..\Include\PercyJackson.hpp"
#include "..\Include\GameManager.hpp"
#include "..\Include\TextureManager.hpp"

PercyJackson::PercyJackson(): Player(new PercyJacksonController),loading(false), moveFlag(0),canAttack(true), canJump(true), canShoot(true), isMenu(false), canMove(true), isArrow(false) {
	setLocation(grim::Vector2(95, 800));
	setViewLocation(grim::Vector2(420,540));
	background.setTexture(*TextureManager::getTexture("tlo"));
	loadingScreen.setTexture(*TextureManager::getTexture("loading"));
	if (GameManager::instance().getLevelName() != "Medusa") {
		sprite.setTexture(*TextureManager::getTexture("Sprite_Side1"), true);
	}
	else {
		sprite.setTexture(*TextureManager::getTexture("Sprite_Side01"), true);
	}
	sprite.setOrigin(95, 180);
}
void PercyJackson::draw() {
	if (!loading) {
		GameManager::instance().getWindow().draw(background);
		GameManager::instance().getWindow().draw(sprite);
	}
	else {
		setLocation(grim::Vector2(20000, 800));
		setViewLocation(grim::Vector2(720, 540));
		GameManager::instance().getWindow().draw(loadingScreen);
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
			if (GameManager::instance().getLevelName() != "Medusa") {
				if (jumpCycle > 0 && jumpCycle < 8)
					sprite.setTexture(*TextureManager::getTexture("Sprite_Jump2"), true);
				else if (jumpCycle > 8 && jumpCycle < 23)
					sprite.setTexture(*TextureManager::getTexture("Sprite_Jump3"), true);
				else if (jumpCycle > 23 && jumpCycle < 33)
					sprite.setTexture(*TextureManager::getTexture("Sprite_Jump4"), true);
				else if (jumpCycle > 33 && jumpCycle < 48)
					sprite.setTexture(*TextureManager::getTexture("Sprite_Jump5"), true);
				else
					sprite.setTexture(*TextureManager::getTexture("Sprite_Jump6"), true);
			}
			else {
				if (jumpCycle > 0 && jumpCycle < 8)
					sprite.setTexture(*TextureManager::getTexture("Sprite_Jump02"), true);
				else if (jumpCycle > 8 && jumpCycle < 23)
					sprite.setTexture(*TextureManager::getTexture("Sprite_Jump03"), true);
				else if (jumpCycle > 23 && jumpCycle < 33)
					sprite.setTexture(*TextureManager::getTexture("Sprite_Jump04"), true);
				else if (jumpCycle > 33 && jumpCycle < 48)
					sprite.setTexture(*TextureManager::getTexture("Sprite_Jump05"),true);
				else
					sprite.setTexture(*TextureManager::getTexture("Sprite_Jump06"),true);
			}
		}
		else if (!canAttack) {
			if (GameManager::instance().getLevelName() != "Medusa") {
				if (attackCycle > 0 && attackCycle < 8)
					sprite.setTexture(*TextureManager::getTexture("Sprite_Attack1"), true);
				else if (attackCycle > 8 && attackCycle < 23) {
					sprite.setTexture(*TextureManager::getTexture("Sprite_Attack2"),true);
				}
			}
			else {
				if (attackCycle > 0 && attackCycle < 8)
					sprite.setTexture(*TextureManager::getTexture("Sprite_Attack01"), true);
				else if (attackCycle > 8 && attackCycle < 23)
					sprite.setTexture(*TextureManager::getTexture("Sprite_Attack02"),true);
			}
		}
		else {
			if(GameManager::instance().getLevelName() == "Medusa")
				sprite.setTexture(*TextureManager::getTexture("Sprite_Side0" + std::to_string(static_cast<int>(moveFlag / 2.5) + 1)),true);
			else
				sprite.setTexture(*TextureManager::getTexture("Sprite_Side" + std::to_string(static_cast<int>(moveFlag / 2.5) + 1)),true);
		}
	}
}

bool PercyJackson::isCollidingWithAnything() {
	sf::FloatRect collider(sf::Vector2f(location.x - 95, location.y - 180), sf::Vector2f(190, 360));
	auto colliders = GameManager::instance().getLevel()->getAllColliders();
	for(auto* Icollider: colliders) {
		grim::Vector2 colliderLoc = Icollider->getLocation();
		sf::FloatRect EIcolliders(sf::Vector2f(colliderLoc.x, colliderLoc.y), sf::Vector2f(64, 64));
		if (EIcolliders.intersects(collider))
			return true;
	}
	return false;

}
