#pragma once
#include "GraphicPrimitives.h"
#include "abstractMeteor.h"
#include "environment.h"

class armageddonMeteor : public abstractMeteor {

private:
	environment* env;
	std::vector<float> posx;
	std::vector<float> posy;
public:

	armageddonMeteor(float speed, float row_, float x_,int freq) :
		abstractMeteor(4, speed, row_, x_,200,400,freq)
	{}


	bool deadArmageddon();
	void draw();
};

