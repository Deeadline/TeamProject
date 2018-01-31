#pragma once
#include "Includers.hpp"
#include "Math/Vector2.hpp"
class CharacterMechanics { // klasa abstrakcyjna do wyœwietlenia gracza
public:
	CharacterMechanics() : healthPoint(0), damage(0), rotation(0), destroyed(false) {
	}

	virtual ~CharacterMechanics() {  }
	virtual void update(const float &deltaTime) {}
	virtual void draw() = 0;
	virtual void setLocation(const grim::Vector2 &location) { this->location = location; }
	virtual void setViewLocation(const grim::Vector2 &viewLocation) { this->viewLocation = viewLocation; }
	virtual grim::Vector2 getViewLocation() { return this->viewLocation; }
	virtual void setRotation(const float &rotation) { this->rotation = rotation; }
	virtual void setDamage(const int damage) { this->damage = damage; }
	virtual void setHealth(const int healthPoint) { this->healthPoint = healthPoint; }

	void move(const grim::Vector2 &delta) { this->setLocation(location + delta); }
	void moveView(const grim::Vector2 &delta) { this->setViewLocation(viewLocation + delta); }
	void rotate(const float &delta) { this->setRotation(rotation + delta); }
	void setDestroyed(const bool destroyed) { this->destroyed = destroyed; }

	sf::Sprite getSprite() const { return this->sprite; }
	grim::Vector2 getLocation() const { return location; }
	float getRotation() const { return rotation; }
	bool isDestroyed() const { return destroyed; }
	int getHealthPoint() const { return healthPoint; }
	int getDamage() const { return damage; }
protected:
	sf::Sprite sprite;
	grim::Vector2 location;
	grim::Vector2 viewLocation;
	int healthPoint;
	int damage;
	float rotation;
	bool destroyed;
};