#include "InputHandler.h"

InputHandler::InputHandler()
{

	commandA_ = &jump_;
//new JumpCommand;

	//commandA_->Execute();

	commandB_ = &fire_;
}

void InputHandler::handleInput()
{



	gameController = SDL_GameControllerOpen(0);

	//commandA_->Execute();
	//macro.add(commandA_);

	//commandB_->Execute();
	//macro.add(commandB_);

	//case SDL_KEYDOWN:

	while (SDL_PollEvent(&event))
	{



		switch (event.key.keysym.sym)
		{
		case SDLK_LEFT: {
			commandA_->Execute();
			macro.add(commandA_);
		} break;

		case SDLK_DOWN: {
			commandA_->Execute();
			macro.add(commandB_);
		} break;

		case SDLK_UP: {
			commandA_->Execute();
			macro.add(commandC_);
		} break;

		case SDLK_RIGHT: {
			commandA_->Execute();
			macro.add(commandD_);
		} break;
		}

	}


	if (SDL_GameControllerGetButton(gameController, SDL_CONTROLLER_BUTTON_A))
	{
		commandA_->Execute();
		macro.add(commandA_);
	}
	if (SDL_GameControllerGetButton(gameController, SDL_CONTROLLER_BUTTON_B))
	{
		commandB_->Execute();
		macro.add(commandB_);
	}

	if (SDL_GameControllerGetButton(gameController, SDL_CONTROLLER_BUTTON_X))commandC_->Execute();
	
	if (SDL_GameControllerGetButton(gameController, SDL_CONTROLLER_BUTTON_Y))commandD_->Execute();
	
}
