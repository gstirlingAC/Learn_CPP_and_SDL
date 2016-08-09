#include "Game.h"

Game* game = 0;

int main(int argc, char* args[])
{
	game = new Game();

	game->init("Tutorial 5: Fullscreen SDL", 100, 100, 640, 480, false);

	while (game->running())
	{
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();

	return 0;
}