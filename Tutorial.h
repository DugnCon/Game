#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "Button.h"
#include "utils.h"
#include "Animated_button_motion.h"
#include "tutorial_2.h"
class Tutorial
{
private:
	SDL_Renderer* renderer = nullptr;
	TTF_Font* font = nullptr;
	TTF_Font* font1 = nullptr;
	Button* button = nullptr;
	Button* button1 = nullptr;
	Button* button2 = nullptr;
	Button* button3 = nullptr;
	Button* button4 = nullptr;
	Button* button5 = nullptr;
	Animated_button_motion* animated = nullptr;
	SDL_Rect object;
	SDL_Rect* butt;
	SDL_Texture* texture = nullptr;
	SDL_Texture* text1 = nullptr;
	SDL_Texture * text2 = nullptr;
public:
	Tutorial(SDL_Renderer* renderer){
		this->renderer = renderer;
		this->font = font;
	}
	~Tutorial() {
	}
	void init();
	void handleEvent(SDL_Event e);
	void render();
	void renderText();
};

