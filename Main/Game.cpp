#include<iostream> // import this module to allow us to use console window features such as outputting to the console
#include "Game.h"

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen)
{
	int flags = 0;

	if (fullScreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	// attempt to initialise SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL init success\n";

		// init the window
		pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (pWindow != 0) // window init success
		{
			std::cout << "window creation success";
			pRenderer = SDL_CreateRenderer(pWindow, -1, 0);

			if (pRenderer != 0) // renderer init success
			{
				std::cout << "renderer creation success\n";
				SDL_SetRenderDrawColor(pRenderer, 255, 0, 0, 255);
			}
			else
			{
				std::cout << "renderer init fail\n";
				return false; // renderer init fail
			}
		}
		else
		{
			std::cout << "window init fail\n";
			return false; // window init fail
		}
	}
	else
	{
		std::cout << "SDL init fail\n";
		return false; // SDL init fail
	}

	std::cout << "init success\n";
	bRunning = true; // everything inited successfully
	
	// to load
	if (!TheTextureManager::pInstance()->load("Assets/animate-alpha.png", "animate", pRenderer))
	{
		return false;
	}

	go.load(100, 100, 128, 82, "animate");
	player.load(300, 300, 128, 82, "animate");

	return true;
}

void Game::render()
{
	SDL_RenderClear(pRenderer); // clear the renderer to the draw colour
	go.draw(pRenderer);
	player.draw(pRenderer);
	SDL_RenderPresent(pRenderer); // draw to the screen
}

void Game::update()
{
	go.update();
	player.update();
}

void Game::clean()
{
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(pWindow);
	SDL_DestroyRenderer(pRenderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	SDL_Event event;

	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			bRunning = false;
			break;

		default:
			break;
		}
	}
}
