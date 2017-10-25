#include "Include\GameManager.hpp"

int main()
{
	auto &game = GameManager::instance();
	game.runGame();

	return 0;
}