#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "utils.h"
#include "Button.h"
#include "Tutorial.h"
#include "Playy.h"
#include "Exit.h"
#include "menu.h"
#include "Sound.h"
#include "Menu.h"
class Menu
{
private:
	SDL_Renderer* renderer = nullptr;
	TTF_Font* font = nullptr;
	SDL_Texture* texture = nullptr;
	Button* button = nullptr;
	Button* tuto = nullptr;
	Button* pla = nullptr;
	Button* ex = nullptr;
	//Button* sou = nullptr;
public:
	Menu(SDL_Renderer* renderer) {
		this->renderer = renderer;
	}
	void init();
	void handleEvents(SDL_Event e);
	void render();
	void renderText();
};

