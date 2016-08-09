#ifndef __Game__
#define __Game__

#include "TextureManager.h"

class Game
{
public:

	Game() {} // constructor
	~Game() {} // deconstructor

	// simply set the running variable to true
	bool init(const char* title, int xpos, int ypos, int width, int height, bool fullScreen);

	void render();
	void update();
	void handleEvents();
	void clean();

	bool running() { return bRunning; }

private:

	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;

	int currentFrame;
	TextureManager textureManager;

	bool bRunning;
};

#endif /* defined(__Game__) */
