#pragma once
#include "Player.hpp"
#include "PercyJacksonController.hpp"
class PercyJackson : public Player { // klasa do poruszania siê graczem.
public: 
	PercyJackson();
	virtual void draw() override;
	virtual void setLocation(const grim::Vector2 &location) override;
	inline void incrementMoveFlag() { moveFlag++; }
	inline void setMoveFlag() { moveFlag = 0; }
	void setSprite(bool);
	inline sf::Sprite getSprite() const { return sprite; }
private:
	sf::Sprite sprite;
	sf::Sprite background;
	int moveFlag;
};