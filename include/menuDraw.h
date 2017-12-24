#pragma once
#include "GraphicPrimitives.h"
#include "abstractBouton.h"

class menuDraw{
private:
	std::vector<abstractBouton*> buyingL;


public:

	menuDraw() {}

	void initBuy(std::vector<abstractBouton*> buyingL);

	void drawOne(char* name, float posY, float i, int pow, int range, int life, int price, float r, float v, float b);

	void drawMenu();

};


