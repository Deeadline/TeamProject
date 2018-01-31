#pragma once
#include "Player.hpp"
#include "Includers.hpp"

class Tile : public Player {
public:
	explicit Tile(const int);
	virtual void draw() override;
	virtual void setLocation(const grim::Vector2 &location) override;
};