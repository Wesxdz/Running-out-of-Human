#include "DialogueManager.h"

#include "Util.h"
#include "Storyteller.h"
#include <iostream>

using namespace rapidxml;

DialogueManager::DialogueManager() :
	mStoryFile{ rapidxml::file<>("../resources/scripts/story.xml") }
{
	types[0] = "Communicate";
	types[1] = "Upload Data";
	types[2] = "Invoke Memory";
	DOM.parse<0>(mStoryFile.data());
	mCurrentScene = DOM.first_node("scene");
	FillScene();
}

void DialogueManager::LoadNext()
{
	Actions(mCurrentScene);
	if (mCurrentScene->next_sibling("scene")) {
		mCurrentScene = mCurrentScene->next_sibling("scene");
		FillScene();
	}
}

void DialogueManager::FillScene()
{
	currentScene.prompt = PostProcess(mCurrentScene->first_node("prompt")->value());
	xml_node<>* option = mCurrentScene->first_node("option");
	for (int i = 0; i < 3; i++) {
		xml_node<>* choice = option->first_node("choice");
		Interact type = Interact::CHAT;
		if (choice->first_attribute("type")) {
			if (std::string(choice->first_attribute("type")->value()) == "memo") {
				type = Interact::MEMO;
			}
			else {
				type = Interact::INFO;
			}
		}
		currentScene.choice[i] = Choice{ PostProcess(choice->value()), PostProcess(option->first_node("reaction")->value()) , type };
		if (i < 2) {
			option = option->next_sibling("option");
		}
	}
}

void DialogueManager::Actions(xml_node<char>* search)
{
	xml_node<>* person = search->first_node("person");
	while (person) {
		xml_node<>* action = person->first_node("action");
		while (action) {
			if (std::string(action->first_attribute("type")->value()) == "move") {
				std::string args[2];
				args[0] = action->first_attribute("x")->value();
				args[1] = action->first_attribute("y")->value();
				mStoryteller->mElements[person->first_attribute("name")->value()]->Event("move", 2, &args[0]);
			}
			action = action->next_sibling("action");
		}
		person = person->next_sibling("person");
	}
}

std::string DialogueManager::PostProcess(std::string text)
{
	std::string namePlaceholder = "#NAME#";
	Util::Replace(text, namePlaceholder, playerName);
	return text;
}
