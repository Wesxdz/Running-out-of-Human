#include "Door.h"

#include "Assets.h"
#include <SDL_mixer.h>
#include <iostream>

Door::Door() :
	door {Assets::manager->getTexture("door.png"), 1 }
{

}

void Door::Draw()
{
	door.Render(0, 13, 93);
}

void Door::Event(std::string name, int numArgs, std::string * args)
{
	if (name == "btn") {
		Mix_PlayChannel(4, Assets::manager->getSound("door_toggle.wav"), 0);
	}
}

Button::Button() :
	btn{ Assets::manager->getTexture("door_btn.png"), 1 }
{

}

void Button::Draw()
{
	btn.Render(0, 5, 106);
}

bool Button::Input(SDL_Event * event)
{
	if (event->type == SDL_MOUSEBUTTONDOWN) {
		SDL_Point mouseClick{ event->button.x, event->button.y };
		SDL_Rect buttonArea{ 5, 106, btn.getSpriteWidth(), btn.getSpriteHeight() };
		if (SDL_PointInRect(&mouseClick, &buttonArea)) {
			controls->Event("btn");
		}
	}
	return false;
}



