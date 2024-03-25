#pragma once
#include <SDL_mixer.h>
#include <SDL.h>
#include <string>
#include <iostream>
class MixerTwo
{
private:
	Mix_Chunk* chunk = nullptr;
public:
	MixerTwo();
	~MixerTwo();
	void init();
	void play();
	void stop();
	void delay(int milis);
	bool add(std::string path);
	void Volume();
	void Ressume();
};

