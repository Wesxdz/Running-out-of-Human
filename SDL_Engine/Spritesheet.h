#pragma once

#include <SDL.h>

/*
Render and represent uniform-size tiles from an SDL_Texture
*/
class Spritesheet
{
public:
	Spritesheet(SDL_Texture* texture, int columns, int rows = 1);
	void Render(int tile, int x, int y);
	void Render(int tile, int x, int y, int width, int height, double angle = 0, SDL_Point* center = nullptr);

	inline SDL_Texture* getTexture() { return mTexture; }
	inline int getNumRows() { return mNumRows; }
	inline int getNumColumns() { return mNumColumns; }
	inline int getNumSprites() { return mNumRows * mNumColumns; }
	inline int getSpriteWidth() { return mSpriteWidth; }
	inline int getSpriteHeight() { return mSpriteHeight; }

private:
	SDL_Texture* mTexture;
	int mNumRows;
	int mNumColumns;
	int mSpriteWidth;
	int mSpriteHeight;
};

