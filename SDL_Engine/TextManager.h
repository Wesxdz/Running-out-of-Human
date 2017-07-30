#pragma once

class Texture;
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

class TextManager
{
public:
	TextManager();
	~TextManager();

public:
	TTF_Font* mFont;
	int mMaxWidth, mMaxHeight;
	SDL_Color mColor;

public:
	static Texture* GenText(const char* text, const char* fontName,
		int fontSize, SDL_Color color = SDL_Color{ 255, 255, 255, 255 },
		int borderSize = 0, SDL_Color borderColor = SDL_Color{ 0, 0, 0, 255 });
	static SDL_Surface* GenTextSurface(const char* text, const char* fontName,
		int fontSize, SDL_Color color = SDL_Color{ 255, 255, 255, 255 },
		int borderSize = 0, SDL_Color borderColor = SDL_Color{ 0, 0, 0, 255 });

};

