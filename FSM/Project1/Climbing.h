#pragma once
#include "Animation.h"
#include "State.h"

class Climbing : public State
{
public:
	Climbing() {};
	~Climbing() {};
	void idle(Animation* a);
};