#include "Home.h"

#include "Game.h"
#include "Window.h"
#include "TextManager.h"

Home::Home()
{
	mBackground = Texture{ Assets::manager->getTexture("background.png") };
	mMusic = Assets::manager->getSound("Early.ogg");
	//Mix_SetDistance(0, 200);
	Mix_PlayChannel(0, mMusic, -1);
}

Home::~Home()
{
}

void Home::Input(SDL_Event* event)
{
	if (event->type == SDL_QUIT || event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_ESCAPE) {
		Game::inst->Exit();
	}
	mStory.Input(event);
}

void Home::Update(int dt)
{
	mStory.Update(dt);
}

void Home::Draw()
{
	SDL_RenderClear(Game::inst->renderer);
	mBackground.Render(0, 0);
	mStory.Draw();
	SDL_RenderPresent(Game::inst->renderer);
}
