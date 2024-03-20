#pragma once
#include "utils.h"
#include "Button.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include "Animated_button_motion.h"
#include "Question.h"
#include "Answer.h"
#include "Next.h"
class Playy
{
private:
	SDL_Renderer* renderer = nullptr;
	TTF_Font* font = nullptr;
	SDL_Texture* texture = nullptr;
	Button* button = nullptr;
	//Button* button1 = nullptr;
	//Button* button2 = nullptr;
	nlohmann::json jsondata;
	Question* question = nullptr;
	Question* question1 = nullptr;
	Button* answer = nullptr;
	Button* answer1 = nullptr;
	Button* answer2 = nullptr;
	Button* answer3 = nullptr;
public:
	Playy(SDL_Renderer* renderer) {
		this->renderer = renderer;
		this->font = font;
	}
	void init();
    void handleEvent(SDL_Event e);
	void render();
	void renderText();
};

