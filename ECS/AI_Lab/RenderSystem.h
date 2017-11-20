#pragma once
#include "PositionComponent.h"
#include "Entity.h"
#include "SDL.h"
#include "SDL_image.h"


class RenderSystem
{
	std::vector<Entity *> entities;

public:

	void addEntity(Entity &e) { entities.push_back(&e); }
	void update(SDL_Renderer* sdl_renderer);

};