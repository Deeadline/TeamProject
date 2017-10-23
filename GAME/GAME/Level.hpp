#pragma once
#include "CharacterMechanic.hpp"

class Level { //nasza scena/mapa na której wyœwietlamy wszystkie potrzebne obiekty.
public:
	Level();
	~Level();
	bool addCharacter(CharacterMechanic* character);
	bool removeCharacter(CharacterMechanic* character);
	bool existCharacter(CharacterMechanic* character) const;
	std::size_t cleanLevel();
	void updateLevel(const float &deltaTime);
	void draw();
	inline std::size_t countCharacter() const { return charactersCollector.size(); }
private:
	std::vector<CharacterMechanic *> charactersCollector;;
};