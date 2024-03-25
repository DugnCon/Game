#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <iostream>
#include "Mixer.h"
#include "MixerTwo.h"
class Button
{
private:
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* texture = nullptr;
	SDL_Color textColor = { 255,255,255,255 };
	TTF_Font* font = nullptr;
	//SDL_Color holerColor = { 255,0,0,0 };
	std::string content;
	SDL_Surface* surface = nullptr;
	SDL_Rect des;
	SDL_Color Color = { 255,255,255,255 };//white
	MixerTwo* chuck = nullptr;
	MixerTwo* chuckTwo = nullptr;
	Mixer* music = nullptr;
	bool isPressed = true;
public:
	Button(SDL_Renderer* renderer, TTF_Font* font, SDL_Point point, std::string content) {
		this->renderer = renderer;
		this->font = font;
		this->content = content;
		des.x = point.x;
		des.y = point.y;
	}
	void init();
	void render();
	void renderText();
	bool handleEvents(SDL_Event e);
	//bool handleEventsMusic(SDL_Event e);
	void Chuck();
	void PlayChuck();
	void PlayChuckTwo();
	void Stop();
	void Volume();
};

