#pragma once
#include "GraphicPrimitives.h"
#include "abstractBouton.h"
#include "environment.h"

class sellBouton : public abstractBouton {

private:
	environment* env;

public:

	sellBouton(float x_, float y_, environment *env_) :
		abstractBouton(x_, y_, new char[7]{ 'V','E', 'N','D','R', 'E','\0' }), env(env_) {}

	void act();
};

