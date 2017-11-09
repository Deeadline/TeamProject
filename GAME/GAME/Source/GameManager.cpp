#include "..\Include\GameManager.hpp"
#include "..\Include\TextureManager.hpp"
#include "..\Include\PercyJackson.hpp"
#include <Windows.h>
GameManager::GameManager() : gameStatus(Status::initializing),
	currentWindow(sf::VideoMode(1440, 1080, 32), "Nowa gra", sf::Style::Close),
	currentLevel(new Level()){
	currentWindow.setFramerateLimit(60);
	//tutaj bedzie wczytywanie z configu i tworzenie okienka o danym rozmiarze, skala bedize tez wyliczana.
	loadContent();
}
void GameManager::loadContent() {
	TextureManager::loadTexture("Sprite_Side", "../Release/Thalia/Thalia1.png");
	TextureManager::loadTexture("Sprite_Combat1", "../Release/Thalia/Thalia2.png");
	TextureManager::loadTexture("Sprite_Combat2", "../Release/Thalia/Thalia2.png");
	TextureManager::loadTexture("Sprite_Combat3", "../Release/Thalia/Thalia2.png");
	TextureManager::loadTexture("Sprite_Side1", "../Release/Thalia/Thalia3.png");
	TextureManager::loadTexture("Sprite_Side2", "../Release/Thalia/Thalia4.png");
	TextureManager::loadTexture("background", "../Release/background.jpg");
	TextureManager::loadTexture("tlo", "../Release/tlo.png");
	if (!font.loadFromFile("../Release//Font/tillana.ttf")) {
		MessageBox(NULL, "Font not found!", "ERROR", NULL); return;
	}
}
GameManager::~GameManager() {
	if (currentWindow.isOpen())
		currentWindow.close();
	if (currentLevel)
		delete currentLevel;
}
void GameManager::setLevel(std::string levelContent)
{
	if (levelContent == "newGame") {
		currentLevel->removeCharacter(content);
		auto* player = new PercyJackson();
		currentLevel->addCharacter(player);
	}
}
void GameManager::runGame() {
	gameStatus = Status::running;
	content = new MenuManager();
	currentLevel->addCharacter(content);
	sf::Clock gameClock;
	sf::Color backgroundColor(30, 30, 30);
	float deltaTime = 1 / 60.f;

	while (gameStatus != Status::cleaningUp) {
		float frameStartTime = gameClock.getElapsedTime().asSeconds();
		sf::Event event;
		while (currentWindow.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				gameStatus = Status::cleaningUp;
			}
		}
		currentWindow.clear(backgroundColor);
		currentLevel->updateLevel(deltaTime);
		currentLevel->draw();
		currentWindow.display();

		deltaTime = gameClock.getElapsedTime().asSeconds() - frameStartTime;
	}
}