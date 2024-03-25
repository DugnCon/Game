#include "Mixer.h"

Mixer::Mixer() {

}

Mixer::~Mixer() {
	Mix_FreeChunk(sound);
}

void Mixer::init() {
}

void Mixer::play() {
	Mix_PlayChannel(-1, sound, -1);
}

bool Mixer::add(std::string path) {
	sound = Mix_LoadWAV(path.c_str());
	if (sound != nullptr) return true;
	return false;
}

void Mixer::ressume() {
	play();
}

void Mixer::delay(int milis) {
	SDL_Delay(0.001);
}

void Mixer::stop() {
	Mix_HaltChannel(-1);
}