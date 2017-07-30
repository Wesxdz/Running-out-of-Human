#include "Texture.h"

#include "Game.h"

Texture::Texture() {};

Texture::Texture(SDL_Texture* texture) :
	mTexture{ texture }
{
	SDL_assert(mTexture);
	SDL_QueryTexture(mTexture, NULL, NULL, &mWidth, &mHeight);
}

void Texture::Render(int x, int y) const
{
	SDL_Rect dst{ x, y, mWidth, mHeight };
	SDL_RenderCopy(Game::inst->renderer, mTexture, NULL, &dst);
}

void Texture::Render(SDL_Rect& clip, int x, int y) const
{
	SDL_Rect dst{ x, y, mWidth, mHeight };
	SDL_RenderCopy(Game::inst->renderer, mTexture, &clip, &dst);
}

void Texture::Render(int x, int y, float scale, double angle, SDL_Point * center) const
{
	SDL_Rect dst{ x, y, (int) (mWidth * scale), (int) (mHeight * scale) };
	SDL_RenderCopyEx(Game::inst->renderer, mTexture, NULL, &dst, angle, center, SDL_FLIP_NONE);
}

void Texture::setTexture(SDL_Texture* texture)
{
	SDL_assert(texture);
	mTexture = texture;
	SDL_QueryTexture(mTexture, NULL, NULL, &mWidth, &mHeight);
}
