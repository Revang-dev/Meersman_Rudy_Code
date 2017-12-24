#include "abstractBouton.h"


void abstractBouton::draw() {
	GraphicPrimitives::drawOutlinedRect2D(x , y, 0.04 + (0.0286*sizeN), 0.1, 1.0f, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawFillRect2D(x , y, 0.04 + (0.0286*sizeN), 0.1, 1.0f, 1.0f, 1.0f, trans);
	GraphicPrimitives::drawText2D(name, x + 0.02 , y + 0.025, 1.0f, 1.0f, 1.0f, 1.0f);
}

float abstractBouton::getPosX() {
	return x;
}

float abstractBouton::getPosY() {
	return y;
}

void abstractBouton::act() {
};

void abstractBouton::actived() {
	trans = 0.5f;
}

void abstractBouton::desactived() {
	trans = 0.2f;
}

void abstractBouton::setTrans(float transp) {
	trans = transp;
}

void abstractBouton::changeState(bool state){
	etat = state;
}

bool abstractBouton::getState() {
	return etat;
}

void abstractBouton::changeName(char* nom) {
	name = nom;
	sizeN = 0;
	while (nom[sizeN] != '\0') {
		sizeN++;
	}
	//x = x - (0.01 + (0.0286*(sizeN / 2)));
}