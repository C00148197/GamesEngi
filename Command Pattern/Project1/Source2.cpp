//////################
//bridge bit two
#include <SDL.h>
using namespace std;
#include <iostream>
#include <list>
#include "Command.h"
#include "InputHandler.h"


int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);



	//code here

	InputHandler input;

	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window * window = SDL_CreateWindow("SDL2 Keyboard/Mouse events",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);



	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	// handle events


	while (true != false)
	{
		input.handleInput();

		SDL_RenderClear(renderer);

		SDL_RenderPresent(renderer);
	}

	system("PAUSE");
	SDL_Quit();
	return 0;
}



//end








	

//	Command* command = new MacroCommand;

