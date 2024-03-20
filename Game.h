#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "Interface.h"
#include "constant.h"
class Game
{
private:
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
	Interface* interface = nullptr;
	SDL_Event event;
public:
	void run();
	void gameLoop();
	void init();
	void handleEvent();
	void render();
};

