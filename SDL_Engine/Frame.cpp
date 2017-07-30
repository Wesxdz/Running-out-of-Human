#include "Frame.h"

#include "Spritesheet.h"

Frame::Frame(Spritesheet* sheet, int tile, int delay) :
	Clip{ sheet, tile },
	mDelay{ delay }
{
}
