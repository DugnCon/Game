#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "constant.h"
#include <SDL_ttf.h>
#include <nlohmann/json.hpp>
#include <fstream>
#include <random>
#include <vector>
#include <algorithm>
class Textmanage {
private:
public:
	Textmanage();
	~Textmanage();
	//static SDL_Texture* loadTexture(const std::string filename, SDL_Renderer * renderer);
	//static SDL_Texture* loadText(SDL_Renderer renderer, TTF_Font* font, std::string text, SDL_Color color = { 0,0,0,255 });
	static void loadTextRect(SDL_Texture* texture, SDL_Rect& textRect, SDL_Rect button);
	static void Draw1(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect src, SDL_Rect dest);
	static void Draw2(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect src, SDL_Rect dest, SDL_RendererFlip flip);
	static void DrawRect(SDL_Renderer* renderer, SDL_Color color, SDL_Rect object);
	static void FillRect(SDL_Renderer* renderer, SDL_Color color, SDL_Rect object);
};

namespace Texture {
	SDL_Texture* loadImg(std::string path, SDL_Renderer* renderer);
	SDL_Texture* loadTexture(const std::string filename, SDL_Renderer* renderer);
	SDL_Texture* loadText(SDL_Renderer* renderer, TTF_Font* font, std::string text, SDL_Color color = { 0,0,0,255});
}
class File {
private:


public:
	File();
	~File();
	static std::string Path(std::string path);
	static void readFile(std::string path , std::string& data , std::string& data1, std::string& data2, std::string& data3 );
	static void readFile2(std::string path, std::string& data , std::string& data1);
	static void readFile3(std::string path, std::function<void(const std::string&)> Data);
	static void readFile4(std::string path, std::string& data, std::string& data1, std::string& data2, std::string& data3, std::string& data4 );
	//static void readFile(std::string path, std::string& datat);
	//static void writeFile(std::string path, nlohmann::json& jsondata);
};
namespace global {
	extern GameState gamestate;
}

namespace Font {
	TTF_Font* loadFont(std::string font, int size);
}