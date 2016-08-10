#ifndef __Game__
#define __Game__

#include<vector>
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"

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

	GameObject* go;
	GameObject* player;
	GameObject* enemy;

	std::vector<GameObject*> gameObjects;

	int currentFrame;

	bool bRunning;
};

#endif /* defined(__Game__) */
