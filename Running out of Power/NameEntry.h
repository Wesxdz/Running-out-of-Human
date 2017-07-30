#pragma once

#include "GameState.h"
#include "Paragraph.h"
#include <string>

class NameEntry : public GameState
{
public:
	NameEntry();
	~NameEntry();

	virtual void Input(SDL_Event* event);
	virtual void Update(int dt);
	virtual void Draw();
private:
	Paragraph hint;
	Paragraph entry;
	std::string name;
};

