#include "ControllerSystem.h"

void ControllerSystem::update(SDL_Event &event)
{


	for (auto i = entities.begin(), end = entities.end(); i != end; i++)
	{
		for (int i2 = 0; i2 < (*i)->getComponents().size(); i2++)
		{

			if ((*i)->getComponents().at(i2)->getID() == "Controller") //check for player input
			{
				SDL_Point point = { 0,0 };

				while (SDL_PollEvent(&event) != 0)
				{
					switch (event.type)
					{
					case SDL_KEYDOWN:
						switch (event.key.keysym.sym) 
						{
						case SDLK_LEFT:
							point.x -= 5;
							break;
						case SDLK_UP:
							point.y -= 5;
							break;
						case SDLK_RIGHT:
							point.x += 5;
							break;
						case SDLK_DOWN:
							point.y += 5;
							break;
						default:
							break;
						}
						break;
					}
				}

				static_cast<ControllerComponent*>((*i)->getComponents().at(i2))->setVelocity(point); //controller component has a velo, set it. It gets angry without a cast
			}


			else if ((*i)->getComponents().at(i2)->getID() == "Position") //apply player position updates
			{
				SDL_Point point;
				for (int i3 = 0; i3 < (*i)->getComponents().size(); i3++)
				{
					if ((*i)->getComponents().at(i3)->getID() == "Controller")  //change current position + velo change in position 
					{
						point.x = static_cast<PositionComponent*>((*i)->getComponents().at(i2))->getPosition().x + static_cast<ControllerComponent*>((*i)->getComponents().at(i3))->getVelocity().x;
						point.y = static_cast<PositionComponent*>((*i)->getComponents().at(i2))->getPosition().y + static_cast<ControllerComponent*>((*i)->getComponents().at(i3))->getVelocity().y;
						static_cast<PositionComponent*>((*i)->getComponents().at(i2))->setPosition(point);

					}
				}
				std::cout << "control update" << std::endl;
			}
		}
	}
}