#pragma once

#include "GraphicPrimitives.h"
#include "abstractBouton.h"

class abstractMenu {
private:

	float posY;
public:
	abstractMenu(float pos) :posY(pos) {
	}

	float getPosY();
	virtual void draw();
};
