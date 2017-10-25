#pragma once
#include "Player.hpp"

class PlayerController { // klasa do sterowania graczem
public:
	PlayerController();
	virtual ~PlayerController();
	virtual void update(const float &deltaTime) = 0;
	inline bool isPossesed() const { return owner != nullptr; }
	friend class Player;
private:
	bool isPossesed(Player *owner);
	Player* owner;
};