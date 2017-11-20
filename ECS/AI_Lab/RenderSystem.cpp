#include "RenderSystem.h"

void RenderSystem::update(SDL_Renderer* sdl_renderer) {
	
	for (auto i = entities.begin(), e = entities.end(); i != e; i++) 
	{

		for (int i2 = 0; i2 < (*i)->getComponents().size(); i2++) 
		{
			if ((*i)->getComponents().at(i2)->getID() == "Position") //draw things with positions
			{
				

				SDL_Rect *rect = new SDL_Rect;

				rect->w = 128;
				rect->h = 128;
				
				rect->x = static_cast<PositionComponent*>((*i)->getComponents().at(i2))->getPosition().x;
				rect->y = static_cast<PositionComponent*>((*i)->getComponents().at(i2))->getPosition().y;


				if ((*i)->getTag() == "Player")
				{
					SDL_SetRenderDrawColor(sdl_renderer, 255, 0, 0, 255);

					std::cout << "graphic update (player)" << std::endl;
				}
				else if ((*i)->getTag() == "Alien")
				{
					SDL_SetRenderDrawColor(sdl_renderer, 0, 255, 0, 255);
					std::cout << "graphic update (alien)" << std::endl;
				}
				else if ((*i)->getTag() == "Dog")
				{
					SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 255, 255);
					std::cout << "graphic update (dog)" << std::endl;
				}
				else if ((*i)->getTag() == "Cat")
				{
					SDL_SetRenderDrawColor(sdl_renderer, 255, 255, 255, 255);
					std::cout << "graphic update (cat)" << std::endl;
				}

				SDL_RenderFillRect(sdl_renderer, rect);
			}
		}
	}
}