#include "Answer.h"
void Answer::init() {
    font = TTF_OpenFont("Pixel _dep.ttf", 24);
    std::string jsonData, jsonData2, jsonData3, jsonData4;
    File::readFile("eng_anses.txt", jsonData, jsonData2 , jsonData3 , jsonData4);
   //File::readFile("eng_ansss.txt", json);
    button = new Button(renderer, font, { 640 - SCREEN_WIDTH / 2 + 250, 100 + 200 }, jsonData);
    button2 = new Button(renderer, font, { 640 - SCREEN_WIDTH / 2 + 400 + 400, 100 + 200}, jsonData2);
    button3 = new Button(renderer, font, { 640 - SCREEN_WIDTH / 2 + 250 , 100 + 200 + 300 - 200}, jsonData3);
    button4 = new Button(renderer, font, { 640 - SCREEN_WIDTH / 2  + 400 + 400, 100 + 200 + 300 - 200 }, jsonData4);
    button->init();
    button2->init();
    button3->init();
    button4->init();
}

void Answer::render() {
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);
    button->render();
    button2->render();
    button3->render();
    button4->render();
    renderText();
}
void Answer::renderText() {
    //button->renderText();
    //button2->renderText();
   //button3->renderText();
    //button4->renderText();
}
void Answer::handleEvent(SDL_Event e) {
    if (button->handleEvents(e) || button2->handleEvents(e) || button3->handleEvents(e) || button4->handleEvents(e))  {
        global::gamestate = PLAY;
    }
}