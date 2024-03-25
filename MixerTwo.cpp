#include "MixerTwo.h"
MixerTwo::MixerTwo() {

}

MixerTwo::~MixerTwo() {
	Mix_FreeChunk(chunk);
}

void MixerTwo::init() {
}

void MixerTwo::play() {
	Mix_PlayChannel(-1, chunk, -1);
}

void MixerTwo::Volume() {
	Mix_VolumeChunk(chunk, MIX_MAX_VOLUME / 10);
}

void MixerTwo::Ressume() {
	play();
}

bool MixerTwo::add(std::string path) {
	chunk = Mix_LoadWAV(path.c_str());
	if (chunk != nullptr) return true;
	return false;
}

void MixerTwo::stop() {
	Mix_HaltChannel(-1);
}