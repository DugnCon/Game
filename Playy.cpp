#include "Playy.h"
#include "utils.h"
#include "Animated_button_motion.h"
//Tao cai nut BACK khi nhap vao
void Playy::init() {
	font = TTF_OpenFont("Pixel _dep.ttf", 25);
	texture = Texture::loadImg("2789549.jpg", renderer);
	std::string jsonData1, jsonData2, jsonData3, jsonData4;
	std::string jsondata1, jsondata2;
	File::readFile2("quest_anses.txt",jsondata1, jsondata2);
	File::readFile("eng_anses.txt", jsonData1, jsonData2, jsonData3, jsonData4);
	question = new Question(renderer, font, { SCREEN_WIDTH / 2  , SCREEN_HEIGHT / 2 - 50 }, jsondata1);
	question1 = new Question(renderer, font, { SCREEN_WIDTH / 2  , SCREEN_HEIGHT / 2 - 50 }, jsondata2);
	answer = new Button(renderer, font,  { 640 - SCREEN_WIDTH / 2 + 250, 100 + 200 }, jsonData1);
	answer1 = new Button(renderer, font, { 640 - SCREEN_WIDTH / 2 + 400 + 400, 100 + 200 }, jsonData2);
	answer2 = new Button(renderer, font, { 640 - SCREEN_WIDTH / 2 + 250 , 100 + 200 + 300 - 200 }, jsonData3);
	answer3 = new Button(renderer, font, { 640 - SCREEN_WIDTH / 2 + 400 + 400, 100 + 200 + 300 - 200 }, jsonData4);
	//answer = new Button(renderer, font, { SCREEN_WIDTH / 2 + 300 , SCREEN_HEIGHT / 2 + 300 }, jsonData1);
	//answer1 = new Button(renderer, font, { SCREEN_WIDTH / 2 + 300 , SCREEN_HEIGHT / 2 + 300 }, jsonData2);
	//answer2 = new Button(renderer, font, { SCREEN_WIDTH / 2 + 300 , SCREEN_HEIGHT / 2 + 300 }, jsonData3);
	//answer3 = new Button(renderer, font, { SCREEN_WIDTH / 2 + 300 , SCREEN_HEIGHT / 2 + 300 }, jsonData4);
	button = new Button(renderer, font, { 1280 / 2 + 540 , 720 / 2 + 300 }, "BACK");
	question->init();
	answer->init();
	answer1->init();
	answer2->init();
	answer3->init();
	button->init();
}
void Playy::render() {
	SDL_RenderCopy(renderer , texture , nullptr , nullptr );
	button->render();
	question-> render();
	answer->render();
	answer1->render();
	answer2->render();
	answer3->render();
	renderText();
}
void Playy::renderText() {
	button->renderText();
}
//Khi bam quay tro lai MENU
void Playy::handleEvent(SDL_Event e) {
	if (button->handleEvents(e) ) {
		global::gamestate = MENU;
	}
	if (answer->handleEvents(e) || answer1->handleEvents(e) || answer2->handleEvents(e) || answer3->handleEvents(e)) {
		global::gamestate = CONTINUE;
	}
}