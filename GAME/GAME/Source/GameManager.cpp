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
	TextureManager::loadTexture("Sprite_Side", "../Release/Thalia2/Thalia1.png");
	TextureManager::loadTexture("Sprite_Side1", "../Release/Thalia2/Thalia2.png");
	TextureManager::loadTexture("Sprite_Side2", "../Release/Thalia2/Thalia3.png");
	TextureManager::loadTexture("Sprite_Side3", "../Release/Thalia2/Thalia4.png");
	TextureManager::loadTexture("Sprite_Side4", "../Release/Thalia2/Thalia5.png");
	TextureManager::loadTexture("Sprite_Side5", "../Release/Thalia2/Thalia6.png");
	TextureManager::loadTexture("Sprite_Side6", "../Release/Thalia2/Thalia7.png");
	TextureManager::loadTexture("Sprite_Side7", "../Release/Thalia2/Thalia8.png");
	TextureManager::loadTexture("Sprite_Side8", "../Release/Thalia2/Thalia9.png");
	TextureManager::loadTexture("Sprite_Side9", "../Release/Thalia2/Thalia10.png");
	TextureManager::loadTexture("Sprite_Side10", "../Release/Thalia2/Thalia11.png");
	TextureManager::loadTexture("Sprite_Side11", "../Release/Thalia2/Thalia12.png");

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