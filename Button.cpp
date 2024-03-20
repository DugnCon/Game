#include "Button.h"
#include "utils.h"
void Button::init() {
	SDL_Surface* surface = TTF_RenderText_Solid(font, content.c_str(), textColor);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	SDL_QueryTexture(texture, NULL, NULL, &des.w, &des.h);
}

void Button::render() {
	SDL_RenderCopy(renderer, texture, NULL, &des);
}

// ve o vuong va them mau
void Button::renderText() {
	//SDL_SetRenderDrawColor(renderer, 255, 255, 255, 100);
	//SDL_RenderFillRect(renderer, &des);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderDrawRect(renderer, &des);
}

bool Button::handleEvents(SDL_Event e) {
	if (e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT) {
		SDL_Point currMousePosition = { e.button.x, e.button.y };
		if (SDL_PointInRect(&currMousePosition, &des) == true) {
			std::cout << "Mouse button" << std::endl;
		
			return 1;
		}
	}
	if (e.type == SDL_MOUSEMOTION) {
		SDL_Point cuurMousePosition = { e.motion.x, e.motion.y };
		if (SDL_PointInRect(&cuurMousePosition, &des)) {
			Color = { 255, 255, 255 ,255 };
			texture = Texture::loadText(renderer, font, content, { 255,0,0,0 });
		}
		else {
			Color = { 255,0,0,0 };
			texture = Texture::loadText(renderer, font, content, { 255,255,255,255 });
			
		}
	}
	return 0;
}