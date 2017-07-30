#pragma once

#include "Renderable.h"
#include <SDL.h>

/*
A wrapper class for simplified use of SDL_Texture
Does not free mTexture when deleted
*/
class Texture : public Renderable
{
public:
	Texture();
	Texture(SDL_Texture* texture);

	void Render(int x, int y) const;
	void Render(SDL_Rect& clip, int x, int y) const;
	virtual void Render(int x, int y, float scale, double angle = 0, SDL_Point* center = nullptr) const;

	inline int getWidth() { return mWidth; }
	inline int getHeight() { return mHeight; }
	inline SDL_Texture* getTexture() { return mTexture; }
	void setTexture(SDL_Texture* texture);

public:
	SDL_Texture* mTexture{ nullptr };
	int mWidth{ 0 };
	int mHeight{ 0 };
};

