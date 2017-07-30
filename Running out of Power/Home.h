#pragma once

#include "Assets.h"
#include "Component.h"
#include "GameState.h"
#include "Storyteller.h"
#include "Texture.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <vector>

class Home : public GameState
{
public:
	Home();
	~Home();
	virtual void Input(SDL_Event* event);
	virtual void Update(int dt);
	virtual void Draw();

public:
	Storyteller mStory; 
private:
	Texture mBackground;
	Mix_Chunk* mMusic;
};