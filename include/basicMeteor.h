#pragma once
#include "GraphicPrimitives.h"
#include "abstractMeteor.h"
#include "environment.h"

class basicMeteor : public abstractMeteor {

private:
	environment* env;
	std::vector<float> posx;
	std::vector<float> posy;

public:

	basicMeteor(float speed, float row_, float x_,int freq) :
		abstractMeteor(3, speed, row_, x_, 200, 200,freq)
	{}

	void draw();

};

