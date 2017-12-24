#include "weakMeteor.h"

void weakMeteor::draw() {
	posx.clear();
	posy.clear();
	posx.push_back(this->getX());
	posy.push_back(this->getY());
	posx.push_back(this->getX() + 0.09);
	posy.push_back(this->getY() + 0.03);
	posx.push_back(this->getX() + 0.05);
	posy.push_back(this->getY() - 0.03);
	GraphicPrimitives::drawFillPolygone2D(posx, posy, 1.0f, 1.0f, 1.0f, this->getTrans());
}
