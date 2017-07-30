#include "GameState.h"

#include "Game.h"

GameState::~GameState()
{
}

bool GameState::ExitInput(SDL_Event* event)
{
	if (event->type == SDL_QUIT ||
		event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_ESCAPE) {
		Game::inst->Exit();
		return true;
	}
	return false;
}
