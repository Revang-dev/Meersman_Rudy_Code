#pragma once
#include "GraphicPrimitives.h"
#include "abstractTower.h"
#include "basicShot.h"
#include "environment.h"

class defenseTower : public abstractTower
{

private:
	environment* env;

public:
	defenseTower(float x_, float y_, environment *env_)
		:abstractTower(x_, y_, basicShot(x_, y_),80,3), env(env_) {
		this->setRange(5);
		this->setPower(1);
		this->setLife(6);
		this->setPrice(1000);
	};

	void shot();
	void draw();
	void hit();
};
