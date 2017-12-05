#include "..\Include\Level.hpp"
#include "../Include/Enemy.hpp"

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

std::vector<CharacterMechanics*> Level::getAllColliders() {
	std::vector<CharacterMechanics*> actors;
	for(auto* actor: charactersCollector) {
		auto* enemy = dynamic_cast<Enemy*>(actor);
		if(enemy) {
			actors.push_back(actor);
		}
	}
	return actors;
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

void Level::addStaticObjects(sf::Rect<float> rectangle) {
	staticObjectList.push_back(rectangle);
}
bool Level::checkCollision(sf::Rect<float> rectangle) {
	std::cout << "my x1: " << rectangle.left << "x2: " << rectangle.left + rectangle.width << std::endl;
	for(const auto i : staticObjectList){
		std::cout << " en x1: " << i.left << "x2: " << i.left + i.width << std::endl;
		if (rectangle.intersects(i))
			return true;
	}
	return false;
	std::cout << std::endl;
}

