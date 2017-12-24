#pragma once
#include "GraphicPrimitives.h"
#include "abstractTower.h"

class Dalle {

private:
	float x;
	float y;
	float size;
	boolean posable;
	abstractTower* tour;
	bool transparant;

public:

	Dalle(float fx = 0.0f, float fy = 0.0f) :
		x(fx), y(fy),
		size(0.155f), posable(true), tour(NULL),transparant(false)
	{}


	void draw();
	abstractTower* getTower();
	float getPosX();
	float getPosY();
	void setTransparancy();
	boolean isPosable();
	void putTower(abstractTower* tower);
	void removeTower();

};
