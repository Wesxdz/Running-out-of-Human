#include "Animation.h"

#include "Frame.h"
#include "Game.h"
#include "Spritesheet.h"

Animation::Animation(Frame* frames, int numFrames) :
	mFrames{ frames },
	mNumFrames{ numFrames },
	mDelayLeft{ frames[0].mDelay }
{
}

Animation::~Animation()
{
	for (int i = 0; i < mNumFrames; i++) {
		delete &mFrames[i];
	}
}

void Animation::Update(int dt)
{
	while (dt >= mDelayLeft) {
		dt -= mDelayLeft;
		mCurrentFrame = (mCurrentFrame == mNumFrames - 1) ? 0 : mCurrentFrame + 1;
		mDelayLeft = mFrames[mCurrentFrame].mDelay;
	}
	mDelayLeft -= dt;
}

void Animation::Render(int x, int y) const
{
	mFrames[mCurrentFrame].Render(x, y);
}

void Animation::Render(int x, int y, float scale, double angle, SDL_Point * center) const
{
	mFrames[mCurrentFrame].Render(
		x, y,
		scale,
		angle, center
	);
}

Animation* Animation::Loop(Spritesheet* sheet, int delay)
{
	int numFrames = sheet->getNumRows() * sheet->getNumColumns();
	Frame* frames = new Frame[numFrames];
	for (int i = 0; i < numFrames; i++) {
		frames[i] = Frame{ sheet, i, delay };
	}
	return new Animation{ frames, numFrames };
}
