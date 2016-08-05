#ifndef __Game__
#define __Game__

#include<SDL2\SDL.h>

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

	bool running() { return m_bRunning; }

private:

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	SDL_Texture* m_pTexture; // the new SDL_Texture variable
	SDL_Rect m_sourceRectangle; // the first rectangle
	SDL_Rect m_destinationRectangle; // the second rectangle

	bool m_bRunning;
};

#endif /* defined(__Game__) */
