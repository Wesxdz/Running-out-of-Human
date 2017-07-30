#pragma once

struct Mix_Chunk;
struct SDL_Renderer;
struct SDL_Texture;
struct _TTF_Font;
struct SDL_Surface;
class Spritesheet;
#include <map>
#include <string>
#include <vector>

class Assets {

public:
	std::map<std::string, SDL_Texture*> mTextures;
	std::map<std::string, Mix_Chunk*> mSounds;
	std::map<std::string, _TTF_Font*> mFonts;
	/* Add Spritesheet pointers to this to free them up at the end of the game
	This is useful for objects that have Clip Renderables and must maintain a Spritesheet pointer indirectly
	*/
	std::vector<Spritesheet*> mSheets;

public:
	static Assets* manager;

public:
	Assets();
	~Assets();

	int Init();

	void Shutdown();

	SDL_Surface* loadSurface(std::string file);
	SDL_Texture* getTexture(std::string file);
	Mix_Chunk* getSound(std::string file);
	_TTF_Font* getFont(std::string file, int size);

};