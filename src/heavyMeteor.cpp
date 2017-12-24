#include "heavyMeteor.h"

void heavyMeteor::draw() {
	posx.clear();
	posy.clear();
	posx.push_back(this->getX());
	posy.push_back(this->getY());

	posx.push_back(this->getX() + 0.04);
	posy.push_back(this->getY() + 0.03);

	posx.push_back(this->getX() + 0.04);
	posy.push_back(this->getY() - 0.08);

	posx.push_back(this->getX() + 0.08);
	posy.push_back(this->getY() - 0.04);

	posx.push_back(this->getX());
	posy.push_back(this->getY() - 0.04);

	posx.push_back(this->getX() + 0.08);
	posy.push_back(this->getY());

	GraphicPrimitives::drawFillPolygone2D(posx, posy, 1.0f, 1.0f, 1.0f, this->getTrans());
}