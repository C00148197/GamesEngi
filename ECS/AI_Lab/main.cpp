#define SDL_MAIN_HANDLED

#include "SDL.h"
#include "SDL_image.h"
#include "AISystem.h"
#include "ControllerSystem.h"
#include "RenderSystem.h"
#include "Entity.h"


#include <iostream>


int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);


	// creates SDL window
	SDL_Window * window = SDL_CreateWindow("Entity Component System", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,1000, 600, 0);

	// sets renderer for window
	SDL_Renderer * sdl_renderer = SDL_CreateRenderer(window, -1, 0);

	//entities

	Entity* player = new Entity("Player");
	Entity* alien = new Entity("Alien");
	Entity* dog = new Entity("Dog");
	Entity* cat = new Entity("Cat");

	//add components to entities
	player->addComponent(new ControllerComponent());
	player->addComponent(new HPComponent());
	player->addComponent(new PositionComponent());


	alien->addComponent(new HPComponent());
	alien->addComponent(new PositionComponent());

	dog->addComponent(new HPComponent());
	dog->addComponent(new PositionComponent());

	cat->addComponent(new HPComponent());
	cat->addComponent(new PositionComponent());

	//add entities to systems
	AISystem aiSystem;
	ControllerSystem controllerSystem;
	RenderSystem renderSystem;

	controllerSystem.addEntity(*player);

	aiSystem.addEntity(*alien);
	aiSystem.addEntity(*dog);
	aiSystem.addEntity(*cat);

	renderSystem.addEntity(*player);
	renderSystem.addEntity(*alien);
	renderSystem.addEntity(*dog);
	renderSystem.addEntity(*cat);

	SDL_Event event;

	bool isRunning = true;


	while (isRunning) 
	{

		SDL_PollEvent(&event);

		aiSystem.update();
		controllerSystem.update(event);
		SDL_RenderClear(sdl_renderer);
		renderSystem.update(sdl_renderer);


		SDL_SetRenderDrawColor(sdl_renderer, 125, 125, 125, 255);
		SDL_RenderPresent(sdl_renderer);
	}

	return 0;
}