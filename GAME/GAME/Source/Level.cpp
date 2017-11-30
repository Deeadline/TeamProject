#include "..\Include\Level.hpp"
Level::Level() {

}

Level::~Level() {
	this->cleanLevel();
}

bool Level::addCharacter(CharacterMechanics *character) {
	if (character) {
		if (!this->existCharacter(character)) {
			charactersCollector.push_back(character);
			return true;
		}
	}
	return false;
}

bool Level::removeCharacter(CharacterMechanics *character) {
	if (character) {
		auto characterIterator = std::find(charactersCollector.begin(), charactersCollector.end(), character);
		if (characterIterator != charactersCollector.end()) {
			charactersCollector.erase(characterIterator);
			return true;
		}
	}
	return false;
}

bool Level::existCharacter(CharacterMechanics* character) const {
	return std::find(charactersCollector.begin(), charactersCollector.end(), character) != charactersCollector.end();
}

std::size_t Level::cleanLevel() {
	std::size_t charactersCount = charactersCollector.size();
	for (auto *character : charactersCollector) {
		delete character;
	}
	return charactersCount;
}

void Level::updateLevel(const float &deltaTime, sf::Event &event) {
	for (auto i = 0u; i < charactersCollector.size();i++) {
		charactersCollector[i]->update(deltaTime, event);
	}
}

void Level::draw() {
	for (auto i = 0u; i < charactersCollector.size(); i++) {
		charactersCollector[i]->draw();
	}
}