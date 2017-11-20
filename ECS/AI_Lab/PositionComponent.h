#pragma once
#include "Component.h"

class PositionComponent : public Component
{
private:
	SDL_Point position = { 0, 0 };

public:
	PositionComponent() : Component("Position") {}
	~PositionComponent() {};

	SDL_Point getPosition() { return position; }
	void setPosition(SDL_Point argPosition) { (this->position = argPosition); }

};