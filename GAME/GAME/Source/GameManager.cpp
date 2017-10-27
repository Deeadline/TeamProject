#include "..\Include\GameManager.hpp"
#include "..\Include\TextureManager.hpp"
#include "..\Include\PercyJackson.hpp"
GameManager::GameManager() : gameStatus(Status::initializing),
	currentWindow(sf::VideoMode(1440, 1080, 32), "Nowa gra", sf::Style::Close),
	currentLevel(new Level()){
	//tutaj bedzie wczytywanie z configu i tworzenie okienka o danym rozmiarze, skala bedize tez wyliczana.
	TextureManager::loadTexture("Sprite_Side", "../Release/Bomberman/Side/Bman_F_f00.png");
	TextureManager::loadTexture("Sprite_Side1", "../Release/Bomberman/Side/Bman_F_f03.png");
	TextureManager::loadTexture("Sprite_Side2", "../Release/Bomberman/Side/Bman_F_f07.png");
}

GameManager::~GameManager() {
	if (currentWindow.isOpen())
		currentWindow.close();
	if (currentLevel)
		delete currentLevel;
}
void GameManager::runGame() {
	gameStatus = Status::running;
	auto *player = new PercyJackson();
	 currentLevel->addCharacter(player);
	sf::Clock gameClock;
	sf::Color backgroundColor(30, 30, 30);
	float deltaTime = 1 / 60.f;

	while (gameStatus != Status::cleaningUp) {
		float frameStartTime = gameClock.getElapsedTime().asSeconds();

		sf::Event windowEvent;

		while (currentWindow.pollEvent(windowEvent)) {
			if (windowEvent.type == sf::Event::Closed || (windowEvent.type == sf::Event::KeyPressed && windowEvent.key.code == sf::Keyboard::Escape)) {
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