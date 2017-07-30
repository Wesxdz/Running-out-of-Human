#pragma once

class Spritesheet;
struct SDL_Point;
#include "Renderable.h"

struct Clip : public Renderable
{
	Clip() {};
	Clip(Spritesheet* sheet, int tile);
	Spritesheet* mSheet{ nullptr };
	int mTile{ 0 };
	virtual void Render(int x, int y) const;
	virtual void Render(int x, int y, float scale, double angle = 0, SDL_Point* center = nullptr) const;
};
