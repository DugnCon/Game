#include "Button.h"
#include "utils.h"
void Button::init() {
	surface = TTF_RenderText_Solid_Wrapped(font, content.c_str(), textColor, 1000);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	SDL_QueryTexture(texture, NULL, NULL, &des.w, &des.h);
	chuck = new MixerTwo;
	chuck->add("sos.wav");
	chuckTwo = new MixerTwo();
	chuckTwo->add("8_bit.wav");
}

void Button::PlayChuck() {
	chuck->play();
}

void Button::PlayChuckTwo() {
	chuckTwo->play();
}

void Button::Volume() {
	chuck->Volume();
}

void Button::Stop() {
	chuck->stop();
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
			PlayChuck();
			Volume();
			SDL_Delay(500);
			//chuckTwo->Ressume();
			std::cout << "Mouse button" << std::endl;
		    return 1;
		}
	}
    else if (e.type == SDL_MOUSEBUTTONUP) {
		chuck->stop();
		chuckTwo->Ressume();
		if (global::gamestate == MENU) {
			chuckTwo->stop();
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
