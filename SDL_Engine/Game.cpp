#include "Game.h"

#include <SDL_ttf.h>

Game* Game::inst{ nullptr };

Game::Game()
{
	inst = this;
};

int Game::Init(const char* title, int width, int height) {
	if (SDL_Init(SDL_INIT_VIDEO)) {
		SDL_Log("SDL initialization failed: %s", SDL_GetError());
		return 1;
	}
	window = SDL_CreateWindow(
		title,
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		width, height,
		SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
	);
	if (!window) {
		SDL_Log("Window creation failed: %s", SDL_GetError());
		SDL_Quit();
		return 2;
	}
	renderer = SDL_CreateRenderer(
		window,
		-1,
		SDL_WINDOW_SHOWN
	);
	if (!renderer) {
		SDL_Log("Rendering context creation failed: %s", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 3;
	}

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	return 0;
}

void Game::Input() {
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		currentState->Input(&event);
	}
}

void Game::Run(GameState* start) {
	currentState = start;
	while (loop) {
		// The number of milliseconds that have passed since the last frame
		Uint32 dt = SDL_GetTicks() - previousTicks;
		previousTicks = SDL_GetTicks();
		Input();
		currentState->Update(dt);
		currentState->Draw();
		if (dt < 10) {
			SDL_Delay(10 - dt); // Hard cap FPS to 100
		}
	}
	Close();
}

void Game::Exit()
{
	loop = false;
}

void Game::Close() {
	delete currentState;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}