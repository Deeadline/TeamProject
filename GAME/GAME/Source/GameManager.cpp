#include "..\Include\GameManager.hpp"
#include "..\Include\TextureManager.hpp"
#include "..\Include\PercyJackson.hpp"
#include <Windows.h>
GameManager::GameManager() : gameStatus(Status::initializing),
	currentWindow(sf::VideoMode(1440, 1080, 32), "Nowa gra", sf::Style::Close),
	currentLevel(new Level()){
	//tutaj bedzie wczytywanie z configu i tworzenie okienka o danym rozmiarze, skala bedize tez wyliczana.
	TextureManager::loadTexture("Sprite_Side", "../Release/Thalia1.png");
	TextureManager::loadTexture("Sprite_Side1", "../Release/Thalia3.png");
	TextureManager::loadTexture("Sprite_Side2", "../Release/Thalia4.png");
	TextureManager::loadTexture("background", "../Release/background.jpg");
	if (!font.loadFromFile("../Release/menuFont.ttf")) {
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

		/*sf::Event windowEvent;

		while (currentWindow.pollEvent(windowEvent)) {
			if (windowEvent.type == sf::Event::Closed || 
				(windowEvent.type == sf::Event::KeyPressed && windowEvent.key.code == sf::Keyboard::Escape)) {
				gameStatus = Status::cleaningUp;
			}
		}
		*/
		currentWindow.clear(backgroundColor);
		currentLevel->updateLevel(deltaTime);
		currentLevel->draw();
		currentWindow.display();

		deltaTime = gameClock.getElapsedTime().asSeconds() - frameStartTime;
	}
}