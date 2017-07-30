#pragma once

class Texture;
#include "Renderable.h"
#include <list>

/*
A Skeleton represents a collection of SDL_Surfaces positioned relative to each other to form a single Texture
*/
class Skeleton : public Renderable
{
public:
	Skeleton();
	~Skeleton();

	virtual void Render(int x, int y);
	virtual void Render(int x, int y, float scale, double angle, SDL_Point* center);

private:
	std::list<SDL_Surface*> mParts;
	Texture* mBody;
};

