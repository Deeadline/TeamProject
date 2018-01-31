#include "../Include/GameMenuController.hpp"
#include "../Include/GameManager.hpp"
#include "../Include/GameMenu.hpp"

GameMenuController::GameMenuController() {
}

void GameMenuController::update(const float& deltaTime) {
	auto* tempOwner = dynamic_cast<GameMenu*>(owner);
	const sf::Vector2f mouse(sf::Mouse::getPosition(GameManager::instance().getWindow()));
	if (!tempOwner->getFlag()) {
		if (tempOwner->getMenuText(0).getGlobalBounds().contains(mouse) &&
			sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			tempOwner->setDestroyed(true);
		}
		else if (tempOwner->getMenuText(1).getGlobalBounds().contains(mouse) &&
			sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			tempOwner->setFlag(true);
			tempOwner->setStatus(GameMenu::MenuState::save);
		}
		else if ((tempOwner->getMenuText(3).getGlobalBounds().contains(mouse) &&
			sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) ||
			(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))) {
			GameManager::instance().setStatus(GameManager::Status::cleaningUp);
		}
	}
	else {
		if (tempOwner->getStatus() == MenuManager::MenuState::newGame) {
			if (tempOwner->getSaveText(1).getGlobalBounds().contains(mouse) &&
				sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				tempOwner->setFlag(false);
			}
			else if (tempOwner->getSaveText(2).getGlobalBounds().contains(mouse) &&
				sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				tempOwner->setFlag(false);
			}
		}
	}
	tempOwner->updateTexts(mouse);
}
