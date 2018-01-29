//#include "../Include/GameMenu.hpp"
//#include "../Include/GameManager.hpp"
//#include "../Include/TextureManager.hpp"

//GameMenu::GameMenu(): Player(new GameMenuController) {
	//setLocation(grim::Vector2(0, 0));
	//background.setTexture(*(TextureManager::getTexture("background")));
	//font = GameManager::instance().getFont();
	//setContent();
//}
//
//void GameMenu::draw() {
//	GameManager::instance().getWindow().draw(background);
//	for (auto i = 0u; i < 3; i++) {
//		GameManager::instance().getWindow().draw(menuContent[i]);
//	}
//	if (menuStatus == menuState::save) {
//		for (auto i = 0u; i < 3; i++) {
//			GameManager::instance().getWindow().draw(saveContent[i]);
//		}
//	}
//}
//
//void GameMenu::setLocation(const grim::Vector2& location) {
//	Player::setLocation(location);
//	background.setPosition(location.x, location.y);
//}
//
//void GameMenu::updateContent(const sf::Vector2f mouse) {
//	for (auto i = 0u; i < 3; i++) {
//		if (menuContent[i].getGlobalBounds().contains(mouse)) {
//			menuContent[i].setFillColor(sf::Color::Red);
//		}
//		else
//			menuContent[i].setFillColor(sf::Color::Black);
//		//	else {
//		//		if (getStatus() == save) {
//		//			for (auto i = 1u; i < 3; i++) {
//		//				if (saveContent[i].getGlobalBounds().contains(mouse)) {
//		//					saveContent[i].setFillColor(sf::Color::Red);
//		//				}
//		//				else
//		//					saveContent[i].setFillColor(sf::Color::Black);
//		//			}
//		//		}
//		//	}
//	}
//}
//
//void GameMenu::setContent() {
//	sf::String temp[] = {  L"Wróæ do gry", "Zapisz grê", "WyjdŸ" };
//	sf::String temp2[] = { "Zapisz: ", "Zapis gry 1", L"WyjdŸ" };
//	for (auto i = 0u; i < 3; i++) {
//		std::cout << i << std::endl;
//			menuContent[i].setFont(font);
//			menuContent[i].setCharacterSize(30);
//			menuContent[i].setString(temp[i]);
//
//		saveContent[i].setFont(font);
//		saveContent[i].setCharacterSize(30);
//		saveContent[i].setString(temp2[i]);
//
//		menuContent[i].setPosition(50.f, 50.f + i*50.f);
//		saveContent[i].setPosition(200.f, 50.f + i*50.f);
//	}
//}
