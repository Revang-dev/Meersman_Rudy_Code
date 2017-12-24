#include "basicMeteor.h"

void basicMeteor::draw() {
	posx.clear();
	posy.clear();
	posx.push_back(this->getX());
	posy.push_back(this->getY());
	posx.push_back(this->getX() + 0.04);
	posy.push_back(this->getY() + 0.03);
	posx.push_back(this->getX() + 0.08);
	posy.push_back(this->getY() - 0.03);
	posx.push_back(this->getX() + 0.03);
	posy.push_back(this->getY() + 0.01);
	posx.push_back(this->getX() + 0.03);
	posy.push_back(this->getY() - 0.09);
	posx.push_back(this->getX() + 0.07);
	posy.push_back(this->getY() - 0.07);
	GraphicPrimitives::drawFillPolygone2D(posx, posy, 1.0f, 1.0f, 1.0f, this->getTrans());
}
