#include "../Include/MenuManager.hpp"
#include "../Include/TextureManager.hpp"
#include "../Include/GameManager.hpp"
#include "../Include/MenuManagerController.hpp"

MenuManager::MenuManager() :Player(new MenuManagerController) {
	MenuManager::setLocation(grim::Vector2(0, 0));
	background.setTexture(*TextureManager::getTexture("menubg"));
	championsChoice[0].setTexture(*TextureManager::getTexture("Thalia_BowWalking1"));
	championsChoice[1].setTexture(*TextureManager::getTexture("SecretPlayer"));
	championsChoice[2].setTexture(*TextureManager::getTexture("SecretPlayer"));
	font = GameManager::instance().getFont();
	setContent();
}
void MenuManager::draw() {
	GameManager::instance().getWindow().draw(background);
	for (auto i = 0u; i < 4; i++) {
		GameManager::instance().getWindow().draw(menuTexts[i]);
	}
	if (flag) {
		if (menuStatus == MenuState::newGame) {
			for (auto i = 0u; i < 5; i++) {
				GameManager::instance().getWindow().draw(gameTexts[i]);
			}
			for (auto i = 0u; i < 3; i++) {
				GameManager::instance().getWindow().draw(championsChoice[i]);
			}
		}
		else if (menuStatus == MenuState::load) {
			for (auto i = 0u; i < 4; i++) {
				GameManager::instance().getWindow().draw(loadTexts[i]);
			}
		}
	}
}
void MenuManager::setContent() {
	sf::String temp[] = { "New Game", "Load game", L"Exit" };
	sf::String temp1[] = { "Choose champion", "Thalia Grace", "Not unlocked", "Not unlocked", L"Exit" };
	sf::String temp2[] = { "Load game: ", "First save", "Second save", L"Exit" };
	for (auto i = 0u; i < 4; i++) {
		if (i != 3)
		{
			menuTexts[i].setFont(font);
			menuTexts[i].setCharacterSize(30);
			menuTexts[i].setString(temp[i]);
		}

		loadTexts[i].setFont(font);
		loadTexts[i].setCharacterSize(30);
		loadTexts[i].setString(temp2[i]);

		menuTexts[i].setPosition(50.f, 50.f + i*50.f);
		loadTexts[i].setPosition(200.f, 50.f + i*50.f);
	}
	for (auto i = 0u; i < 5; i++) {
		gameTexts[i].setFont(font);
		gameTexts[i].setCharacterSize(30);
		gameTexts[i].setString(temp1[i]);
	}

	for (auto i = 1u; i < 4; i++) {
		gameTexts[i].setPosition(50.f + 300 * i, 680.f); // 1, 2 i 3
	}
	gameTexts[0].setPosition(700.f, 50.f); // wybierz
	gameTexts[4].setPosition(650.f, 850.f); // wyjdz
}
void MenuManager::setLocation(const grim::Vector2 &location) {
	Player::setLocation(location);
	background.setPosition(location.x, location.y);
	for (auto i = 0u; i < 3; i++) {
		championsChoice[i].setPosition(location.x + 300 * (i + 1), location.y + 250);
	}
}
void MenuManager::updateContent(const sf::Vector2f mouse) {
	if (!flag) {
		for (auto i = 0u; i < 4; i++) {
			if (menuTexts[i].getGlobalBounds().contains(mouse)) {
				menuTexts[i].setFillColor(sf::Color::Red);
			}
			else
				menuTexts[i].setFillColor(sf::Color::Black);
		}
	}
	else {
		if (getStatus() == newGame) {
			for (auto i = 1u; i < 5; i++) {
				if (gameTexts[i].getGlobalBounds().contains(mouse)) {
					gameTexts[i].setFillColor(sf::Color::Red);
				}
				else
					gameTexts[i].setFillColor(sf::Color::Black);
			}
		}
		else if (getStatus() == load) {
			for (auto i = 1u; i < 4; i++) {
				if (loadTexts[i].getGlobalBounds().contains(mouse)) {
					loadTexts[i].setFillColor(sf::Color::Red);
				}
				else
					loadTexts[i].setFillColor(sf::Color::Black);
			}
		}
	}
}