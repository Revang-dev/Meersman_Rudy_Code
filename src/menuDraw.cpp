#include "menuDraw.h"

void menuDraw::initBuy(std::vector<abstractBouton*> buyingL_) {
	buyingL = buyingL_;
}

void menuDraw::drawOne(char* name, float posY, float i, int pow, int range, int life, int price, float r, float v, float b) {
	char* strp = new char[2];
	char* strr = new char[2];
	char* strl = new char[2];
	char* strprice = new char[4];
	float posX = (-1.0f + (0.3f * i));
	GraphicPrimitives::drawOutlinedRect2D(posX, posY, 0.2f, 0.2f, r, v, b, 1.0f);
	GraphicPrimitives::drawFillTriangle2D(((posX + 0.1f) - 0.05f), (posY + 0.1f) + 0.05f, ((posX + 0.1f) - 0.05f), (posY + 0.1f) - 0.05f, ((posX + 0.1f) + 0.05f), (posY + 0.1f), r,v, b, 1.0f);
	GraphicPrimitives::drawText2D((strcat((new char[10]{ 'P','O', 'W', ' ', ' ', ' ',' ', ':',' ','\0' }), _itoa(pow, strp, 10))),
		posX, posY - 0.1, 1.0f, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D((strcat((new char[10]{ 'R','A', 'N', 'G', 'E', ' ',' ', ':',' ','\0' }), _itoa(range, strr, 10))),
		posX, posY - 0.2, 1.0f, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D((strcat((new char[10]{ 'L','I', 'F', 'E', ' ', ' ',' ', ':',' ','\0' }), _itoa(life, strl, 10))),
		posX, posY - 0.3, 1.0f, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D((strcat((new char[10]{ 'P','R', 'I', 'C', 'E', ' ',' ', ':',' ','\0' }), _itoa(price, strprice, 10))),
		posX, posY - 0.4, 1.0f, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D(name, posX, posY + 0.21, 1.0f, 1.0f, 1.0f, 1.0f);
	buyingL[i - 1]->draw();
}

void menuDraw::drawMenu() {
	drawOne((new char[7]{ 'N','O', 'R', 'M', 'A', 'L','\0' }), -0.2f, 1.0, 1, 5, 3, 500, 1.0, 1.0, 1.0);
	drawOne((new char[6]{ 'L','O', 'U', 'R', 'D', '\0'}), -0.2f, 2.0, 5, 5, 3, 2000, 1.0, 1.0, 0.0);
	drawOne((new char[7]{ 'D','E', 'F', 'E', 'N', 'D','\0' }), -0.2f, 3.0, 1, 5, 10, 1000, 0.0, 0.0, 1.0);
	drawOne((new char[7]{ 'S','N', 'I', 'P', 'E', 'R','\0' }), -0.2f, 4.0, 1, 13, 3, 1500, 1.0, 0.0, 0.5);
	buyingL[4]->draw();
}