#pragma once
#include "Includers.hpp"
#include "Player.hpp"
class ProjectTile : public Player {
public:
	ProjectTile(const bool direction, const bool tOwner);
	virtual void draw() override;
	virtual void setLocation(const grim::Vector2 &location) override;
	inline bool getIsHit() const{ return hit; }
	inline void setIsHit(const bool hit) { this->hit = hit; }
	inline bool getDirection() { return direction; }
	inline sf::Sprite getSprite() const { return sprite; }
	inline bool getOwner() const { return tOwner; }
private:
	sf::Sprite sprite;
	bool direction;
	bool tOwner;
	bool hit;
};