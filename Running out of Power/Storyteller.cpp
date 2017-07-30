#include "Storyteller.h"

#include "Animation.h"
#include "Assets.h"
#include "Door.h"
#include "Window.h"

Storyteller::Storyteller() :
	dots{Spritesheet{Assets::manager->getTexture("dots.png"), 2}}
{
	story.mStoryteller = this;
	choiceType = { 200, 20, Assets::manager->getFont("habbo.ttf", 15) };
	thoughts = { 180, 30, Assets::manager->getFont("habbo.ttf", 15) };
	thoughts.SetText(story.currentScene.prompt);

	Door* door = new Door;
	mComponents.push_back(door);
	mElements["door"] = door;

	Button* button = new Button;
	button->controls = door;
	mComponents.push_back(button);

	Window* window = new Window;
	mComponents.push_back(window);
	mElements["window"] = window;


	Person* vanilla = new Person;
	vanilla->mAnimations.push_back(Animation::Loop(new Spritesheet(Assets::manager->getTexture("vanilla.png"), 2), 500));
	vanilla->mLocation = SDL_Point{ 140, 110 };
	mComponents.push_back(vanilla);
	mElements["vanilla"] = vanilla;

	click = Assets::manager->getSound("click.ogg");
	convey[0] = Assets::manager->getSound("beep.ogg");
	convey[1] = Assets::manager->getSound("upload.wav");
	convey[2] = Assets::manager->getSound("memo.wav");
}

Storyteller::~Storyteller()
{
	for (Component* component : mComponents) {
		delete component;
	}
}
void Storyteller::Update(int dt)
{
	blink -= dt;
	if (blink <= -500) {
		blink = 800;
	}
	if (pause > 0) {
		pause -= dt;
		if (pause <= 0) {
			pause = 0;
			if (moveNext) {
				Mix_PlayChannel(3, Assets::manager->getSound("think.wav"), 0);
				story.Actions(story.mCurrentScene);
				thoughts.SetText(story.currentScene.prompt);
				pause = story.currentScene.prompt.length() * 80;
				moveNext = false;
			}
			else {
				thoughts.mColor = SDL_Color{ 58, 227, 209 };
				thoughts.SetText(story.currentScene.choice[option].input);
				choiceType.SetText(story.types[story.currentScene.choice[option].type]);
				blink = 2000;
			}
			thoughts.mColor = SDL_Color{ 58, 227, 209 };
		}
	}
	for (Component* component : mComponents) {
		component->Update(dt);
	}
}

void Storyteller::Draw()
{
	for (Component* component : mComponents) {
		component->Draw();;
	}
	thoughts.Render(10, 10);
	if (!pause) {
		if (blink > 0) choiceType.Render(0, 50);
		for (int i = 0; i < 3; i++) {
			dots.Render((i == option) ? 1 : 0, 20 + 11 * i , 54);
		}
	}
}

bool Storyteller::Input(SDL_Event* event)
{
	switch (event->type) {
	case SDL_KEYDOWN:
		if (!pause) {
			switch (event->key.keysym.sym) {
			case SDLK_RIGHT:
				SetOption(option + 1);
				return true;
			case SDLK_LEFT:
				SetOption(option - 1);
				return true;
			case SDLK_RETURN:
				Mix_PlayChannel(2, convey[story.currentScene.choice[option].type], 0);
				thoughts.mColor = SDL_Color{ 255, 255, 255 };
				thoughts.SetText(story.currentScene.choice[option].reaction);
				pause = story.currentScene.choice[option].reaction.length() * 80;
				story.LoadNext();
				moveNext = true;
				return true;
			}
		}
		if (pause) { pause = 1; }
		break;
	}
	for (Component* component : mComponents) {
		component->Input(event);
	}
	return false;
}

void Storyteller::SetOption(int num)
{
	if (pause == 0) {
		if (num < 0) { num = 2; }
		option = num % 3;
		Mix_SetPosition(1, 270 + option * 90, 0);
		Mix_PlayChannel(1, click, 0);
		thoughts.SetText(story.currentScene.choice[option].input);
		choiceType.SetText(story.types[story.currentScene.choice[option].type]);
		blink = 1000;
	}
}
