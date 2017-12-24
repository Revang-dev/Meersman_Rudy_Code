#include "sellBouton.h"

void sellBouton::act() {
	if (!this->getState()) {
		actived();
		changeState(true);
		env->changeType(5);
	}else {
		desactived();
		changeState(false);
		env->changeType(0);
	}
}