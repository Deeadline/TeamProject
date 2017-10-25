#include "..\Include\GameManager.hpp"
#include "..\Include\TextureManager.hpp"

GameManager::GameManager() : gameStatus(Status::initializing),
	currentWindow(sf::VideoMode(1440, 1080, 32), "Nowa gra", sf::Style::Close),
	currentLevel(new Level()) {
	TextureManager::loadTexture("Sprite_Front", "../Release/Bomberman/Front/Bman_F_f00.png");
}

GameManager::~GameManager() {
	if (currentWindow.isOpen())
		currentWindow.close();
	if (currentLevel)
		delete currentLevel;
}
void GameManager::runGame() {
	gameStatus = Status::running;
	//PercyJackson percy = new PercyJackson();
	// percy.setLocation(x,y);
	// currentLevel->addCharacter(percy);
	sf::Clock gameClock;
	sf::Color backgroundColor(30, 30, 30);
	sf::Sprite tempSprite;
	tempSprite.setTexture(*(TextureManager::getTexture("Sprite_Front")));
	tempSprite.setOrigin(32, 91);
	tempSprite.setPosition(500, 500);
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
		GameManager::instance().getWindow().draw(tempSprite);
		currentWindow.display();

		deltaTime = gameClock.getElapsedTime().asSeconds() - frameStartTime;
	}
}