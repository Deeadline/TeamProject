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
	Thalia::setHealth(1000);
	Thalia::setDamage(5);
	loadingScreen.setTexture(*TextureManager::getTexture("loading"));
	if (GameManager::instance().getLevelName() != "Medusa") {
		sprite.setTexture(*TextureManager::getTexture("Thalia_Walking1"), true);
		background.setTexture(*TextureManager::getTexture("gamebg1"));
		width = 3505;
	}
	else {
		sprite.setTexture(*TextureManager::getTexture("Thalia_BowWalking1"), true);
		background.setTexture(*TextureManager::getTexture("gamebg6"));
		width = 7505;
	}
	font = GameManager::instance().getFont();
	setTexts();
	sprite.setOrigin(95, 180);
}

void Thalia::draw() {
	if (!loading && !menu) {
		if (getLocation().x > 200 && checkpoint == 0 && GameManager::instance().getLevelName() != "Medusa") {
			background.setTexture(*TextureManager::getTexture("gamebg2"));
			checkpoint = 1;
		}
		if (getLocation().x > 1400 && checkpoint == 1 && GameManager::instance().getLevelName() != "Medusa") {
			background.setTexture(*TextureManager::getTexture("gamebg3"));
			checkpoint = 2;
		}
		if (GameManager::instance().getEnemy(0)->isDestroyed() && checkpoint == 2 && GameManager::instance().getLevelName() != "Medusa") {
			GameManager::instance().getEnemy(1)->setLocation(grim::Vector2(3000, 800));
			GameManager::instance().getLevel()->addCharacter(GameManager::instance().getEnemy(1));
			background.setTexture(*TextureManager::getTexture("gamebg4"));
			std::cout << GameManager::instance().getEnemy(1)->isDestroyed() << std::endl;
			checkpoint = 3;
		}
		if (GameManager::instance().getEnemy(1)->isDestroyed() && checkpoint == 3 && GameManager::instance().getLevelName() != "Medusa") {
			background.setTexture(*TextureManager::getTexture("gamebg5"));
		}
		GameManager::instance().getWindow().draw(background);
		GameManager::instance().getWindow().draw(sprite);
		if (checkpoint != 0)
			GameManager::instance().getWindow().draw(texts[checkpoint - 1]);
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

void Thalia::setDamage(const int damage) {
	Player::setDamage(damage);
}

void Thalia::setHealth(const int healthPoint) {
	Player::setHealth(healthPoint);
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

void Thalia::setTexts() {
	sf::String textsCheckpoint[] = { "BLABLABLA","BLABLABLA","BLABLABLA","BLABLABLA" };
	for (auto i = 0; i < 4; i++) {
		texts[i].setFont(font);
		texts[i].setCharacterSize(30);
		texts[i].setString(textsCheckpoint[i]);
		texts[i].setFillColor(sf::Color::Black);
	}
	texts[0].setPosition(585, 650);
	texts[1].setPosition(1875, 650);
	texts[2].setPosition(2550, 650);
	texts[3].setPosition(3435, 650);
}


void Thalia::setSprite(const bool direct) {
	this->direct = direct;
	if (movable) {
		!this->direct ? sprite.setScale(1, 1) : sprite.setScale(-1, 1);
		sprite.setOrigin(190 / 2.f, 360 / 2.f);
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
		else if(!shoot) {
			sprite.setOrigin(110,253);
				if (attackCycle > 0 && attackCycle < 3)
					sprite.setTexture(*TextureManager::getTexture("Thalia_AttackBow1"), true);
				else if (attackCycle > 3 && attackCycle < 6)
					sprite.setTexture(*TextureManager::getTexture("Thalia_AttackBow2"), true);
				else if (attackCycle > 6 && attackCycle < 9)
					sprite.setTexture(*TextureManager::getTexture("Thalia_AttackBow3"), true);
				else if (attackCycle > 9 && attackCycle < 12)
					sprite.setTexture(*TextureManager::getTexture("Thalia_AttackBow4"), true);
				else if (attackCycle > 12 && attackCycle < 15)
					sprite.setTexture(*TextureManager::getTexture("Thalia_AttackBow5"), true);
				else if (attackCycle > 15 && attackCycle < 18)
					sprite.setTexture(*TextureManager::getTexture("Thalia_AttackBow6"), true);
				else if (attackCycle > 18 && attackCycle < 21)
					sprite.setTexture(*TextureManager::getTexture("Thalia_AttackBow7"), true);
				else if (attackCycle > 21 && attackCycle < 24)
					sprite.setTexture(*TextureManager::getTexture("Thalia_AttackBow8"), true);
				else if (attackCycle > 24) {
					sprite.setTexture(*TextureManager::getTexture("Thalia_AttackBow9"), true);
				}
		}
		else {
			if (GameManager::instance().getLevelName() == "Medusa" ||  checkpoint > 2)
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