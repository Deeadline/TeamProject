#include "../Include/GameManager.hpp"
#include "../Include/TextureManager.hpp"
#include "../Include/Tile.hpp"
#include "../Include/GameMenu.hpp"

#include <Windows.h>
#include <random>

GameManager::GameManager() : gameStatus(Status::initializing),
	currentLevel(new Level()),
	currentWindow(sf::VideoMode(1440, 1080, 32), "Percy Jackson Game", sf::Style::Default){
	//tutaj bedzie wczytywanie z configu i tworzenie okienka o danym rozmiarze, skala bedzie tez wyliczana.
	loadContent();
}
void GameManager::loadContent() {
	//Load colliders textures
	for (auto i = 1; i< 4; i++)
		TextureManager::loadTexture("Rock" + std::to_string(i), "../Release/Tile/theRock" + std::to_string(i) + ".png");
	TextureManager::loadTexture("RockThrowing", "../Release/Tile/ThrowingRock.png");
	TextureManager::loadTexture("Arrow", "../Release/Tile/Arrow.png");

	//Load maps textures
	TextureManager::loadTexture("menubg", "../Release/Screen/background.jpg");
	TextureManager::loadTexture("gamebg1", "../Release/Screen/tlo.png");
	TextureManager::loadTexture("gamebg2", "../Release/Screen/tlo2.png");
	TextureManager::loadTexture("gamebg3", "../Release/Screen/tlo3.png");
	TextureManager::loadTexture("gamebg4", "../Release/Screen/sklep.png");
	TextureManager::loadTexture("loading", "../Release/Screen/loadingScreen.png");

	//Load player and enemy textures
	TextureManager::loadTexture("Phil", "../Release/Characters/phil.png");

	for (auto i = 1; i < 13; i++) {
		TextureManager::loadTexture("Thalia_Walking" + std::to_string(i), "../Release/Thalia/NoBow/Thalia" + std::to_string(i) + ".png");
		TextureManager::loadTexture("Thalia_BowWalking" + std::to_string(i), "../Release/Thalia/Bow/ThaliaWalk0" + std::to_string(i) + ".png");
		TextureManager::loadTexture("Rocky_Walking" + std::to_string(i), "../Release/RockyWalk/RockyWalk" + std::to_string(i) + ".png");
	}

	for (auto i = 1; i<7; i++) {
		TextureManager::loadTexture("Thalia_Jump" + std::to_string(i), "../Release/Thalia/NoBow/ThaliaJump" + std::to_string(i) + ".png");
		TextureManager::loadTexture("Thalia_BowJump" + std::to_string(i), "../Release/Thalia/Bow/ThaliaJump0" + std::to_string(i) + ".png");
		TextureManager::loadTexture("Rocky_Attack" + std::to_string(i), "../Release/RockyThrowRock/RockyThrow0" + std::to_string(i) + ".png");
	}

	for (auto i = 0; i<2; i++) {
		TextureManager::loadTexture("Thalia_AttackKnifeNoBow" + std::to_string(i + 1), "../Release/Thalia/NoBow/ThaliaKnife0" + std::to_string(i) + ".png");
		TextureManager::loadTexture("Thalia_AttackKnifeBow" + std::to_string(i + 1), "../Release/Thalia/Bow/ThaliaKnife" + std::to_string(i) + ".png");
	}

	TextureManager::loadTexture("SecretPlayer", "../Release/Thalia/SecondPlayer.png");

	currentWindow.setFramerateLimit(40);
	viewMenu.setSize(currentWindow.getSize().x, currentWindow.getSize().y);
	viewGame.setSize(currentWindow.getSize().x, currentWindow.getSize().y);
	viewMenu.setCenter(currentWindow.getSize().x / 2, currentWindow.getSize().y / 2);
	currentWindow.setView(viewMenu);

	if (!font.loadFromFile("../Release/Font/tillana.ttf")) {
		MessageBox(NULL, "Font not found!", "ERROR", NULL);
	}
}
GameManager::~GameManager() {
	if (currentWindow.isOpen())
		currentWindow.close();
	if (currentLevel)
		delete currentLevel;
}
void GameManager::setLevel(const std::string levelContent, const bool wasMenu)
{
	this->levelContent = levelContent;
	enemy = new Enemy();
	if (player == nullptr) {
		player = new Thalia();
	}
	if (levelContent == "Introduce") {
		currentLevel->removeCharacter(content);
		currentLevel->addCharacter(player);
		currentLevel->addCharacter(enemy);
		std::vector<Tile*> tileCollector;
		for (auto i = 0; i < 6; i++) {
			tileCollector.push_back(new Tile(rand() % 3 + 1));
			tileCollector[i]->setLocation(grim::Vector2(400 + i * 350, 880));
			currentLevel->addCharacter(tileCollector[i]);
		}
	}
	if (levelContent == "Medusa") {
		std::cout << currentLevel->cleanLevel();
		player = new Thalia();
		enemy = new Enemy();
		currentLevel->addCharacter(player);
		currentLevel->addCharacter(enemy);
		std::vector<Tile*> tileCollector;
		for (auto i = 0; i < 6; i++) {
			tileCollector.push_back(new Tile(rand() % 3 + 1));
			tileCollector[i]->setLocation(grim::Vector2(400 + i * 150, 980));
			currentLevel->addCharacter(tileCollector[i]);
		}
	}
}

void GameManager::runGame() {
	srand(time(NULL));
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
		currentLevel->updateLevel(deltaTime);
		currentLevel->draw();
		currentWindow.display();

		deltaTime = gameClock.getElapsedTime().asSeconds() - frameStartTime;
	}
}