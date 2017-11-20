#pragma once
#include "Component.h"

class ControllerComponent : public Component
{
private:
	SDL_Point velocity = { 0, 0 };

public:
	ControllerComponent() : Component("Controller") {};
	~ControllerComponent() {};

	SDL_Point getVelocity() { return velocity; }
	void setVelocity(SDL_Point position) { (this->velocity = position); }
};