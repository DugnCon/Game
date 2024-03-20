#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <iostream>
class Button
{
private:
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* texture = nullptr;
	//SDL_Texture* texture1 = nullptr; //Dung de chua be noi chu va mau cho texture
	SDL_Color textColor = { 255,255,255,255 };
	TTF_Font* font = nullptr;
	//SDL_Color holerColor = { 255,0,0,0 };
	std::string content;
	SDL_Rect des;
	SDL_Color Color = { 255,255,255,255 };//white
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
};

