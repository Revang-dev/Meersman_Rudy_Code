#pragma once
#include "GraphicPrimitives.h"
#include "movingEntities.h"

class abstractShot : public movingEntities{

private:
	float range;
	float baseX;


public:

	abstractShot(float x_, float y_, float speed,int range_) :
		movingEntities(x_, y_, speed),range(range_ * 0.155f),baseX(x_)
	{}

	bool reset();
	void draw();


};

