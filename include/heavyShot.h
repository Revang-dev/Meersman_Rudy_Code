#pragma once
#include "GraphicPrimitives.h"
#include "abstractShot.h"

class heavyShot : public abstractShot
{
private:

public:
	heavyShot(float x_, float y_) :
		abstractShot(x_, y_, 0.01, 5)
	{}

};
