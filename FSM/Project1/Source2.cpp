
#define SPRITE_SIZE    256


#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <SDL.h>
using namespace std;
#include <iostream>
#include <list>
#include "Command.h"
#include "InputHandler.h"
#include "SDL_thread.h"


#include <chrono>
#include <thread>
#include "Animation.h"
#include "State.h"
#include "SDL_image.h"

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);




	//Walking animation
	const int WALKING_ANIMATION_FRAMES = 4;


	/* source and destination rectangles */
	SDL_Rect rcSrc, rcSprite;


	//code here



	InputHandler input;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window * window = SDL_CreateWindow("SDL2 Keyboard/Mouse events",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1080, 960, 0);
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);

	bool quit = false;
	SDL_Event event;

	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);

	//
	//SDL_Surface * image = IMG_Load("spritesheet.png");
	//SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer,
	//	image);


	// handle events

	Animation fsm; 
	int i = 0;




	SDL_Surface * image = IMG_Load("walk_f2.png");
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer,
		image);
	
	//SDL_SetRenderDrawColor(renderer, 168, 230, 255, 255);
	int ySprite = 256;


	while (!quit)
	{
		Uint32 ticks = SDL_GetTicks();
		Uint32 seconds = ticks / 300;
		int sprite = seconds % 3;

		SDL_Rect srcrect = { sprite * 256, ySprite, 256, 256 };
		SDL_Rect dstrect = { 256, 256, 256, 256 };


		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{

			case SDL_KEYDOWN:
			{
				switch (event.key.keysym.sym)
				{
				default:
				case SDLK_LEFT: {
					image = IMG_Load("atk.png");
					texture = SDL_CreateTextureFromSurface(renderer,
						image);
					fsm.jumping();

				} break;

				case SDLK_DOWN: {
					image = IMG_Load("idle2.png");
					texture = SDL_CreateTextureFromSurface(renderer,
						image);
					fsm.idle();
				} break;

				case SDLK_UP: {

				} break;

				case SDLK_RIGHT: {
					image = IMG_Load("walk_f2.png");
					texture = SDL_CreateTextureFromSurface(renderer,
						image);
					fsm.climbing();
					//fsm.idle();
				} break;

				}
			}

			case SDL_KEYUP:
			{
	
			}

			}
		}



		SDL_RenderCopy(renderer, texture, &srcrect, &dstrect);
		SDL_RenderPresent(renderer);
		SDL_RenderClear(renderer); //bg color
	}

	SDL_DestroyTexture(texture);
	SDL_FreeSurface(image);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();



	return 0;

}


