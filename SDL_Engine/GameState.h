#pragma once

#include <SDL.h>

/**
Abstract interface, implement the following methods:
void Input(SDL_Event* event)
void Update(int dt)
void Draw()
*/
class GameState
{
public:
	virtual ~GameState();
	virtual void Input(SDL_Event* event) = 0;
	/*
	@param dt: Number of milliseconds that have passed since the previous frame
	*/
	virtual void Update(int dt) = 0;
	virtual void Draw() = 0;
	/*
	Exits Game loop if Esc is pressed or the window is closed
	@return: Loop ending
	*/
	virtual bool ExitInput(SDL_Event* event);
};

