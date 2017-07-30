#pragma once

#include "Component.h"

#include "Animation.h"
#include "Renderable.h"
#include "Scriptable.h"
#include <vector>

class Person : public Component, public Scriptable
{
public:
	Person();
	~Person();

	virtual void Draw();
	virtual void Update(int dt);

	virtual void Event(std::string name, int numArgs, std::string* args);

public:
	std::vector<Animation*> mAnimations;
	int mCurrentAnimation;
	SDL_Point mLocation;
};

