#include "tutorial_2.h"
void tutorial_2::init() {
	font = TTF_OpenFont("Pixel _dep.ttf", 24);
	std::string jsondata, jsondata2, jsondata3, jsondata4;
	File::readFile("hello_world.txt", jsondata , jsondata2, jsondata3, jsondata4);
	button1 = new Button(renderer, font, { SCREEN_WIDTH / 2 - 50 - 20 - 20 , SCREEN_HEIGHT / 2 - 30 }, jsondata);
	button2 = new Button(renderer, font, { SCREEN_WIDTH / 2 - 50 - 20 - 20 , SCREEN_HEIGHT / 2 - 30 }, jsondata2);
	button3 = new Button(renderer, font, { SCREEN_WIDTH / 2 - 50 - 20 - 20 , SCREEN_HEIGHT / 2 - 30 }, jsondata3);
	button4 = new Button(renderer, font, { SCREEN_WIDTH / 2 - 50 - 20 - 20 , SCREEN_HEIGHT / 2 - 30 }, jsondata4);
	button1->init();
	button2->init();
	button3->init();
	button4->init();
}
void tutorial_2::render() {
	//SDL_RenderCopy(renderer, texture, nullptr, nullptr);
	button1->render();
	button2->render();
	button3->render();
	button4->render();
	renderText();
}
void tutorial_2::renderText() {
	//button1->renderText();
	//button2->renderText();
}
void tutorial_2::handleEvent(SDL_Event e) {
	//if (button2->handleEvents(e)) {
		//global::gamestate = PLAY;
	//}
}