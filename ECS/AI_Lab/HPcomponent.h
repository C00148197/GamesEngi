#pragma once
#include "Component.h"

class HPComponent : public Component
{
private:
	int hp;

public:
	HPComponent() : hp(9999), Component("HP") {}
	~HPComponent() {};
	int getHealth() { return hp; }
	void setHealth(int health) { this->hp = health; }

};