
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

	Animation fsm; int i = 0;




	SDL_Surface * image = IMG_Load("walk_f.png");
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer,
		image);
	
	//SDL_SetRenderDrawColor(renderer, 168, 230, 255, 255);
	int ySprite = 256;


	while (!quit)
	{
		Uint32 ticks = SDL_GetTicks();
		Uint32 seconds = ticks / 1000;
		int sprite = seconds % 3;

		SDL_Rect srcrect = { sprite * 256, ySprite, 256, 256 };
		SDL_Rect dstrect = { 256, 256, 256, 256 };

		//if (sprite != 0 && sprite % 3 == 0)
		//{

		//	srcrect = { sprite * 256, 256, 256, 256 };
		//	dstrect = { 256, 256, 256, 256 };
		//	ySprite *= 2;
		//}

	
		//SDL_WaitEvent(&event);

		//switch (event.type)
		//{
		//case SDL_QUIT:
		//	quit = true;
		//	break;
		//}


		if (i == 0)
		{
			//std::this_thread::sleep_for(std::chrono::milliseconds)

			//or call idle 

			//std::this_thread::sleep_for(2s);
			std::this_thread::sleep_for(std::chrono::milliseconds::duration(1000));
			i = 1;
		}

		else if (i == 1)
		{
	
			

			//std::this_thread::sleep_for(2s);
			std::this_thread::sleep_for(std::chrono::milliseconds::duration(1000));

			i = 0;

		}



		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{

			case SDL_KEYDOWN:
			{
				switch (event.key.keysym.sym)
				{

				case SDLK_LEFT: {
					image = IMG_Load("walk_b.png");
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


