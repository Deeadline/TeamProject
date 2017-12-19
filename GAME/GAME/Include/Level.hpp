#pragma once
#include "CharacterMechanic.hpp"

class Level { //nasza scena/mapa na której wyœwietlamy wszystkie potrzebne obiekty.
public:
	Level();
	~Level();
	bool addCharacter(CharacterMechanics* character);
	bool removeCharacter(CharacterMechanics* character);
	bool existCharacter(CharacterMechanics* character) const;
	std::vector<CharacterMechanics*> getAllColliders();
	std::size_t cleanLevel();
	void updateLevel(const float &deltaTime, sf::Event &event);
	void draw();
	inline std::size_t countCharacter() const { return charactersCollector.size(); }
	bool checkCollision(sf::Rect<float>);
private:
	std::vector<CharacterMechanics *> charactersCollector;
};
