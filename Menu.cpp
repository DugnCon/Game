#include "Menu.h"
#include "Button.h"
#include "Animated_button_motion.h"
void Menu::init() {
	font = TTF_OpenFont("Pixel _dep.ttf", 30);
	texture = Texture::loadImg("829055.png", renderer);
	//Trong cai anh thi tao cac nut PLAY MENU CLOSE TUTORIAL
	button = new Button(renderer, font, { 1280 - 300,720 - 100  }, "CLOSE");
	tuto = new Button(renderer, font, { 1280 / 2 - 50 - 20 + 150 - 30 , 720 - 100 }, "TUTORIAL");
	pla = new Button(renderer, font, { 1280 / 2 - 320 + 180 - 50 , 720 - 100 }, "PLAY");
	ex = new Button(renderer, font, { 1280 / 2 - 400 - 50, 720 - 100 }, "MENU");
    //sou = new Button(renderer, font, { 1280 / 2 , 720 / 2 }, "SOUND");
	button->init();
	tuto->init();
	pla->init();
	ex->init();
	//sou->init();
}

void Menu::render() {
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	button->render();
	tuto->render();
	pla->render();
	ex->render();
	//renderText();
	//sou->render();
}

void Menu::renderText() {
	ex->renderText();
}
//Khi thuc hien.....
void Menu::handleEvents(SDL_Event e) {
	if (button->handleEvents(e)) {
		global::gamestate = EXIT;
	}
	if (tuto->handleEvents(e)) {
		global::gamestate = TUTORIAL;
	}
	if (pla->handleEvents(e)) {
		global::gamestate = PLAY;
	}
	if (ex->handleEvents(e)) {
		global::gamestate = SOUND;
	}
	//if (sou->handleEvents(e)) {
		//global::gamestate = MENU;
	//}
}
