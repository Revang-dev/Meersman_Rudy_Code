/*#pragma once
#include "Engine.h"
#include "Dalle.h"
#include "Ship.h"
#include "Shot.h"
#include "board.h"

class MyControlEngine : public ControlEngineBase {
	std::vector<Ship*> *tower;
	std::vector<Dalle*> *plateau;
	std::vector<Shot*> *tire;
	GameEngineBase *ce;
public:
	MyControlEngine(std::vector<Ship*> *tower_, std::vector<Dalle*> *plateau_, std::vector<Shot*> *tire_, GameEngineBase *ce_) :
		tower(tower_), plateau(plateau_),tire(tire_),ce(ce_)
	{}


	void getDalle(float posx, float pos);
	virtual void MouseCallback(int bouton, int state, int x, int y);
};*/