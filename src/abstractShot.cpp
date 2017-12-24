#include "abstractShot.h"


void abstractShot::draw() {
	GraphicPrimitives::drawFillRect2D(this->getX(), this->getY(), 0.1f, 0.01f, 1.0,1.0, 1.0, 1.0f);
}

bool abstractShot::reset() {
	return (this->getX() > (baseX + range));
}



