#pragma once
#include <SDL.h>
#include "Button.h"
#include "utils.h"
class Exit
{
private:
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* texture = nullptr;
	Button* button = nullptr;
	TTF_Font* font = nullptr;
public:
	Exit(SDL_Renderer* renderer) {
		this->renderer = renderer;
	}
	void init();
	void handleEvent(SDL_Event e);
	void render();
	void renderText();
};


