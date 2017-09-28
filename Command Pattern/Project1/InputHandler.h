#pragma once
#include "Command.h"
#include <SDL.h>
class InputHandler
{
public:
	InputHandler();
	void handleInput();
	//methods to bind commands
private:
	Command* commandA_;
	Command* commandB_;
	Command* commandC_;
	Command* commandD_;
	JumpCommand jump_;
	FireCommand fire_;
	SDL_GameController *gameController;
	SDL_Event event;
	MacroCommand macro;
};

