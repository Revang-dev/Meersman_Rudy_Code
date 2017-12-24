#pragma once
#include "GraphicPrimitives.h"
#include "movingEntities.h"

class abstractMeteor: public movingEntities {

private:
	int life;
	std::vector<float> posx;
	std::vector<float> posy;
	float row;
	bool invul;
	float trans;
	int invulTime;
	int score;
	int money;
	int freq;

public:
	abstractMeteor(int life_, float speed, float row_, float x_,int score_,int money_,int freq_) :
		movingEntities(x_, 1.0 - ((row_ * 0.155f) + (0.155f / 2.0)) - 0.02, speed),
		life(life_), row(row_), invul(false),trans(1.0),score(score_),money(money_),freq(freq_) {
	

	}

	int getScore();
	int getMoney();
	float getTrans();
	void move();
	int getLife();
	virtual void draw();
	void hit(int damage);
	virtual bool deadArmageddon();
	float getRow();
	void nowInvul();
	void notInvul();
	bool getInvul();
};

