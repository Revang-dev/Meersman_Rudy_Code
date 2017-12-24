#pragma once
#include "GraphicPrimitives.h"
#include "abstractShot.h"

class basicShot : public abstractShot
{
private:

public:
	basicShot(float x_, float y_) :
		abstractShot(x_, y_, 0.01, 5)
	{}

};
