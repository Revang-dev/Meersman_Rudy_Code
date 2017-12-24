#pragma once
#include "GraphicPrimitives.h"
#include "abstractTower.h"
#include "environment.h"
#include "snipeShot.h"

class snipeTower : public abstractTower{
private:
	environment* env;

public:
	snipeTower(float x_, float y_, environment *env_)
		:abstractTower(x_, y_, snipeShot(x_, y_),100,4), env(env_) {
		this->setRange(13);
		this->setPower(1);
		this->setLife(3);
		this->setPrice(1500);
	}

	void shot();
	void hit();
	void draw();
};
