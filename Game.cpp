#include "Game.h"
void Game::init() {
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();
	window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	renderer = SDL_CreateRenderer(window, -1, 0);

	interface = new Interface(renderer);
	interface->init();
}

void Game::render() {
	SDL_RenderClear(renderer);
	interface->render();
	SDL_RenderPresent(renderer);
}

void Game::handleEvent() {
	SDL_PollEvent(&event);

	if (event.type == SDL_QUIT) global::gamestate = EXIT;

	interface->handleEvents(event);
}

void Game::run() {
	init();
	gameLoop();
}

void Game::gameLoop() {
	while (global::gamestate != EXIT) {
		handleEvent();
		render();
	}
}