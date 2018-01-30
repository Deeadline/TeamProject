#pragma once
#include "CharacterMechanic.hpp"

class Level {
public:
	Level();
	~Level();

	bool addCharacter(CharacterMechanics* character);
	bool removeCharacter(CharacterMechanics* character);
	bool existCharacter(CharacterMechanics* character) const;
	bool checkCollision(sf::Rect<float>);
	std::vector<CharacterMechanics*> getCharacters() { return charactersCollector; }
	std::vector<CharacterMechanics*> getAllColliders();
	size_t cleanLevel();
	size_t countCharacter() const { return charactersCollector.size(); }

	void updateLevel(const float &deltaTime);
	void draw();
private:
	std::vector<CharacterMechanics *> charactersCollector;
};
