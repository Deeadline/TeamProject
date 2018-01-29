#include "../Include/GameManager.hpp"
#include "../Include/TextureManager.hpp"
#include "../Include/Tile.hpp"
#include "../Include/Introducer.hpp"

#include <Windows.h>
#include "../Include/GameMenu.hpp"
#include <random>

GameManager::GameManager() : gameStatus(Status::initializing),
	currentLevel(new Level()),
	currentWindow(sf::VideoMode(1440, 1080, 32), "Nowa gra", sf::Style::Close){
	//tutaj bedzie wczytywanie z configu i tworzenie okienka o danym rozmiarze, skala bedzie tez wyliczana.
	loadContent();
}
void GameManager::loadContent() {
	TextureManager::loadTexture("Arrow", "../Release/Arrow.png");
	TextureManager::loadTexture("Rock1", "../Release/Tile/theRock1.png");
	TextureManager::loadTexture("Rock2", "../Release/Tile/theRock2.png");
	TextureManager::loadTexture("Rock3", "../Release/Tile/theRock3.png");
	TextureManager::loadTexture("RockyA", "../Release/RockyA.png");
	TextureManager::loadTexture("RockyB", "../Release/RockyB.png");

	TextureManager::loadTexture("loading", "../Release/loadingScreen.png");
	TextureManager::loadTexture("shadow", "../Release/phil.png");

	for (auto i = 1; i <= 12; i++) {
		TextureManager::loadTexture("Sprite_Side" + std::to_string(i), "../Release/Thalia/Thalia" + std::to_string(i) + ".png");
		TextureManager::loadTexture("Sprite_Side0" + std::to_string(i), "../Release/ThaliaWalkingCycleBowLast/ThaliaWalkBow" + std::to_string(i) + ".png");
	}
	TextureManager::loadTexture("Sprite_Attack1", "../Release/ThaliaKnifeAttack/ThaliaKnifeAttack1NoBow.png");
	TextureManager::loadTexture("Sprite_Attack2", "../Release/ThaliaKnifeAttack/ThaliaKnifeAttack2NoBow.png");
	TextureManager::loadTexture("Sprite_Attack01", "../Release/ThaliaKnifeAttack/ThaliaKnifeAttack1.png");
	TextureManager::loadTexture("Sprite_Attack02", "../Release/ThaliaKnifeAttack/ThaliaKnifeAttack22.png");


	TextureManager::loadTexture("background", "../Release/background.jpg");
	TextureManager::loadTexture("tlo", "../Release/tlo.png");
	TextureManager::loadTexture("tlo2", "../Release/tlo2.png");
	TextureManager::loadTexture("tlo3", "../Release/tlo3.png");
	TextureManager::loadTexture("shop", "../Release/sklep.png");

	for (auto i = 1; i <= 7; i++)
		TextureManager::loadTexture("Sprite_Jump" + std::to_string(i), "../Release/Thalia/ThaliaJump" + std::to_string(i) + ".png");
	for(auto i=1; i<=6;i++)
		TextureManager::loadTexture("Sprite_Jump0" + std::to_string(i), "../Release/ThaliaJumpBow/ThaliaJumpBow" + std::to_string(i) + ".png");

	TextureManager::loadTexture("Sprite_Combat1", "../Release/ThaliaJumpBow/ThaliaJumpBow1.png");
	TextureManager::loadTexture("Sprite_Combat2", "../Release/Thalia/ThaliaJump7.png");
	TextureManager::loadTexture("Sprite_Combat3", "../Release/Thalia/ThaliaJump7.png");

	currentWindow.setFramerateLimit(40);
	viewMenu.setSize(currentWindow.getSize().x,currentWindow.getSize().y);
	viewGame.setSize(currentWindow.getSize().x, currentWindow.getSize().y);
	viewMenu.setCenter(currentWindow.getSize().x / 2, currentWindow.getSize().y / 2);
	currentWindow.setView(viewMenu);

	if (!font.loadFromFile("../Release//Font/tillana.ttf")) {
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
		player = new PercyJackson();
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
		player = new PercyJackson();
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
	std::srand(time(NULL));
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