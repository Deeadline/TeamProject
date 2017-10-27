#include "..\Include\TextureManager.hpp"

TextureManager::TextureManager() {

}
TextureManager::~TextureManager() {
	for (auto textureData : texturesCollector) {
		delete (textureData.second);
	}
}
sf::Texture* TextureManager::loadTexture(const std::string &textureName, const std::string &texturePath) {
	sf::Texture *result = TextureManager::getTexture(textureName);
	if (result) {
		result->loadFromFile(texturePath);
	}
	else {
		result = new sf::Texture();
		result->loadFromFile(texturePath);
		instance().texturesCollector[textureName] = result;
	}
	return result;
}

bool TextureManager::unLoad(const std::string &textureName) {
	auto &tempInstance = instance();
	auto textureIt = tempInstance.texturesCollector.find(textureName);
	if (textureIt == tempInstance.texturesCollector.end())	{
		return false;
	}
	else {
		delete (textureIt->second);
		tempInstance.texturesCollector.erase(textureIt);
		return true;
	}
}

std::size_t TextureManager::cleanTexture() {
	auto &tempInstance = instance();
	std::size_t textureCount = tempInstance.texturesCollector.size();
	for (auto textureData : tempInstance.texturesCollector) {
		delete (textureData.second);
	}
	return textureCount;
}

sf::Texture * TextureManager::getTexture(const std::string &textureName) {
	auto &tempInstance = instance();
	auto textureIt = tempInstance.texturesCollector.find(textureName);
	if (textureIt == tempInstance.texturesCollector.end()) {
		return nullptr;
	}
	return textureIt->second;
}