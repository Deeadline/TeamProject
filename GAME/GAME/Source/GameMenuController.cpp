//#include "../Include/GameMenuController.hpp"
//#include "../Include/GameManager.hpp"
//
//GameMenuController::GameMenuController() {
//}
//
//void GameMenuController::update(const float& deltaTime, sf::Event& event) {
////	auto* tempOwner = dynamic_cast<GameMenu*>(owner);
////	sf::Vector2f mouse(sf::Mouse::getPosition(GameManager::instance().getWindow()));
////	if (!tempOwner->getFlag()) {
////		if (tempOwner->getMenuContent(0).getGlobalBounds().contains(mouse) &&
////			sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
////			GameManager::instance().setLevel(tempOwner->getLevelName(),true);
////		}
////		else if (tempOwner->getMenuContent(1).getGlobalBounds().contains(mouse) &&
////			sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
////			tempOwner->setFlag(true);
////			tempOwner->setStatus(GameMenu::menuState::save);
////		}
////		else if ((tempOwner->getMenuContent(3).getGlobalBounds().contains(mouse) &&
////			sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) ||
////			(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))) {
////			GameManager::instance().setStatus(GameManager::Status::cleaningUp);
////		}
////	}
////	else {
////		if (tempOwner->getStatus() == GameMenu::menuState::save) {
////			if (tempOwner->getSaveContent(1).getGlobalBounds().contains(mouse) &&
////				sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
////				tempOwner->setFlag(false);
////			}
////			else if (tempOwner->getSaveContent(2).getGlobalBounds().contains(mouse) &&
////				sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
////				tempOwner->setFlag(false);
////			}
////		}
////	}
////	tempOwner->updateContent(mouse);
//}
