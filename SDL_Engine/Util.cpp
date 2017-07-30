#include "Util.h"

#include "Texture.h"
#include <iostream>

bool Util::IsOver(SDL_Point point, SDL_Rect rect)
{
	return point.x >= rect.x && point.x <= rect.x + rect.w
			&&
			point.y >= rect.y && point.y <= rect.y + rect.h;
}

bool Util::IsOver(SDL_MouseButtonEvent mouse, SDL_Point point, Texture* texture)
{
	return IsOver(SDL_Point{ mouse.x, mouse.y }, SDL_Rect{ point.x, point.y, texture->getWidth(), texture->getHeight() });
}

void Util::ReplaceColor(SDL_Surface* surface, SDL_Color find, SDL_Color replace)
{
	SDL_LockSurface(surface);
	Uint32 findColor = SDL_MapRGB(surface->format, find.r, find.g, find.b);
	Uint32 replaceColor = SDL_MapRGB(surface->format, replace.r, replace.g, replace.b);
	//for (int i = 0; i < surface->w * surface->h; i++) {
	//	if ((Uint32)surface->pixels[i] == find) {

	//	}
	//}
	SDL_UnlockSurface(surface);
}

void Util::Replace(std::string& text, std::string& find, std::string& replace)
{
	std::size_t pos{ 0 };
	while (true) {
		pos = text.find(find, pos);
		if (pos == std::string::npos) break;
		text.erase(pos, find.length());
		if (pos == std::string::npos) {
			pos = text.length() + 1;
		}
		text.insert(pos, replace);
	}
}
