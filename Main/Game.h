#ifndef __Game__
#define __Game__

#include<vector>
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"

class Game
{
public:
	static Game* Instance()
	{
		if (pInstance == 0)
		{
			pInstance = new Game();
			return pInstance;
		}

		return pInstance;
	}

	SDL_Renderer* getRenderer() const { return pRenderer; }

	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen);

	void render();
	void update();
	void handleEvents();
	void clean();

	bool running() { return bRunning; }

private:
	Game() {} // constructor

	static Game* pInstance;

	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;

	std::vector<SDLGameObject*> gameObjects;

	int currentFrame;

	bool bRunning;
};

typedef Game TheGame;

#endif /* defined(__Game__) */
