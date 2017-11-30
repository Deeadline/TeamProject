#pragma once
#include "Includers.hpp"
#include "Math\Vector2.hpp"
class CharacterMechanics { // klasa abstrakcyjna do wyœwietlenia gracza
public:
	inline CharacterMechanics() :rotation(0) {  }
	inline virtual ~CharacterMechanics() {  }
	inline virtual void setLocation(const grim::Vector2 &location) { this->location = location; }
	inline virtual void setViewLocation(const grim::Vector2 &viewLocation) { this->viewLocation = viewLocation; }
	inline virtual void setRotation(const float &rotation) { this->rotation = rotation; }
	inline void move(const grim::Vector2 &delta) { this->setLocation(location + delta); }
	inline void moveView(const grim::Vector2 &delta) { this->setViewLocation(viewLocation + delta); }
	inline void rotate(const float &delta) { this->setRotation(rotation + delta); }
	inline virtual void update(const float &deltaTime, sf::Event &event){}
	virtual void draw() = 0;
	inline grim::Vector2 getLocation() const { return location; }
	inline float getRotation() const { return rotation; }
private:
	grim::Vector2 location;
	grim::Vector2 viewLocation;
	float rotation;
};