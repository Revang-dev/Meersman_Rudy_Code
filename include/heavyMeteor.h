#pragma once
#include "GraphicPrimitives.h"
#include "abstractMeteor.h"
#include "environment.h"

class heavyMeteor : public abstractMeteor {

private:
	environment* env;
	std::vector<float> posx;
	std::vector<float> posy;
public:

	heavyMeteor(float speed, float row_, float x_,int freq) :
		abstractMeteor(5, speed, row_, x_,500,500,freq)
	{}

	void draw();

};

