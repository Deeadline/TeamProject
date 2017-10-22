#pragma once
#include "Includers.hpp"
#include "Player.hpp"

class PlayerController {
public:
	PlayerController();
	virtual ~PlayerController();
	virtual void update(const float &deltaTime) = 0;
	inline bool isPossesed() const { return owner != nullptr; }
	friend class Player;
private:
	bool posses(Player *owner);
	Player* owner;
};