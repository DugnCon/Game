#include "Tutorial.h"
#include "utils.h"
#include "Animated_button_motion.h"
void Tutorial::init() {
	font = TTF_OpenFont("Pixel _dep.ttf", 25);
	font1 = TTF_OpenFont("Pixel _dep.ttf", 20);
	texture = Texture::loadImg("Pixel_Dep_CC.jpg", renderer);
	std::string jsonData1, jsonData2, jsonData3, jsonData4, jsonData5;
	File::readFile4("tutorial.txt", jsonData1, jsonData2, jsonData3, jsonData4, jsonData5);
	button = new Button(renderer, font, { 1280 / 2 + 540 , 720 / 2 + 300 }, "BACK");
	button1 = new Button(renderer, font1, { 640 - SCREEN_WIDTH / 2 + 250, 0 }, jsonData1);
	button2 = new Button(renderer, font1, { 640 - SCREEN_WIDTH / 2 + 250, 100 }, jsonData2);
	button3 = new Button(renderer, font1, { 640 - SCREEN_WIDTH / 2 + 250 , 150 }, jsonData3);
	button4 = new Button(renderer, font1, { 640 - SCREEN_WIDTH / 2 + 250, 200 }, jsonData4);
	button5 = new Button(renderer, font1, { 640 - SCREEN_WIDTH / 2  + 500, 200 + 100}, jsonData5);
	button->init();
	button1->init();
	button2->init();
	button3->init();
	button4->init();
	button5->init();
}
//In ra man hinh
void Tutorial::render() {
	SDL_RenderCopy(renderer, texture, nullptr, nullptr);
	button->render();
	button1->render();
	button2->render();
	button3->render();
	button4->render();
	button5->render();
	//animated->render();
	renderText();
}

void Tutorial::renderText() {
	//button->renderText();
}
// Khi bam quay tro lai MENU
void Tutorial::handleEvent(SDL_Event e) {
	if (button->handleEvents(e)) {
		global::gamestate = MENU;
	}
}