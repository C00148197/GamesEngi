#pragma once
#include <iostream>
#include <string>
#include "SDL.h"

class Component
{
private:
	std::string id;

public:
	Component() {}
	Component(std::string argID) { id = argID; }
	~Component() {}

	std::string getID() { return id; }

	void setID(std::string argID) { id = argID; }

};