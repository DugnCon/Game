#include "Next.h"
void Next::init() {
	font = TTF_OpenFont("Pixel _dep.ttf", 24);
	font1 = TTF_OpenFont("Pixel _dep.ttf", 23);
	std::string jsondata;

	File::readFile3("hello_world.txt", [&](const std::string& jsonDataReal) {
		jsondata = jsonDataReal;
	});

	button1 = new Button(renderer, font, { SCREEN_WIDTH / 2 - 50 - 20 - 20 , SCREEN_HEIGHT / 2 - 30 }, jsondata);
	button2 = new Button(renderer, font1, { 1280 / 2 + 480, 720 / 2 + 300 }, "CONTINUE");

	button1->init();
	button2->init();
}

void Next::render() {
	//SDL_RenderCopy(renderer, texture, nullptr, nullptr);
	button1->render();
	//button2->render();
	renderText();
}
void Next::renderText() {
	//button1->renderText();
	//button2->renderText();
}
void Next::handleEvent(SDL_Event e) {
	static Uint32 lastTime = SDL_GetTicks(); //Luu thoi diem cuoi cung
	Uint32 currentTime = SDL_GetTicks(); //Thoi diem ma bat dau
	//Neu de thao tac bang Nut
	if (button2->handleEvents(e)) {
		global::gamestate = PLAY;
		lastTime = currentTime; //Update thoi diem
	}

	//Neu khong thao tac bang nut
	if (currentTime - lastTime >= 1500) {
		global::gamestate = PLAY; //Tu dong chuyen trang thai
		lastTime = currentTime; //Update
	}
}