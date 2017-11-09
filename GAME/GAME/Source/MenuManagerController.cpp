#include "..\Include\MenuManagerController.hpp"
#include "..\Include\GameManager.hpp"
#include "..\Include\TextureManager.hpp"

MenuManagerController::MenuManagerController() {

}
void MenuManagerController::update(const float &deltaTime) {
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
		else if (tempOwner->getMenuContent(2).getGlobalBounds().contains(mouse) &&
			sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			tempOwner->setFlag(true);
			tempOwner->setStatus(MenuManager::menuState::options);

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
				GameManager::instance().setLevel("newGame");
			}
			else if ((tempOwner->getNewGameContent(2).getGlobalBounds().contains(mouse) ||
				tempOwner->getSpriteBounds(1).contains(mouse)) &&
				sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				GameManager::instance().setLevel("newGame");
			}
			else if ((tempOwner->getNewGameContent(3).getGlobalBounds().contains(mouse) ||
				tempOwner->getSpriteBounds(2).contains(mouse)) &&
				sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				GameManager::instance().setLevel("newGame");
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
		else if (tempOwner->getStatus() == MenuManager::menuState::options) {
			if (tempOwner->getOptionsContent(1).getGlobalBounds().contains(mouse) &&
				sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				tempOwner->setFlag(false);
			}
			else if (tempOwner->getOptionsContent(2).getGlobalBounds().contains(mouse) &&
				sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				tempOwner->setFlag(false);
			}
			else if (tempOwner->getOptionsContent(3).getGlobalBounds().contains(mouse) &&
				sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
				tempOwner->setFlag(false);
			}
		}
	}
	tempOwner->updateContent(mouse);
}