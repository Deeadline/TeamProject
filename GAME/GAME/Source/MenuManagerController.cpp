#include "..\Include\MenuManagerController.hpp"
#include "..\Include\GameManager.hpp"

MenuManagerController::MenuManagerController() {

}
void MenuManagerController::update(const float &deltaTime, sf::Event &event) {
	auto* tempOwner = dynamic_cast<MenuManager*>(owner);
	sf::Vector2f mouse(sf::Mouse::getPosition(GameManager::instance().getWindow()));
	if (!tempOwner->getFlag()) {
		if (tempOwner->getMenuContent(0).getGlobalBounds().contains(mouse) &&
			sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			tempOwner->setFlag(true);
			tempOwner->setStatus(MenuManager::menuState::newGame);
		}
		else if (tempOwner->getMenuContent(1).getGlobalBounds().contains(mouse) &&
			sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			tempOwner->setFlag(true);
			tempOwner->setStatus(MenuManager::menuState::load);
		}
		else if ((tempOwner->getMenuContent(3).getGlobalBounds().contains(mouse) &&
			sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) ||
			(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))) {
			GameManager::instance().setStatus(GameManager::Status::cleaningUp);
		}
	}
	else {
		if (tempOwner->getStatus() == MenuManager::menuState::newGame) {
			if ((tempOwner->getNewGameContent(1).getGlobalBounds().contains(mouse) ||
				tempOwner->getSpriteBounds(0).contains(mouse))&&
				sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				GameManager::instance().setLevel("Introduce");
			}
			else if (tempOwner->getNewGameContent(4).getGlobalBounds().contains(mouse) &&
				sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				tempOwner->setFlag(false);
			}
		}
		else if (tempOwner->getStatus() == MenuManager::menuState::load) {
			if (tempOwner->getLoadContent(1).getGlobalBounds().contains(mouse) &&
				sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				tempOwner->setFlag(false);
			}
			else if (tempOwner->getLoadContent(2).getGlobalBounds().contains(mouse) &&
				sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				tempOwner->setFlag(false);
			}
			else if (tempOwner->getLoadContent(3).getGlobalBounds().contains(mouse) &&
				sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				tempOwner->setFlag(false);
			}
		}
	}
	tempOwner->updateContent(mouse);
}