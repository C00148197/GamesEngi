#include "AISystem.h"

void AISystem::addEntity(Entity &e)
{
	entities.push_back(&e);
}

void AISystem::update() 
{



	for (auto i = entities.begin(), e = entities.end(); i != e; i++) 
	{

		for (int i2 = 0; i2 < (*i)->getComponents().size(); i2++) {

			if ((*i)->getComponents().at(i2)->getID() == "Position") //if current entity component has a position
			{
				std::cout << "AI update Pos" << std::endl;

			}

			else if ((*i)->getComponents().at(i2)->getID() == "HP") //if current entity component has a position
			{
				std::cout << "AI update HP" << std::endl;

			}
		}
	}

}


