#pragma once
#include "GraphicPrimitives.h"

class movingEntities{
private:
	float x,y;
	float speed;

public:
	movingEntities(float x_, float y_, float speed_)
		:x(x_), y(y_),speed(speed_) {
	}

	float getX();

	float getY();

	void setX(float x);

	void setY(float y);

	float getSpeed();

	virtual void move();

	void setPosition(float x_, float y_);

	//virtual void draw();


};

