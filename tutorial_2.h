#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "Button.h"
#include "utils.h"
class tutorial_2
{
private:
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* texture = nullptr;
	Button* button1 = nullptr;
	Button* button2 = nullptr;
	Button* button3 = nullptr;
	Button* button4 = nullptr;
	TTF_Font* font = nullptr;
	TTF_Font* font1 = nullptr;
	SDL_Rect des;
	std::string content;
public:
	tutorial_2(SDL_Renderer* renderer) {
		this->renderer = renderer;
		this->font = font;
		this->font = font1;
		//this->content = content;
		//des.w = point.x;
		//des.h = point.y;
	}
	void init();
	void render();
	void handleEvent(SDL_Event e);
	void renderText();

};

