#include "../Include/Thalia.hpp"
#include "../Include/GameManager.hpp"
#include "../Include/TextureManager.hpp"
#include "../Include/ThaliaController.hpp"

Thalia::Thalia() : Player(new ThaliaController),
moveFlag(0), checkpoint(0),
isArrow(false), loading(false),
attack(true), menu(false),
movable(true), jump(true), shoot(true) {
	Thalia::setLocation(grim::Vector2(95, 800));
	Thalia::setViewLocation(grim::Vector2(420, 540));
	loadingScreen.setTexture(*TextureManager::getTexture("loading"));
	if (GameManager::instance().getLevelName() != "Medusa") {
		sprite.setTexture(*TextureManager::getTexture("Thalia_Walking1"), true);
		background.setTexture(*TextureManager::getTexture("gamebg1"));
		width = 3505;
	}
	else {
		sprite.setTexture(*TextureManager::getTexture("Thalia_BowWalking1"), true);
		background.setTexture(*TextureManager::getTexture("gamebg4"));
		width = 7505;
	}
	sprite.setOrigin(95, 180);
}
void Thalia::draw() {
	if (!loading && !menu) {
		if (getLocation().x > 300 && checkpoint == 0 && GameManager::instance().getLevelName() != "Medusa") {
			checkpoint = 1;
			background.setTexture(*TextureManager::getTexture("gamebg2"));
		}
		if (getLocation().x >1400 && checkpoint == 1 && GameManager::instance().getLevelName() != "Medusa") {
			checkpoint = 2;
			background.setTexture(*TextureManager::getTexture("gamebg3"));
		}
		if (getLocation().x> 2500 && checkpoint == 2 && GameManager::instance().getLevelName() != "Medusa") {
			checkpoint = 3;
			background.setTexture(*TextureManager::getTexture("gamebg1"));
		}
		GameManager::instance().getWindow().draw(background);
		GameManager::instance().getWindow().draw(sprite);
	}
	else if (!menu) {
		setLocation(grim::Vector2(20000, 800));
		setViewLocation(grim::Vector2(720, 540));
		GameManager::instance().getWindow().draw(loadingScreen);
	}
	else {
		GameManager::instance().getWindow().draw(background);
	}
}
void Thalia::setLocation(const grim::Vector2 &location) {
	Player::setLocation(location);
	sprite.setPosition(location.x, location.y);
}

void Thalia::setViewLocation(const grim::Vector2 & viewLocation)
{
	Player::setViewLocation(viewLocation);
	GameManager::instance().getViewGame().setCenter(viewLocation.x, viewLocation.y);
	GameManager::instance().getWindow().setView(GameManager::instance().getViewGame());
}


void Thalia::setSprite(const bool direct) {
	this->direct = direct;
	if (movable) {
		!this->direct ? sprite.setScale(1, 1) : sprite.setScale(-1, 1);
		if (!jump) {
			if (GameManager::instance().getLevelName() != "Medusa") {
				if (jumpCycle > 0 && jumpCycle < 8)
					sprite.setTexture(*TextureManager::getTexture("Thalia_Jump2"), true);
				else if (jumpCycle > 8 && jumpCycle < 23)
					sprite.setTexture(*TextureManager::getTexture("Thalia_Jump3"), true);
				else if (jumpCycle > 23 && jumpCycle < 33)
					sprite.setTexture(*TextureManager::getTexture("Thalia_Jump4"), true);
				else if (jumpCycle > 33 && jumpCycle < 48)
					sprite.setTexture(*TextureManager::getTexture("Thalia_Jump5"), true);
				else
					sprite.setTexture(*TextureManager::getTexture("Thalia_Jump6"), true);
			}
			else {
				if (jumpCycle > 0 && jumpCycle < 8)
					sprite.setTexture(*TextureManager::getTexture("Thalia_BowJump2"), true);
				else if (jumpCycle > 8 && jumpCycle < 23)
					sprite.setTexture(*TextureManager::getTexture("Thalia_BowJump3"), true);
				else if (jumpCycle > 23 && jumpCycle < 33)
					sprite.setTexture(*TextureManager::getTexture("Thalia_BowJump4"), true);
				else if (jumpCycle > 33 && jumpCycle < 48)
					sprite.setTexture(*TextureManager::getTexture("Thalia_BowJump5"), true);
				else
					sprite.setTexture(*TextureManager::getTexture("Thalia_BowJump6"), true);
			}
		}
		else if (!attack) {
			if (GameManager::instance().getLevelName() != "Medusa") {
				if (attackCycle > 0 && attackCycle < 8)
					sprite.setTexture(*TextureManager::getTexture("Thalia_AttackKnifeNoBow1"), true);
				else if (attackCycle > 8 && attackCycle < 23) {
					sprite.setTexture(*TextureManager::getTexture("Thalia_AttackKnifeNoBow2"), true);
				}
			}
			else {
				if (attackCycle > 0 && attackCycle < 8)
					sprite.setTexture(*TextureManager::getTexture("Thalia_AttackKnifeBow1"), true);
				else if (attackCycle > 8 && attackCycle < 23)
					sprite.setTexture(*TextureManager::getTexture("Thalia_AttackKnifeBow2"), true);
			}
		}
		else {
			if (GameManager::instance().getLevelName() == "Medusa" || GameManager::instance().getEnemy()->isDestroyed())
				sprite.setTexture(*TextureManager::getTexture("Thalia_BowWalking" + std::to_string(static_cast<int>(moveFlag / 2.5) + 1)), true);
			else
				sprite.setTexture(*TextureManager::getTexture("Thalia_Walking" + std::to_string(static_cast<int>(moveFlag / 2.5) + 1)), true);
		}
	}
}

bool Thalia::isCollidingWithAnything() {
	const sf::FloatRect collider(sf::Vector2f(location.x - 95, location.y - 180), sf::Vector2f(190, 360));
	auto colliders = GameManager::instance().getLevel()->getAllColliders();
	for (auto* icollider : colliders) {
		const auto colliderLoc = icollider->getLocation();
		sf::FloatRect eIcolliders(sf::Vector2f(colliderLoc.x, colliderLoc.y), sf::Vector2f(64, 64));
		if (eIcolliders.intersects(collider))
			return true;
	}
	return false;

}