#pragma once
#include "Player.hpp"
#include "Includers.hpp"

class Tile : public Player {
public:
	Tile();
	virtual void draw() override;
	virtual void setLocation(const grim::Vector2 &location) override;
	inline sf::Sprite getSprite() const { return sprite; }
private:
	sf::Sprite sprite;
};