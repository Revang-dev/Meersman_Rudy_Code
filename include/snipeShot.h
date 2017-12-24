#pragma once
#include "GraphicPrimitives.h"
#include "abstractShot.h"

class snipeShot : public abstractShot
{
private:

public:
	snipeShot(float x_, float y_) :
		abstractShot(x_, y_, 0.015, 14)
	{}

};
