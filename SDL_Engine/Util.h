#pragma once

class Texture;
#include <SDL.h>
#include <string>

namespace Util {
	/*
	@return: Is #point overlapping #rect
	*/
	bool IsOver(SDL_Point point, SDL_Rect rect);
	bool IsOver(SDL_MouseButtonEvent mouse, SDL_Point point, Texture* texture);
	void ReplaceColor(SDL_Surface* find, SDL_Color target, SDL_Color replace);
	void Replace(std::string& text, std::string& find, std::string& replace);
}