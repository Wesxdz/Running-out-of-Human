#include "Skeleton.h"
#include "Texture.h"

Skeleton::Skeleton()
{
}


Skeleton::~Skeleton()
{
}

void Skeleton::Render(int x, int y)
{
	mBody->Render(x, y);
}

void Skeleton::Render(int x, int y, float scale, double angle, SDL_Point* center)
{
	mBody->Render(x, y, scale, angle, center);
}
