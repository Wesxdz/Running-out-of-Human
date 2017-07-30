#pragma once

#include "Clip.h"

struct Frame : public Clip
{
	Frame() {};
	Frame(Spritesheet* sheet, int tile, int delay = 100);
	int mDelay{ 100 };
};

