#include "TextManager.h"

#include "Assets.h"
#include "Game.h"
#include "Texture.h"
#include <SDL_ttf.h>
#include <vector>

using namespace std;

TextManager::TextManager()
{
}

TextManager::~TextManager()
{
}

Texture* TextManager::GenText(const char* text, const char* fontName, int fontSize, SDL_Color color,
	int borderSize, SDL_Color borderColor)
{
	SDL_Surface* textPixels = GenTextSurface(text, fontName, fontSize, color, borderSize, borderColor);
	SDL_Texture* textDisplay = SDL_CreateTextureFromSurface(Game::inst->renderer, textPixels);
	SDL_FreeSurface(textPixels);
	return new Texture{ textDisplay };
}

SDL_Surface* TextManager::GenTextSurface(const char* text, const char* fontName, int fontSize, SDL_Color color,
	int borderSize, SDL_Color borderColor)
{
	TTF_Font* font = Assets::manager->getFont(fontName, fontSize);
	SDL_Surface* textPixels = TTF_RenderText_Solid(font, text, color);
	if (borderSize > 0) {
		TTF_SetFontOutline(font, borderSize);
		SDL_Surface* borderPixels = TTF_RenderText_Solid(font, text, borderColor);
		TTF_SetFontOutline(font, 0);
		// TODO: Ability to add shadow or border
		SDL_Rect dst{ borderSize, borderSize, textPixels->w, textPixels->h };
		SDL_BlitSurface(textPixels, NULL, borderPixels, &dst);
		SDL_FreeSurface(textPixels);
		return borderPixels;
	}
	return textPixels;
}