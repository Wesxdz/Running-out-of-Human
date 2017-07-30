#include "Person.h"

#include "Game.h"

Person::Person()
{
}


Person::~Person()
{
}

void Person::Draw()
{
	mAnimations[mCurrentAnimation]->Render(mLocation.x, mLocation.y);
}

void Person::Update(int dt)
{
	for (Animation* animation : mAnimations) {
		animation->Update(dt);
	}
}

void Person::Event(std::string name, int numArgs, std::string * args)
{
	if (name == "move") {
		mLocation = SDL_Point{ std::stoi(args[0]), std::stoi(args[1]) };
	}
	if (name == "jump") {
		Game::inst->Exit();
	}
}
