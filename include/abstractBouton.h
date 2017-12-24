#pragma once
#include "GraphicPrimitives.h"

class abstractBouton {

private:
	float x;
	float y;
	char* name;
	float trans;
	int sizeN;
	bool etat;

public:

	abstractBouton(float x_, float y_, char* name_) :
		x(x_), y(y_), name(name_), trans(0.2f),etat(false) {
			sizeN = 0;
			while (name_[sizeN] != '\0') {
				sizeN++;
		}
			x = x - (0.01 + (0.0286*(sizeN / 2)));
	}

	void draw();

	float getPosX();
	float getPosY();
	void setTrans(float transp);
	void actived();
	virtual void desactived();
	void changeState(bool state);
	void changeName(char* nom);
	bool getState();
	virtual void act();
};

