#include "abstractTower.h"


void abstractTower::draw() {
	GraphicPrimitives::drawFillTriangle2D(x - 0.05f, y + 0.05f, x - 0.05f, y - 0.05f, x + 0.05f, y, 1.0f, 1.0f, 1.0f, trans);
}

float abstractTower::getPosX() {
	return x;
}

float abstractTower::getPosY() {
	return y;
}

void abstractTower::shot() {
}

int abstractTower::getType() {
	return type;
}

void abstractTower::getShotDraw() {
	for (int i = 0; i < tireList.size(); i++) {
		tireList[i].draw();
	}
}

void abstractTower::getShotMove() {
	for (int i = 0; i < tireList.size(); i++) {
			tireList[i].move();
	}
	timeAdvance();
	if (invul) {
		if (invulTime < 20) {
			invulTime++;
		}
		else {
			notInvul();
		}
	}
}

void abstractTower::timeAdvance() {
	time += 1;
}

bool abstractTower::timeToShot() {
	return (time >= freq);
}

void abstractTower::addList(abstractShot shot_) {
	tireList.push_back(shot_);
	time = 0;
}

void abstractTower::resetAllShot() {
	for (int i = 0; i < tireList.size(); i++) {
		if(tireList[i].reset())
			tireList.erase(tireList.begin() + i);
	}
}

void abstractTower::resetForcedShot(int i){
	tireList.erase(tireList.begin() + i);
}

void abstractTower::resetAllForcedShot() {
	for (int i = 0; i < tireList.size(); i++) {
		tireList.erase(tireList.begin() + i);
	}
}

movingEntities* abstractTower::getShot(int i) {
	return &tireList[i];
}

int abstractTower::sizeShot() {
	return tireList.size();
}

void abstractTower::setRange(int i) {
	range = i;
}

void abstractTower::setPower(int i) {
	power = i;
}
void abstractTower::setLife(int i) {
	life = i;
}
void abstractTower::setPrice(int i) {
	price = i;
}

int abstractTower::getRange() {
	return range;
}
int abstractTower::getPower() {
	return power;
}
int abstractTower::getLife() {
	return life;
}
int abstractTower::getPrice() {
	return price;
}

void abstractTower::isHit(int degat) {
	if (!invul) {
		life -= degat;
	}
}
 
void abstractTower::hit() {
}

void abstractTower::nowInvul() {
	invul = true;
	trans = 0.3;
}

void abstractTower::notInvul() {
	invul = false;
	invulTime = 0;
	trans = 1.0;
}

bool abstractTower::getInvul() {
	return invul;
}