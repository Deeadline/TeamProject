#pragma once
#include "Player.hpp"
#include "PercyJacksonController.hpp"
class PercyJackson : public Player { // klasa do poruszania siê graczem.
public: 
	PercyJackson();
	virtual void draw() override;
	virtual void setLocation(const grim::Vector2 &location) override;
	inline void incrementMoveFlag() { moveFlag++; }
	void setSprite();
private:
	sf::Sprite sprite;
	int moveFlag;
};