#pragma once
#include "GraphicPrimitives.h"
#include "abstractMeteor.h"
#include "environment.h"

class weakMeteor : public abstractMeteor {

private:
	environment* env;
	std::vector<float> posx;
	std::vector<float> posy;
public:
	weakMeteor(float speed, float row_, float x_,int freq) :
		abstractMeteor(1, speed, row_, x_, 100, 100,freq)
	{}

	void draw();

};

