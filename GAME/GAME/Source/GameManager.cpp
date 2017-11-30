#include "..\Include\GameManager.hpp"
#include "..\Include\TextureManager.hpp"

#include <Windows.h>
GameManager::GameManager() : gameStatus(Status::initializing),
	currentWindow(sf::VideoMode(1440, 1080, 32), "Nowa gra", sf::Style::Close),
	currentLevel(new Level()){
	//tutaj bedzie wczytywanie z configu i tworzenie okienka o danym rozmiarze, skala bedize tez wyliczana.
	loadContent();
}

void GameManager::loadContent() {
	for (int i = 1; i <= 12; i++) {
		TextureManager::loadTexture("Sprite_Side"+std::to_string(i), "../Release/Thalia2/Thalia"+ std::to_string(i) +".png");
	}

	TextureManager::loadTexture("background", "../Release/background.jpg");
	TextureManager::loadTexture("tlo", "../Release/tlo.png");

	TextureManager::loadTexture("Sprite_Combat1", "../Release/Thalia/Thalia2.png");
	TextureManager::loadTexture("Sprite_Combat2", "../Release/Thalia/Thalia2.png");
	TextureManager::loadTexture("Sprite_Combat3", "../Release/Thalia/Thalia2.png");
	currentWindow.setFramerateLimit(40);
	viewMenu.setSize(currentWindow.getSize().x,currentWindow.getSize().y);
	viewGame.setSize(currentWindow.getSize().x, currentWindow.getSize().y);
	viewMenu.setCenter(currentWindow.getSize().x / 2, currentWindow.getSize().y / 2);
	currentWindow.setView(viewMenu);

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
		player = new PercyJackson();
		enemy = new Enemy();
		currentLevel->addCharacter(player);
		//currentLevel->addCharacter(enemy);
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