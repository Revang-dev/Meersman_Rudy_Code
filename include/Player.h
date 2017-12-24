#pragma once
class Player {

private:
	int score;
	int gold;
	int life;

public:
	Player()
		:gold(0),life(10),score(0){}
	void hit();
	void addGold(int x);
	void addScore(int x);
	void buyGold(int x);
	void addLife();
	int getGold();
	int getScore();
	int getLife();
	void setGold(int i);
};

