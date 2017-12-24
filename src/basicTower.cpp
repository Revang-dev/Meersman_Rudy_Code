#include "basicTower.h"
#include "basicShot.h"

void basicTower::shot() {
	if (this->timeToShot()) {
		this->addList(basicShot(this->getPosX(), this->getPosY()));
	}
}

void basicTower::hit() {
	for (int i = 0; i < env->getMeteor().size(); i++) {
		for (int k = 0; k < this->sizeShot(); k++) {
			if (env->getMeteor()[i]->getX() >= this->getShot(k)->getX() && env->getMeteor()[i]->getX() <= this->getShot(k)->getX() + 0.1
				&& env->getMeteor()[i]->getY() <= this->getShot(k)->getY() + (0.155f / 2) && env->getMeteor()[i]->getY() >= this->getShot(k)->getY() - (0.155f / 2)) {
				this->resetForcedShot(k);
				env->getMeteor()[i]->hit(this->getPower());
			}
		}
	}
}