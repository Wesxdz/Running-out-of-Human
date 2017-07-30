#pragma once

#include "Component.h"
#include "Spritesheet.h"
#include "Scriptable.h"

class Door : public Component, public Scriptable
{
public:
	Door();
	Spritesheet door;
	virtual void Draw();
	virtual void Event(std::string name, int numArgs, std::string* args);
};

class Button : public Component
{
public:
	Button();
	Spritesheet btn;
	Scriptable* controls;
	virtual void Draw();
	virtual bool Input(SDL_Event* event);
};
