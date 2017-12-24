#pragma once
#include "GraphicPrimitives.h"
#include "abstractShot.h"
#include "movingEntities.h"

class abstractTower {

private:
	float x;
	float y;
	int range;
	int power;
	int life;
	int price;
	int freq;
	std::vector<abstractShot>  tireList;
	bool invul;
	float trans;
	int invulTime;
	int time;
	int type;

public:
	abstractTower(float x_, float y_, abstractShot shot_,int freq_,int type_) :
		x(x_), y(y_),invul(false),trans(1.0f),freq(freq_),type(type_)
	{
		tireList.push_back(shot_);
	}


	virtual void draw();
	int getType();
	void getShotDraw();
	void getShotMove();
	float getPosX();
	float getPosY();
	int getRange();
	int getPower();
	int getLife();
	int getPrice();
	void setRange(int i);
	void setPower(int i);
	void setLife(int i);
	void setPrice(int i);
	void nowInvul();
	void notInvul();
	bool getInvul();
	void addList(abstractShot shot_);
	int sizeShot();
	bool timeToShot();
	void timeAdvance();
	void resetAllShot();
	void resetForcedShot(int i);
	void resetAllForcedShot();
	movingEntities* getShot(int i);
	virtual void shot();
	virtual void hit();
	void isHit(int degat);

	/*void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();*/
};
