#include "Window.h"

#include "Assets.h"
#include "Game.h"
#include "Util.h"
#include <SDL_mixer.h>

Window::Window() :
	city{Assets::manager->getTexture("city.png")}
{
	glass = Assets::manager->getTexture("broken_glass.png");
	breakingSound = Assets::manager->getSound("window_break.wav");
	suspenseSound = Assets::manager->getSound("intense.wav");
	windSound = Assets::manager->getSound("wind.ogg");
	highWindSound = Assets::manager->getSound("high.ogg");
}

bool Window::Input(SDL_Event * event)
{
	return false;
}

void Window::Draw()
{
	if (broken) {
		SDL_SetRenderDrawColor(Game::inst->renderer, 1, 1, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderFillRect(Game::inst->renderer, NULL);
	}
	city.Render(72, 75);
	if (broken) {
		glass.Render(72, 75);
	}
}

void Window::Event(std::string name, int numArgs, std::string * args)
{
	if (name == "stop") {
		Mix_FadeOutChannel(0, 2000);
	}
	if (name == "break") {
		broken = true;
		Mix_PlayChannel(5, breakingSound, 0);
		//Mix_SetDistance(6, 200);
		//Mix_PlayChannel(6, suspenseSound, 0);
		Mix_PlayChannel(7, windSound, -1);
		Mix_PlayChannel(0, highWindSound, -1);
	}
}
