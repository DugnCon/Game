#include "utils.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
SDL_Texture* Texture::loadImg(std::string path, SDL_Renderer* renderer) {
	SDL_Surface* surface = IMG_Load(path.c_str());
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	return texture;
}
SDL_Texture* Texture::loadTexture(const std::string filename, SDL_Renderer* renderer) {
	SDL_Surface* tempSurface = IMG_Load(filename.c_str());
	SDL_Texture* tempTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
	//SDL_SetTextureBlendMode(tempTexture, SDL_BLENDMODE_NONE);
	SDL_FreeSurface(tempSurface);
	return tempTexture;
}
 //Load mau 
SDL_Texture* Texture::loadText(SDL_Renderer* renderer, TTF_Font* font, std::string text, SDL_Color color){
	SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	return texture;
}

void Textmanage::loadTextRect(SDL_Texture* texture, SDL_Rect& textRect, SDL_Rect button) {
	int w, h;
	SDL_QueryTexture(texture, NULL, NULL, &w, &h);
	textRect.x = button.x + button.w / 2 - w / 2;
	textRect.y = button.y + button.h / 2 - h / 2;
	textRect.w = w;
	textRect.h = h;
}
void Textmanage::FillRect(SDL_Renderer* renderer, SDL_Color Color, SDL_Rect object) {
	SDL_SetRenderDrawColor(renderer, Color.r, Color.g, Color.b, Color.a);
	SDL_RenderFillRect(renderer, &object);
}
void Textmanage::DrawRect(SDL_Renderer* renderer, SDL_Color Color, SDL_Rect object) {
	SDL_SetRenderDrawColor(renderer, Color.r, Color.g, Color.b, Color.a);
	SDL_RenderDrawRect(renderer, &object);
}
void Textmanage::Draw1(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect src, SDL_Rect dest) {
	SDL_RenderCopy(renderer, texture, &src, &dest);

}
void Textmanage::Draw2(SDL_Renderer* renderer, SDL_Texture* texture, SDL_Rect src, SDL_Rect dest, SDL_RendererFlip flip) {
	SDL_RenderCopyEx(renderer, texture, &src, &dest, NULL , NULL, flip);
}
void File::readFile(std::string path, std::string& jsonData1, std::string& jsonData2 , std::string& jsonData3 , std::string& jsonData4) {
	std::ifstream in(path);
	if (!in.is_open()) {
		std::cout << "Cannot open file \n";
	}
	else {
		std::getline(in, jsonData1);
		std::getline(in, jsonData2);
		std::getline(in, jsonData3);
		std::getline(in, jsonData4);
		//in.close();
	}
	in.close();
}
void File::readFile2(std::string path, std::function<void(const std::string&)> Data) {
	std::ifstream in(path);
	if (!in.is_open()) {
		std::cout << "Cannot open file \n";
	}
	else {
		std::string jsonData;
		std::vector<std::string> lines;
		while (std::getline(in, jsonData)) {
			lines.push_back(jsonData);
		}
		in.close();
		//std::random_device rd;
		//std::mt19937 gen(rd());
		//std::shuffle(lines.begin(), lines.end(), gen);
		for (const std::string& line : lines) {
			Data(line);
		}
	}
}

void File::readFile3(std::string path, std::function<void(const std::string&)> Data) {
	std::ifstream in(path);
	if (!in.is_open()) {
		std::cout << "Cannot open file \n";
	}
	else {
		std::vector<std::string> lines;
		std::string jsonData;

		while (std::getline(in, jsonData)) {
			lines.push_back(jsonData);
		}
		in.close();
		std::random_device rd;
		std::mt19937 gen(rd());
		std::shuffle(lines.begin(), lines.end() , gen);
		for (const std::string& json : lines) {
			Data(json);
		}
	}
	//in.close();
}
void File::readFile4(std::string path, std::function<void(const std::string&, const std::string&, const std::string&, const std::string&)> Data) {
	std::ifstream in(path);
	if (!in.is_open()) {
		std::cout << "Cannot open file \n";
	}
	else {
		std::string ans1, ans2, ans3, ans4;
		while (std::getline(in, ans1)) {
			std::getline(in, ans2);
			std::getline(in, ans3);
			std::getline(in, ans4);
			Data(ans1, ans2, ans3, ans4);
		}
		in.close();
	}
}
void File::readFile5(std::string path, std::string& jsonData1, std::string& jsonData2, std::string& jsonData3, std::string& jsonData4 , std::string& jsonData5) {
	std::ifstream in(path);
	if (!in.is_open()) {
		std::cout << "Cannot open file \n";
	}
	else {
		std::getline(in, jsonData1);
		std::getline(in, jsonData2);
		std::getline(in, jsonData3);
		std::getline(in, jsonData4);
		std::getline(in, jsonData5);
		//in.close();
	}
	in.close();
}

GameState global::gamestate = MENU;
