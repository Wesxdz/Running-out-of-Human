#include "Spritesheet.h"

#include "Game.h"

Spritesheet::Spritesheet(SDL_Texture* texture, int columns, int rows) :
	mTexture	{ texture },
	mNumRows	{ rows },
	mNumColumns	{ columns }
{
	int width, height;
	SDL_QueryTexture(texture, NULL, NULL, &width, &height);
	mSpriteWidth = width / columns;
	mSpriteHeight = height / rows;
}

void Spritesheet::Render(int tile, int x, int y)
{
	int totalTiles = mNumRows * mNumColumns;
	if (tile >= totalTiles) tile = tile % totalTiles;
	int row = tile / mNumColumns;
	int column = tile - row * mNumColumns;
	SDL_Rect clip{ column * mSpriteWidth, row * mSpriteHeight, mSpriteWidth, mSpriteHeight };
	SDL_Rect dst{ x, y, mSpriteWidth, mSpriteHeight };
	SDL_RenderCopy(Game::inst->renderer, mTexture, &clip, &dst);
}

void Spritesheet::Render(int tile, int x, int y, int width, int height, double angle, SDL_Point* center) {
	int totalTiles = mNumRows * mNumColumns;
	if (tile >= totalTiles) tile = tile % totalTiles;
	int row = tile / mNumColumns;
	int column = tile - row * mNumColumns;
	SDL_Rect clip{ column * mSpriteWidth, row * mSpriteHeight, mSpriteWidth, mSpriteHeight };
	SDL_Rect dst{ x, y, width, height };
	SDL_RenderCopyEx(Game::inst->renderer, mTexture, &clip, &dst, angle, center, SDL_FLIP_NONE);
}
