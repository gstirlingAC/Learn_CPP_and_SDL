#include "Game.h"

Game* game = 0;

int main(int argc, char* args[])
{
	game = new Game();

	game->init("Tutorial 11: Creating Game Objects", 100, 100, 640, 480, false);

	while (game->running())
	{
		game->handleEvents();
		game->update();
		game->render();

		SDL_Delay(10); // add the delay
	}

	game->clean();

	return 0;
}