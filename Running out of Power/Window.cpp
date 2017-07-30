#include "Window.h"

#include "Assets.h"
#include "Util.h"

Window::Window() :
	city{Assets::manager->getTexture("city.png")}
{
}

bool Window::Input(SDL_Event * event)
{
	if (event->type == SDL_MOUSEBUTTONDOWN) {
		if (Util::IsOver(event->button, SDL_Point{ 72, 75 }, &city)) {
			on = !on;
		}
	}
	return false;
}

void Window::Draw()
{
	if (on) {
		city.Render(72, 75);
	}
}
