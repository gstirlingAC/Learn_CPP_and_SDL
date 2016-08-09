#ifndef __TextureManager__
#define __TextureManager__

#include <iostream>
#include <map>
#include <SDL2\SDL.h>
#include <SDL2\SDL_image.h>

class TextureManager
{
public:
	TextureManager() {};
	~TextureManager() {};

	bool load(std::string fileName, std::string id, SDL_Renderer* pRenderer);

	// draw - we would use this if we only wanted to draw a single frame
	void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

	// drawframe - we would use this if we wanted to draw multiple frames (for animation)
	void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	std::map<std::string, SDL_Texture*> textureMap;
};

#endif // !__TextureManager__

