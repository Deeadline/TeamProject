#pragma once
#include <unordered_map>
#include "Includers.hpp"
class TextureManager {
public:
	~TextureManager();

	static TextureManager& instance() {
		static TextureManager instance;
		return instance;
	}

	static sf::Texture* loadTexture(const std::string &textureName, const std::string &texturePath);
	static bool unLoad(const std::string &textureName);
	static std::size_t cleanTexture();
	static sf::Texture* getTexture(const std::string &textureName);
	static bool isExistTexture(const std::string &textureName) { return getTexture(textureName) != nullptr; }
private:
	TextureManager();
	TextureManager(const TextureManager &) = delete;
	void operator=(const TextureManager &) = delete;
	std::unordered_map<std::string, sf::Texture*> texturesCollector;
};