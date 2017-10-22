#include "Level.hpp"
Level::Level() {

}

Level::~Level() {
	this->cleanLevel();
}

bool Level::addCharacter(CharacterMechanic *character) {
	if (character) {
		if (!this->existCharacter(character)) {
			charactersCollector.push_back(character);
			return true;
		}
	}
	return false;
}

bool Level::removeCharacter(CharacterMechanic *character) {
	if (character) {
		auto characterIterator = std::find(charactersCollector.begin(), charactersCollector.end(), character);
		if (characterIterator != charactersCollector.end()) {
			charactersCollector.erase(characterIterator);
			return true;
		}
	}
	return false;
}

bool Level::existCharacter(CharacterMechanic* character) const {
	return std::find(charactersCollector.begin(), charactersCollector.end(), character) != charactersCollector.end();
}

std::size_t Level::cleanLevel() {
	std::size_t charactersCount = charactersCollector.size();
	for (auto *character : charactersCollector) {
		delete character;
	}
	return charactersCount;
}

void Level::updateLevel(const float &deltaTime) {
	for (auto *character : charactersCollector) {
		character->update(deltaTime);
	}
}

void Level::draw() {
	for (auto *character : charactersCollector) {
		character->draw();
	}
}