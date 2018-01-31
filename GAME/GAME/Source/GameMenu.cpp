#include "../Include/GameMenu.hpp"
#include "../Include/GameManager.hpp"
#include "../Include/TextureManager.hpp"
#include "../Include/GameMenuController.hpp"

GameMenu::GameMenu(): Player(new GameMenuController) {
	GameMenu::setLocation(grim::Vector2(0, 0));
	background.setTexture(*(TextureManager::getTexture("menubg")));
	font = GameManager::instance().getFont();
	setTexts();
}

void GameMenu::draw() {
	GameManager::instance().getWindow().draw(background);
	for (auto i = 0u; i < 3; i++) {
		GameManager::instance().getWindow().draw(menuText[i]);
	}
	if (menuStatus == MenuState::save) {
		for (auto i = 0u; i < 3; i++) {
			GameManager::instance().getWindow().draw(saveText[i]);
		}
	}
}

void GameMenu::setLocation(const grim::Vector2& location) {
	Player::setLocation(location);
	background.setPosition(location.x, location.y);
}

void GameMenu::updateTexts(const sf::Vector2f mouse) {
	for (auto i = 0u; i < 3; i++) {
		if (menuText[i].getGlobalBounds().contains(mouse)) {
			menuText[i].setFillColor(sf::Color::Red);
		}
		else
			menuText[i].setFillColor(sf::Color::Black);
	}
	if (menuStatus == save) {
		for (auto i = 1u; i < 3; i++) {
			if (saveText[i].getGlobalBounds().contains(mouse)) {
				saveText[i].setFillColor(sf::Color::Red);
			}
			else
				saveText[i].setFillColor(sf::Color::Black);
		}
	}
}

void GameMenu::setTexts() {

	sf::String temp[] = {  "Return", "Save game", "Exit" };
	sf::String temp2[] = { "Save game: ", "First save", "Return" };
	for (auto i = 0; i < 3; i++) {
		menuText[i].setFont(font);
		menuText[i].setCharacterSize(30);
		menuText[i].setString(temp[i]);
		menuText[i].setPosition(50.f, 50.f + i*50.f);

		saveText[i].setFont(font);
		saveText[i].setCharacterSize(30);
		saveText[i].setString(temp2[i]);
		saveText[i].setPosition(200.f, 50.f + i*50.f);
	}
}
