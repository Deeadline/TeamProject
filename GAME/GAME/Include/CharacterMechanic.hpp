#pragma once
#include "Includers.hpp"
#include "Math/Vector2.hpp"
class CharacterMechanics { // klasa abstrakcyjna do wyœwietlenia gracza
public:
	CharacterMechanics() : rotation(0), destroyed(false) {
	}

	virtual ~CharacterMechanics() {  }
	virtual void update(const float &deltaTime) {}
	virtual void draw() = 0;
	virtual void setLocation(const grim::Vector2 &location) { this->location = location; }
	virtual void setViewLocation(const grim::Vector2 &viewLocation) { this->viewLocation = viewLocation; }
	virtual grim::Vector2 getViewLocation() { return this->viewLocation; }
	virtual void setRotation(const float &rotation) { this->rotation = rotation; }

	void move(const grim::Vector2 &delta) { this->setLocation(location + delta); }
	void moveView(const grim::Vector2 &delta) { this->setViewLocation(viewLocation + delta); }
	void rotate(const float &delta) { this->setRotation(rotation + delta); }
	void setDestroyed(const bool destroyed) { this->destroyed = destroyed; }

	grim::Vector2 getLocation() const { return location; }
	float getRotation() const { return rotation; }
	bool isDestroyed() const { return destroyed; }
protected:
	grim::Vector2 location;
	grim::Vector2 viewLocation;
	float rotation;
	bool destroyed;
};