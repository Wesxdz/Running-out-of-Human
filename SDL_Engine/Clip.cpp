#include "Clip.h"

#include "Game.h"
#include "Spritesheet.h"

Clip::Clip(Spritesheet* sheet, int tile) :
	mSheet{ sheet },
	mTile{ tile }
{
}

void Clip::Render(int x, int y) const
{
	mSheet->Render(mTile, x, y);
}

void Clip::Render(int x, int y, float scale, double angle, SDL_Point* center) const
{
	mSheet->Render(mTile, x, y,
		(int)(mSheet->getSpriteWidth() * scale), (int)(mSheet->getSpriteHeight() * scale),
		angle, center);
}