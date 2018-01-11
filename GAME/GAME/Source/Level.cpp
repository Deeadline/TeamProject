#include "../Include/Level.hpp"
#include "../Include/ProjectTile.hpp"
#include "../Include/Tile.hpp"

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
		auto* tile = dynamic_cast<Tile*>(actor);
		if(tile) {
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
		if (charactersCollector[i]->getIsDestroyed()) {
			delete charactersCollector[i];
			charactersCollector.erase(charactersCollector.begin() + i);
			i--;
		}
	}
}

void Level::draw() {
	for (auto i = 0u; i < charactersCollector.size(); i++) {
		charactersCollector[i]->draw();
	}
}

bool Level::checkCollision(sf::Rect<float> rectangle) {
	for(const auto i : charactersCollector){
		auto* tile = dynamic_cast<Tile*>(i);
		if (tile) {
			if (rectangle.intersects(tile->getSprite().getGlobalBounds())) {
				return true;
			}
		}
	}
	return false;
}
