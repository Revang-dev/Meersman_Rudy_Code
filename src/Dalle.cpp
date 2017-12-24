#include "Dalle.h"

void Dalle::draw() {
	if (!transparant) {
		GraphicPrimitives::drawFillRect2D(x, y, size, size, 1.0, 1.0, 1.0, 0.1f);
		GraphicPrimitives::drawOutlinedRect2D(x, y, size, size, 1.0, 1.0, 1.0, 1.0f);
	}
	if (!posable) {
		tour->draw();
	}
}

float Dalle::getPosX() {
	return x;
}

float Dalle::getPosY() {
	return y;
}


boolean Dalle::isPosable() {
	return posable;
}
void Dalle::putTower(abstractTower* tower) {
	tour = tower;
	posable = false;
}

void Dalle::removeTower() {
	tour = NULL;
	posable = true;
}

void Dalle::setTransparancy() {
	transparant = !transparant;
}


abstractTower* Dalle::getTower() {
	return tour;
}