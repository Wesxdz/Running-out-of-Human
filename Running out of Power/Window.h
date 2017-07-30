#pragma once

#include "Component.h"
#include "Texture.h"

class Window : public Component
{
public:
	Window();
	virtual bool Input(SDL_Event* event);
	virtual void Draw();
private:
	Texture city;
	bool on{ true };
};