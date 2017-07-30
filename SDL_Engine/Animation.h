#pragma once

struct Frame;
class Spritesheet;
#include "Renderable.h"

class Animation : public Renderable
{
public:
	Animation(Frame* frames, int numFrames);
	~Animation();
	void Update(int dt);
	void Render(int x, int y) const;
	void Render(int x, int y, float scale, double angle = 0, SDL_Point* center = nullptr) const;
	/*
	@return: An Animation instance that loops through all the tiles of #sheet with #delay milliseconds
	*/
	static Animation* Loop(Spritesheet* sheet, int delay = 100);

public:
	Frame* mFrames;
	int mNumFrames;
	int mCurrentFrame{ 0 };

private:
	int mDelayLeft{ 0 };
};

