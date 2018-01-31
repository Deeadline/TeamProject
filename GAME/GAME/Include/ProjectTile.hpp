#pragma once
#include "Includers.hpp"
#include "Player.hpp"
class ProjectTile : public Player {
public:
	ProjectTile(const bool, const int, const grim::Vector2 &location);
	virtual void draw() override;
	virtual void setLocation(const grim::Vector2 &location) override;
	virtual void setDamage(const int damage) override;
	enum TileType {
		arrow = 1,
		rock = 2
	};
	TileType getType() const { return tile; }
	bool isHit() const { return hit; }
	bool getDirection() { return direction; }

	void setHit(const bool hit) { this->hit = hit; }
private:
	bool direction;
	bool hit;
	TileType tile;
};