#pragma once
#include "PositionComponent.h"
#include "HPComponent.h"
#include "Entity.h"

class AISystem
{
private:
	std::vector<Entity *> entities;

public:
	AISystem() {};
	void addEntity(Entity &e);
	void update();

};