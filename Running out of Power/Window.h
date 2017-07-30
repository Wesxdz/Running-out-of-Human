#pragma once

#include "Component.h"
#include "Scriptable.h"
#include "Texture.h"
#include <SDL_mixer.h>

class Window : public Component, public Scriptable
{
public:
	Window();
	virtual bool Input(SDL_Event* event);
	virtual void Draw();

	virtual void Event(std::string name, int numArgs, std::string* args);
private:
	Texture city;
	Texture glass;
	bool broken{ false };
	Mix_Chunk* breakingSound;
	Mix_Chunk* suspenseSound;
	Mix_Chunk* windSound;
	Mix_Chunk* highWindSound;
};