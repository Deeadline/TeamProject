#include "..\Include\PercyJackson.hpp"
#include "..\Include\GameManager.hpp"
#include "..\Include\TextureManager.hpp"

PercyJackson::PercyJackson(): Player(new PercyJacksonController), moveFlag(0), canJump(true), canShoot(true), isMenu(false), canMove(true), isArrow(false) {
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
			if (jumpCycle > 0 && jumpCycle < 8)
				sprite.setTexture(*TextureManager::getTexture("Sprite_Jump2"));
			else if (jumpCycle > 8 && jumpCycle < 23)
				sprite.setTexture(*TextureManager::getTexture("Sprite_Jump3"));
			else if (jumpCycle > 23 && jumpCycle < 33)
				sprite.setTexture(*TextureManager::getTexture("Sprite_Jump4"));
			else if (jumpCycle > 33 && jumpCycle < 48)
				sprite.setTexture(*TextureManager::getTexture("Sprite_Jump5"));
			else
				sprite.setTexture(*TextureManager::getTexture("Sprite_Jump6"));
		}
		else {
			sprite.setTexture(*TextureManager::getTexture("Sprite_Side" + std::to_string(static_cast<int>(moveFlag / 2.5) + 1)));
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
