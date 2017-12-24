#pragma once
#include "GraphicPrimitives.h"
#include "abstractTower.h"
#include "environment.h"
#include "basicShot.h"

class basicTower : public abstractTower
{

private:
	environment* env;

public:
	basicTower(float x_, float y_, environment *env_)
		:abstractTower(x_, y_, basicShot(x_,y_),80,1), env(env_) {
		this->setRange(5);
		this->setPower(1);
		this->setLife(3);
		this->setPrice(500);
	};

	void shot();
	void hit();
};
