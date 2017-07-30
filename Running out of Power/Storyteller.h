#pragma once

#include "Component.h"
#include "DialogueManager.h"
#include "Person.h"
#include "Spritesheet.h"
#include <SDL_mixer.h>
#include <map>
#include <vector>
#include <string>

class Storyteller
{
public:
	Storyteller();
	~Storyteller();
	virtual void Update(int dt);
	virtual void Draw();
	virtual bool Input(SDL_Event* event);

public:
	DialogueManager story;
	std::vector<Component*> mComponents;
	std::map<std::string, Scriptable*> mElements;

private:
	void SetOption(int num);

private:
	int option{ 0 };
	int blink{ 0 };
	Paragraph thoughts;
	Paragraph choiceType;
	int pause{ 5000 };
	bool moveNext{ false };
	Spritesheet dots;
	Mix_Chunk* click;
	Mix_Chunk* convey[3];
};