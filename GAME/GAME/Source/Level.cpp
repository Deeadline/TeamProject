#include "../Include/Level.hpp"
#include "../Include/ProjectTile.hpp"
#include "../Include/Tile.hpp"
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
		const auto characterIterator = std::find(charactersCollector.begin(), charactersCollector.end(), character);
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
	for (auto* actor : charactersCollector) {
		auto* tile = dynamic_cast<Tile*>(actor);
		if (tile) {
			actors.push_back(actor);
		}
	}
	return actors;
}

std::vector<CharacterMechanics*> Level::getEnemies() {
	std::vector<CharacterMechanics*> actors;
	for (auto* actor : charactersCollector) {
		auto* enemy = dynamic_cast<Enemy*>(actor);
		if (enemy) {
			actors.push_back(actor);
		}
	}
	return actors;
}

std::size_t Level::cleanLevel() {
	const auto charactersCount = charactersCollector.size();
	for (auto *character : charactersCollector) {
		delete character;
	}
	charactersCollector.resize(0);
	return charactersCount;
}

void Level::updateLevel(const float &deltaTime) {
	for (auto i = 0u; i < charactersCollector.size(); i++) {
		charactersCollector[i]->update(deltaTime);
		if (charactersCollector[i]->isDestroyed()) {
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
	for (const auto i : charactersCollector) {
		auto* tile = dynamic_cast<Tile*>(i);
		if (tile) {
			if (rectangle.intersects(tile->getSprite().getGlobalBounds())) {
				return true;
			}
		}
	}
	return false;
}
