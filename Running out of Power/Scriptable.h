#pragma once

#include <string>

class Scriptable
{
public:
	virtual void Event(std::string name, int numArgs = 0, std::string* args = nullptr) = 0;
};