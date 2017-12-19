#include "../Include/GameManager.hpp"
#include "../Include/TextureManager.hpp"
#include "../Include/Tile.hpp"

#include <Windows.h>
GameManager::GameManager() : gameStatus(Status::initializing),
	currentLevel(new Level()),
	currentWindow(sf::VideoMode(1440, 1080, 32), "Nowa gra", sf::Style::Close){
	//tutaj bedzie wczytywanie z configu i tworzenie okienka o danym rozmiarze, skala bedzie tez wyliczana.
	loadContent();
}
void GameManager::loadContent() {
	TextureManager::loadTexture("Arrow", "../Release/Arrow.png");
	TextureManager::loadTexture("Klocek", "../Release/Klocek.png");

	for (auto i = 1; i <= 12; i++)
		TextureManager::loadTexture("Sprite_Side" + std::to_string(i), "../Release/Thalia/Thalia" + std::to_string(i) + ".png");

	TextureManager::loadTexture("background", "../Release/background.jpg");
	TextureManager::loadTexture("tlo", "../Release/tlo.png");

	for(auto i = 1; i<=7; i++)
		TextureManager::loadTexture("Sprite_Jump" + std::to_string(i), "../Release/Thalia/ThaliaJump" + std::to_string(i) + ".png");

	TextureManager::loadTexture("Sprite_Combat1", "../Release/Thalia/ThaliaJump7.png");
	TextureManager::loadTexture("Sprite_Combat2", "../Release/Thalia/ThaliaJump7.png");
	TextureManager::loadTexture("Sprite_Combat3", "../Release/Thalia/ThaliaJump7.png");

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
void GameManager::setLevel(const std::string levelContent)
{
	if (levelContent == "newGame") {
		currentLevel->removeCharacter(content);
		player = new PercyJackson();
		enemy = new Enemy();

		std::vector<Tile*> tileCollector;
		tileCollector.push_back(new Tile);
		tileCollector.push_back(new Tile);
		tileCollector.push_back(new Tile);
		tileCollector.push_back(new Tile);
		tileCollector[0]->setLocation(grim::Vector2(1000, 400));
		tileCollector[1]->setLocation(grim::Vector2(500, 800));
		tileCollector[2]->setLocation(grim::Vector2(1700, 100));
		tileCollector[3]->setLocation(grim::Vector2(500, 200));
		currentLevel->addCharacter(player);
		currentLevel->addCharacter(enemy);
		currentLevel->addCharacter(tileCollector[0]);
		currentLevel->addCharacter(tileCollector[1]);
		currentLevel->addCharacter(tileCollector[2]);
		currentLevel->addCharacter(tileCollector[3]);
	}
}

void GameManager::runGame() {
	gameStatus = Status::running;
	content = new MenuManager();
	currentLevel->addCharacter(content);
	sf::Clock gameClock;
	auto deltaTime = 1 / 60.f;

	while (gameStatus != Status::cleaningUp) {
		const auto frameStartTime = gameClock.getElapsedTime().asSeconds();
		sf::Event event;
		while (currentWindow.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				gameStatus = Status::cleaningUp;
			}
		}
		currentWindow.clear();
		currentLevel->updateLevel(deltaTime, event);
		currentLevel->draw();
		currentWindow.display();

		deltaTime = gameClock.getElapsedTime().asSeconds() - frameStartTime;
	}
}