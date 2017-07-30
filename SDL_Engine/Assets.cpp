#include "Assets.h"

#include "Game.h"
#include "Spritesheet.h"
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

Assets* Assets::manager{ nullptr };

Assets::Assets()
{
	Init();
	manager = this;
}

Assets::~Assets()
{
	for (auto pair : mTextures) {
		SDL_DestroyTexture(pair.second);
	}
	for (auto pair : mSounds) {
		Mix_FreeChunk(pair.second);
	}
	for (auto pair : mFonts) {
		TTF_CloseFont(pair.second);
	}
	for (Spritesheet* sheet : mSheets) {
		delete sheet;
	}
	Shutdown();
}

int Assets::Init()
{
	SDL_Init(SDL_INIT_AUDIO);
	Mix_Init(MIX_INIT_OGG);
	Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
	TTF_Init();
	return 0;
}

void Assets::Shutdown()
{
	IMG_Quit();
	TTF_Quit();
	Mix_CloseAudio();
	Mix_Quit();
}

SDL_Surface* Assets::loadSurface(std::string file)
{
	SDL_Surface* surface = IMG_Load(("../resources/images/" + file).c_str());
	if (!surface) {
		SDL_Log(("Unable to load surface from " + file).c_str());
	}
	return surface;
}

SDL_Texture* Assets::getTexture(std::string file)
{
	if (!mTextures[file]) {
		SDL_Texture* tex = IMG_LoadTexture(Game::inst->renderer, ("../resources/images/" + file).c_str());
		if (!tex) {
			SDL_Log(("Unable to load texture from " + file).c_str());
		}
		mTextures[file] = tex;
	}
	return mTextures[file];
}

Mix_Chunk* Assets::getSound(std::string file)
{
	if (!mSounds[file]) {
		Mix_Chunk* sound = Mix_LoadWAV(("../resources/audio/" + file).c_str());
		if (!sound) {
			SDL_Log(("Unable to load " + file).c_str());
		}
		mSounds[file] = sound;
	}
	return mSounds[file];
}

TTF_Font* Assets::getFont(std::string file, int size)
{
	std::string storedName = file + std::to_string(size);
	if (!mFonts[storedName]) {
		TTF_Font* font = TTF_OpenFont(("../resources/fonts/" + file).c_str(), size);
		if (!font) {
			SDL_Log(("Unable to load " + storedName + " font").c_str());
		}
		mFonts[storedName] = font;
	}
	return mFonts[storedName];
}
