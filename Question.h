#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "Button.h"
#include "utils.h"
#include "Question.h"
class Question
{
private:
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* texture = nullptr;
	TTF_Font* font = nullptr;
	SDL_Rect des;
	Button* button = nullptr;
	Button* button1 = nullptr;
	File* question = nullptr;
	std::string content;
public:
	Question(SDL_Renderer* renderer, TTF_Font* font, SDL_Point point, std::string content) {
		this->renderer = renderer;
		this->font = font;
		this->content = content;
		des.w = point.x;
		des.h = point.y;
	}
	void init();
	void handleEvent(SDL_Event e);
	void render();
};

