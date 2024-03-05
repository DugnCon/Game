#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
using namespace std;
#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 900
class Game{
private:
	SDL_Window* gWindow = NULL;
	SDL_Surface* gScreenSurface = NULL;
	SDL_Surface* gHelloWorld = NULL;
public:
	bool init() {
		SDL_Window* gWindow = NULL;
		SDL_Surface* gScreenSurface = NULL;
		SDL_Surface* gHelloWorld = NULL;
		bool success = true;
		//Khoi tao SDL
		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			cout << ("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
			success = false;

		}
		else {
			// Tao cua so
			gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
			if (gWindow == NULL)
			{
				cout << ("Window could not be created! SDL_Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Lay be mat cua so
				gScreenSurface = SDL_GetWindowSurface(gWindow);
			}
		}

		return success;
	}
	bool loadMedia() {
		//Dang tai
		bool success = true;

		//Tai hinh anh giat gan
		gHelloWorld = SDL_LoadBMP("02_getting_an_image_on_the_screen/hello_world.bmp");
		if (gHelloWorld == NULL)
		{
			printf("Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError());
			success = false;
		}

		return success;
	}
	void close() {
		//Phan bo be mat
		SDL_FreeSurface(gHelloWorld);
		gHelloWorld = NULL;
		//Pha huy cua so
		SDL_DestroyWindow(gWindow);
		gWindow = NULL;
		//Thoat SDL
		SDL_Quit();
	}
};

