#include "Exit.h"
#include "utils.h"
#include "Animated_button_motion.h"
void Exit::init() {
	font = TTF_OpenFont("Pixel _dep.ttf ",30);
	texture = Texture::loadImg("fg.jpg", renderer);
	button = new Button(renderer, font, { 1280 / 2  , 720 / 2 }, "CLOSE");
	button->init();
}
void Exit::render() {
	//SDL_RenderCopy(renderer, texture, nullptr, nullptr);
	button->render();
	renderText();
}
void Exit::renderText() {
	button->renderText();
}
//Khi bam thoat luon
void Exit::handleEvent(SDL_Event e) {
	if (button->handleEvents(e)) {
		global::gamestate = EXIT;
	}
}