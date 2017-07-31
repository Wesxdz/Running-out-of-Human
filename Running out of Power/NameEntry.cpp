#include "NameEntry.h"

#include "Assets.h"
#include "Game.h"
#include "Home.h"
#include "TextManager.h"
#include <iostream>

NameEntry::NameEntry()
{
	hint = Paragraph{ 200, 40, Assets::manager->getFont("habbo.ttf", 15) };
	hint.mVertical = Align::TOP;
	entry = hint;
	controls = hint;
	controls.mWidth = 160;
	controls.SetText("Use the right/left arrow keys and enter to play");
	hint.SetText("ENTER NAME");
	entry.mColor = SDL_Color{ 58, 227, 209 };
	SDL_StartTextInput();
}


NameEntry::~NameEntry()
{
}

void NameEntry::Input(SDL_Event* event)
{
	if (event->type == SDL_QUIT || event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_ESCAPE) {
		Game::inst->Exit();
	}
	if (event->type == SDL_KEYDOWN) {
		if (event->key.keysym.sym == SDLK_BACKSPACE) {
			name = name.substr(0, name.length() - 1);
			entry.SetText(name);
		}
		if (event->key.keysym.sym == SDLK_RETURN && name.length() > 0) {
			Home* home = new Home;
			home->mStory.story.playerName = name;
			Game::inst->currentState = home;
			delete this;
		}
	}
	if (event->type == SDL_TEXTINPUT && *event->text.text != ' ' && name.length() < 6) {
		name += event->text.text;
		entry.SetText(name);
	}
}

void NameEntry::Update(int dt)
{
}

void NameEntry::Draw()
{
	SDL_RenderClear(Game::inst->renderer);
	hint.Render(0, 60);
	entry.Render(0, 90);
	controls.Render(20, 160);
	SDL_RenderPresent(Game::inst->renderer);
}
