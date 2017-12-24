#include "defenseTower.h"
#include "basicShot.h"

void defenseTower::shot() {
	if (this->timeToShot()) {
		this->addList(basicShot(this->getPosX(), this->getPosY()));
	}
}

void defenseTower::draw() {
	GraphicPrimitives::drawFillTriangle2D(this->getPosX() - 0.05f, this->getPosY() + 0.05f, this->getPosX() - 0.05f, this->getPosY() - 0.05f, this->getPosX() + 0.05f, this->getPosY(), 0.0f, 0.0f, 1.0f, 1.0f);
}

void defenseTower::hit() {
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