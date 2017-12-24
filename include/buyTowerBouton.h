#pragma once
#include "GraphicPrimitives.h"
#include "abstractBouton.h"
#include "environment.h"

class buyTowerBouton : public abstractBouton {

private:
	environment* env;
	int type;

public:

	buyTowerBouton(float x_, float y_, environment *env_,int t) :
		abstractBouton(x_, y_, new char[6]{ 'A','C', 'H','A','T','\0' }), env(env_),type(t) {}

	void act();
};

