#pragma once
#include "GraphicPrimitives.h"
#include "abstractBouton.h"
#include "environment.h"

class startBouton : public abstractBouton{

private:
	environment* env;

public:

	startBouton(float x_, float y_,environment *env_) :
		abstractBouton(x_,y_, new char[6]{ 'S','T', 'A','R','T','\0' }),env(env_) {}

	void act();
	void desactived();
};

