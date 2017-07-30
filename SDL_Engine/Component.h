#pragma once

#include <SDL.h>

/*
A framework for organizing elements within a GameState
*/
class Component
{
public:
	Component();
	virtual ~Component();
	/*
	@return: Consume event
	This is useful for preventing an event from interacting through UI layers
	*/
	virtual bool Input(SDL_Event* event);
	/*
	@param dt: Number of milliseconds that have passed since the previous frame
	*/
	virtual void Update(int dt);
	virtual void Draw();
};

