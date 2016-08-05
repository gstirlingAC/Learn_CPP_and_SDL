#ifndef __Game__
#define __Game__

#include<SDL2\SDL.h>

class Game
{
public:

	Game() {} // constructor
	~Game() {} // deconstructor

	// simply set the running variable to true
	void init() { m_bRunning = true; }

	void render() {}
	void update() {}
	void handleEvents() {}
	void clean() {}

private:

	bool m_bRunning;
};

#endif /* defined(__Game__) */
