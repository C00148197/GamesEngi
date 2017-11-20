#pragma once
#include "ControllerComponent.h"
#include "PositionComponent.h"
#include "Entity.h"

class ControllerSystem
{
	std::vector<Entity *> entities;
public:
	void addEntity(Entity &e) { entities.push_back(&e); }
	void update(SDL_Event &e);
};