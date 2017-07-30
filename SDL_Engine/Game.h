#pragma once

#include "GameState.h"
#include <SDL.h>
#include <SDL_image.h>

/*
A singleton game template
*/
class Game
{
public:
	SDL_Window* window{ nullptr };
	SDL_Renderer* renderer{ nullptr };
	GameState* currentState{ nullptr };

private:
	bool loop{ true };
	Uint32 previousTicks;

public:
	Game();
	int Init(const char* title, int width, int height);
	void Input();
	void Run(GameState* start);
	void Exit();

private:
	void Close();

public:
	/*
	Represents that current Game state that this engine interacts with
	This is used so that drawing functions don't need to be passed a pointer to the renderer
	*/
	static Game* inst;

};

