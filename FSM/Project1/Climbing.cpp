
#include "Climbing.h"
#include "Idle.h"

void Climbing::idle(Animation* a)
{
	cout << "going from F to idling" << endl;
	a->setCurrent(new Idle());
	delete this;
}
