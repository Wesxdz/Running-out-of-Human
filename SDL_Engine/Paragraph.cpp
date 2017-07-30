#include "Paragraph.h"

#include "Assets.h"
#include "Game.h"
#include <iostream>

using namespace std;

Paragraph::Paragraph()
{
}

Paragraph::Paragraph(int width, int height, TTF_Font* font) :
	mFont{ font },
	mWidth{ width },
	mHeight{ height }
{
}

Paragraph::~Paragraph()
{
}

void Paragraph::Render(int x, int y) const
{
	for (LineDetails line : mLines) {
		line.image->Render(x + line.offset.x, y + line.offset.y);
	}
}

void Paragraph::AddText(std::string text)
{
}

// TODO: Reformat greatly
void Paragraph::SetText(std::string text)
{
	mLines.clear();
	vector<string> lines;
	string word;
	string currentLine;
	int totalHeight{ 0 };
	int lineWidth{ 0 };
	for (int i = 0; i < text.length(); i++) {
		word += text[i];
		bool isLastWord = i == text.length() - 1;
		if (text[i] == ' ' || isLastWord) {
			int wordWidth{ 0 };
			TTF_SizeText(mFont, word.c_str(), &wordWidth, NULL);
			if (lineWidth + wordWidth > mWidth) {
				int lineHeight{ 0 };
				TTF_SizeText(mFont, currentLine.c_str(), NULL, &lineHeight);
				totalHeight += lineHeight + lineSpacing;
				lines.push_back(currentLine);
				lineWidth = 0;
				currentLine = word;
				if (isLastWord) {
					totalHeight += lineHeight + lineSpacing;
					lines.push_back(currentLine);
				}
				word = "";
			}
			else {
				currentLine += word;
				if (isLastWord) {
					int lineHeight{ 0 };
					TTF_SizeText(mFont, currentLine.c_str(), NULL, &lineHeight);
					totalHeight += lineHeight + lineSpacing;
					lines.push_back(currentLine);
				}
				lineWidth += wordWidth;
				word = "";
			}
		}
	}

	int yOffsetStart = 0;
	switch (mVertical) {
	case Align::CENTER:
		yOffsetStart = (mHeight - totalHeight)/2;
		break;
	case Align::BOTTOM:
		yOffsetStart = mHeight - totalHeight;
		break;
	}
	int yOffsetAdd = 0;
	for (string lineText : lines) {
		SDL_Surface* lineSurface = TTF_RenderText_Solid(mFont, lineText.c_str(), mColor);
		int xOffset = 0;
		switch (mHorizontal) {
		case Align::CENTER:
			xOffset = (mWidth - lineSurface->w) / 2;
			break;
		case Align::RIGHT:
			xOffset = mWidth - lineSurface->w;
			break;
		}
		SDL_Point offset = { xOffset, yOffsetStart + yOffsetAdd };
		yOffsetAdd += lineSurface->h;
		SDL_Texture* lineTexture = SDL_CreateTextureFromSurface(Game::inst->renderer, lineSurface);
		SDL_FreeSurface(lineSurface);
		mLines.push_back(LineDetails{ lineText, new Texture{lineTexture}, offset });
	}
}
