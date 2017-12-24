#pragma once
#include "GraphicPrimitives.h"
#include "abstractTower.h"
#include "environment.h"
#include "heavyShot.h"

class heavyTower : public abstractTower
{

private:
	environment* env;

public:
	heavyTower(float x_, float y_, environment *env_)
		:abstractTower(x_, y_, heavyShot(x_, y_),100,2), env(env_) {

		this->setRange(5);
		this->setPower(3);
		this->setLife(3);
		this->setPrice(2000);
	};

	void shot();
	void hit();
	void draw();
};
