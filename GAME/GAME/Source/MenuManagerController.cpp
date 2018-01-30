#include "../Include/MenuManagerController.hpp"
#include "../Include/GameManager.hpp"

MenuManagerController::MenuManagerController() {

}
void MenuManagerController::update(const float &deltaTime) {
	auto* tempOwner = dynamic_cast<MenuManager*>(owner);
	const sf::Vector2f mouse(sf::Mouse::getPosition(GameManager::instance().getWindow()));
	if (!tempOwner->getFlag()) {
		if (tempOwner->menuText(0).getGlobalBounds().contains(mouse) &&
			sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			tempOwner->setFlag(true);
			tempOwner->setStatus(MenuManager::MenuState::newGame);
		}
		else if (tempOwner->menuText(1).getGlobalBounds().contains(mouse) &&
			sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			tempOwner->setFlag(true);
			tempOwner->setStatus(MenuManager::MenuState::load);
		}
		else if (tempOwner->menuText(2).getGlobalBounds().contains(mouse) &&
			sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) ||
			sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
			GameManager::instance().setStatus(GameManager::Status::cleaningUp);
		}
	}
	else {
		if (tempOwner->getStatus() == MenuManager::MenuState::newGame) {
			if ((tempOwner->gameText(1).getGlobalBounds().contains(mouse) ||
				tempOwner->getSpriteBounds(0).contains(mouse)) &&
				sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				GameManager::instance().setLevel("Introduce", false);
			}
			else if (tempOwner->gameText(4).getGlobalBounds().contains(mouse) &&
				sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				tempOwner->setFlag(false);
			}
		}
		else if (tempOwner->getStatus() == MenuManager::MenuState::load) {
			if (tempOwner->loadText(1).getGlobalBounds().contains(mouse) &&
				sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				tempOwner->setFlag(false);
			}
			else if (tempOwner->loadText(2).getGlobalBounds().contains(mouse) &&
				sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				tempOwner->setFlag(false);
			}
			else if (tempOwner->loadText(3).getGlobalBounds().contains(mouse) &&
				sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				tempOwner->setFlag(false);
			}
		}
	}
	tempOwner->updateContent(mouse);
}