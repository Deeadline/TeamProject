#include "..\Include\MenuManager.hpp"
#include "..\Include\TextureManager.hpp"
#include "..\Include\GameManager.hpp"

MenuManager::MenuManager() :Player(new MenuManagerController) {
	setLocation(grim::Vector2(0,0));
	background.setTexture(*(TextureManager::getTexture("background")));
	sprite[0].setTexture(*(TextureManager::getTexture("Sprite_Combat1")));
	sprite[1].setTexture(*(TextureManager::getTexture("Sprite_Combat2")));
	sprite[2].setTexture(*(TextureManager::getTexture("Sprite_Combat3")));
	font=GameManager::instance().getFont();
	setContent();
}
void MenuManager::draw() {
	GameManager::instance().getWindow().draw(background);
	for (auto i = 0u; i < 4; i++) {
		GameManager::instance().getWindow().draw(menuContent[i]);
	}
	if (flag) {
		if (menuStatus == menuState::newGame) {
			for (auto i = 0u; i < 5; i++) {
				GameManager::instance().getWindow().draw(newGameContent[i]);
			}
			for (auto i = 0u; i < 3; i++) {
				GameManager::instance().getWindow().draw(sprite[i]);
			}
		}
		else if (menuStatus == menuState::load) {
			for (auto i = 0u; i < 4; i++) {
				GameManager::instance().getWindow().draw(loadContent[i]);
			}
		}
	}
}
void MenuManager::setContent() {
	sf::String temp[] = { "Nowa gra", "Wczytaj", L"WyjdŸ" };
	sf::String temp1[] = { L"Wybierz postaæ", "Pierwsza", "Druga", "Trzecia", L"WyjdŸ" };
	sf::String temp2[] = { "Wczytaj: ", "Zapis gry 1", "Zapis gry 2", L"WyjdŸ" };
	for (auto i = 0u; i < 4; i++) {
		if (i != 3)
		{
			menuContent[i].setFont(font);
			menuContent[i].setCharacterSize(30);
			menuContent[i].setString(temp[i]);
		}

		loadContent[i].setFont(font);
		loadContent[i].setCharacterSize(30);
		loadContent[i].setString(temp2[i]);

		menuContent[i].setPosition(50.f, 50.f + i*50.f);
		loadContent[i].setPosition(200.f, 50.f + i*50.f);
	}
	for (auto i = 0u; i < 5; i++) {
		newGameContent[i].setFont(font);
		newGameContent[i].setCharacterSize(30);
		newGameContent[i].setString(temp1[i]);
	}

	for (auto i = 1u; i < 4; i++) {
		newGameContent[i].setPosition(50.f + 300 * i, 680.f); // 1, 2 i 3
	}
	newGameContent[0].setPosition(700.f, 50.f); // wybierz
	newGameContent[4].setPosition(650.f, 850.f); // wyjdz
}
void MenuManager::setLocation(const grim::Vector2 &location) {
	Player::setLocation(location);
	background.setPosition(location.x, location.y);
	for (auto i = 0u; i < 3; i++) {
		sprite[i].setPosition(location.x + 300*(i+1), location.y + 250);
	}
}
void MenuManager::updateContent(const sf::Vector2f mouse) {
	if (!flag) {
		for (auto i = 0u; i < 4; i++) {
			if (menuContent[i].getGlobalBounds().contains(mouse)) {
				menuContent[i].setFillColor(sf::Color::Red);
			}
			else
				menuContent[i].setFillColor(sf::Color::Black);
		}
	}
	else {
		if (getStatus() == newGame) {
			for (auto i = 1u; i < 5; i++) {
				if (newGameContent[i].getGlobalBounds().contains(mouse)) {
					newGameContent[i].setFillColor(sf::Color::Red);
				}
				else
					newGameContent[i].setFillColor(sf::Color::Black);
			}
		}
		else if (getStatus() == load) {
			for (auto i = 1u; i < 4; i++) {
				if (loadContent[i].getGlobalBounds().contains(mouse)) {
					loadContent[i].setFillColor(sf::Color::Red);
				}
				else
					loadContent[i].setFillColor(sf::Color::Black);
			}
		}
	}
}