#pragma once

class Storyteller;
#include "rapidxml.hpp"
#include "rapidxml_utils.hpp"
#include "Paragraph.h"
#include <string>

enum Interact 
{
	CHAT, INFO, MEMO
};

struct Choice 
{
	std::string input;
	std::string reaction;
	Interact type;
};

struct Scene
{
	std::string prompt;
	Choice choice[3];
};

class DialogueManager
{
public:
	DialogueManager();
	void LoadNext();

public:
	std::string playerName;
	Scene currentScene;
	Storyteller* mStoryteller;
	const char* types[3];
private:
	rapidxml::xml_document<> DOM;
	rapidxml::file<> mStoryFile;
	rapidxml::xml_node<>* mCurrentScene;

private:
	void FillScene();
	void Actions(rapidxml::xml_node<>* search);
	std::string PostProcess(std::string text);
};
