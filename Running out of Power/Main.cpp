#include "Assets.h"
#include "Game.h"
#include "NameEntry.h"
#include <SDL.h>

int main(int argc, char** argv)
{
	Game game;
	Assets manager;
	game.Init("Running out of Human", 200, 200);
	//SDL_SetRenderDrawBlendMode(Game::inst->renderer, SDL_BLENDMODE_ADD);
	SDL_Surface* icon = Assets::manager->loadSurface("icon.png");
	SDL_SetWindowIcon(Game::inst->window, icon);
	SDL_FreeSurface(icon);
	game.Run(new NameEntry);
	return 0;
}