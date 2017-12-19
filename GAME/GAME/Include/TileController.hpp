#pragma once
#include "Player.hpp"
#include "PlayerController.hpp"
#include "Includers.hpp"

class TileController : public PlayerController {
public:
	TileController();
	virtual void update(const float &deltaTime, sf::Event &event) override;
private:

};

