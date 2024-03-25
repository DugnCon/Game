#pragma once
#include <SDL_mixer.h>
#include <iostream>
#include <vector>
#include <SDL.h>
class Mixer
{
private:
	Mix_Chunk* sound = nullptr;
public:
	Mixer();
	~Mixer();
	void init();
	void play();
	void stop();
	void delay(int milis);
	bool add(std::string path);
	void ressume();
};