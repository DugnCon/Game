#include "Question.h"
void Question::init() {
    font = TTF_OpenFont("Pixel _dep.ttf", 22);
    std::string jsonData1, jsonData2;
    File::readFile2("quest_anses.txt", jsonData1, jsonData2); 
    button = new Button(renderer, font, { 640 - SCREEN_WIDTH / 2 + 250 - 50, 100}, jsonData1);
    button1 = new Button(renderer, font ,{ 640 - SCREEN_WIDTH / 2 + 250 - 50, 100 + 50 }, jsonData2);
    button->init();
    button1->init();
}

void Question::render(){
	SDL_RenderCopy(renderer, texture, nullptr, nullptr);
	button->render();
    button1->render();
}
void Question::handleEvent(SDL_Event e) {
    //if (button->handleEvents(e)) {
        //global::gamestate = MENU;
    //}
}