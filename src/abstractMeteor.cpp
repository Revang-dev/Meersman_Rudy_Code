#include "abstractMeteor.h"


void abstractMeteor::draw() {
	posx.clear();
	posy.clear();
	posx.push_back(this->getX());
	posy.push_back(this->getY());
	posx.push_back(this->getX() + 0.04);
	posy.push_back(this->getY() + 0.03);
	posx.push_back(this->getX() + 0.08);
	posy.push_back(this->getY() - 0.03);
	posx.push_back(this->getX() + 0.03);
	posy.push_back(this->getY() + 0.01);
	posx.push_back(this->getX() + 0.03);
	posy.push_back(this->getY() - 0.09);
	posx.push_back(this->getX() + 0.07);
	posy.push_back(this->getY() - 0.07);
	GraphicPrimitives::drawFillPolygone2D(posx, posy, 1.0f, 1.0f, 1.0f, trans);
}


int abstractMeteor::getScore() {
	return score;
}

int abstractMeteor::getMoney() {
	return money;
}

void abstractMeteor::hit(int damage) {
	if(!invul)
		life -= damage;
}

float abstractMeteor::getRow() {
	return row;
}

int abstractMeteor::getLife() {
	return life;
}

void abstractMeteor::nowInvul() {
	invul = true;
	trans = 0.3;
}

float abstractMeteor::getTrans() {
	return trans;
}

void abstractMeteor::move() {
	if (freq == 0) {
		this->setX(this->getX() + this->getSpeed());
	}
	else {
		freq--;
	}
	if (invul) {
		if (invulTime < 20) {
			invulTime++;
		}
		else {
			notInvul();
		}
	}
}

void abstractMeteor::notInvul() {
	invul = false;
	invulTime = 0;
	trans = 1.0;
}

bool abstractMeteor::getInvul() {
	return invul;
}

bool abstractMeteor::deadArmageddon() {
	return false;
}
