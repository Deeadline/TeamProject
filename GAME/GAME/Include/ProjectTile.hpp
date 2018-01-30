#pragma once
#include "Includers.hpp"
#include "Player.hpp"
class ProjectTile : public Player {
public:
	ProjectTile(const bool direction, const bool tOwner);
	virtual void draw() override;
	virtual void setLocation(const grim::Vector2 &location) override;

	bool isHit() const { return hit; }
	bool getDirection() { return direction; }
	bool getOwner() const { return tOwner; }
	sf::Sprite getSprite() const { return sprite; }

	void setHit(const bool hit) { this->hit = hit; }
private:
	sf::Sprite sprite;
	bool direction;
	bool tOwner;
	bool hit;
};