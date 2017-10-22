#include "GameManager.hpp"

GameManager::GameManager() : gameStatus(Status::initializing),
	window(sf::VideoMode(1440, 1080, 32), "Nowa gra", sf::Style::Close) {

}

GameManager::~GameManager() {
	if (window.isOpen())
		window.close();
}
void GameManager::runGame() {
	gameStatus = Status::running;
	sf::Clock gameClock;
	float deltaTime = 1 / 60.f;

	while (gameStatus != Status::cleaningUp) {
		float frameStartTime = gameClock.getElapsedTime().asSeconds();

		sf::Event windowEvent;
		while (window.pollEvent(windowEvent)) {
			if (windowEvent.type == sf::Event::Closed) {
				gameStatus = Status::cleaningUp;
			}
		}
		window.clear();
		currentLevel->updateLevel(deltaTime);
		currentLevel->draw();
		window.display();

		deltaTime = gameClock.getElapsedTime().asSeconds() - frameStartTime;
	}
}