#pragma once

#include "Texture.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <vector>
#include <string>

struct LineDetails
{
	std::string text;
	Texture* image;
	SDL_Point offset;
};

enum Align {
	CENTER, LEFT, RIGHT, TOP, BOTTOM
};

class Paragraph : public Renderable
{
public:
	Paragraph();
	Paragraph(int width, int height, TTF_Font* font);
	~Paragraph();

	virtual void Render(int x, int y) const;

	void AddText(std::string text);
	void SetText(std::string text);

public:
	TTF_Font* mFont;
	SDL_Color mColor{ 255, 255, 255 };
	std::vector<LineDetails> mLines;
	int mWidth, mHeight;
	Align mHorizontal = Align::CENTER;
	Align mVertical = Align::CENTER;
	int lineSpacing = 1;
};

