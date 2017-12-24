#pragma once
#include "GraphicPrimitives.h"
#include "abstractBouton.h"
#include "environment.h"

class buyBouton : public abstractBouton {

private:
	environment* env;

public:

	buyBouton(float x_, float y_, environment *env_, bool i) :
		abstractBouton(x_, y_, new char[6]{ 'A','C', 'H','A','T','\0' }), env(env_) {
		if (i) {
			this->changeName(new char[7]{ 'R','E', 'T','O','U','R', '\0' });
	}
	}

	void act();
};

