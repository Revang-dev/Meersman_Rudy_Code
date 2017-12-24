#include "startBouton.h"

void startBouton::act() {
	if (!this->getState()) {
		actived();
		changeName(new char[8]{ 'P','L', 'A','Y','I','N', 'G','\0' });
		this->changeState(true);
		env->setStop();
	}
}

void startBouton::desactived() {
	this->setTrans(0.2);
	changeName(new char[6]{ 'S','T','A','R','T','\0' });
	this->changeState(false);
}