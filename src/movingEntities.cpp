#include "movingEntities.h"
#include <math.h>

float movingEntities::getX() {
	return x;
}

float movingEntities::getY() {
	return y;
}

void movingEntities::setX(float posX) {
	x = posX;
}

void movingEntities::setY(float posY) {
	y = posY;
}

float movingEntities::getSpeed() {
	return speed;
}

void movingEntities::move() {
	x = x + speed;
}


void movingEntities::setPosition(float x_, float y_) {
	x = x_;
	y = y_;
}

/*void movingEntities::draw() {

}*/
