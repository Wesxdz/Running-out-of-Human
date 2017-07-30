#pragma once

#include <SDL.h>

/*
An abstract class for Rendering SDL_Textures
Implement
virtual void Render(int x, int y) const
virtual void Render(int x, int y, float scale, double angle, SDL_Point* center) const
*/
class Renderable
{
public:
	virtual ~Renderable();

	inline void Render(SDL_Point point) { Render(point.x, point.y); }

	virtual void Render(int x, int y) const = 0;

	virtual void Render(int x, int y,
		float scale, double angle = 0,
		SDL_Point* center = nullptr) const;
};

