/*#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "Dalle.h"
#include "Ship.h"
#include "Shot.h"
#include "movingEntities.h"
#include "Bouton.h"
#include "Player.h"

class MyGraphicEngine : public GraphicEngineBase {
private:
	std::vector<Dalle*>* area;
	std::vector<Meteor*>* ennemy;
	std::vector<Shot*> *tire;
	std::vector<Ship*> *tower;
	std::vector<Bouton*> *listener;
	Player* player;

public:

	MyGraphicEngine(std::vector<Dalle * > * area_, std::vector<Ship*> *tower_,std::vector<Shot*> *tire_, std::vector<Meteor*> *ennemy_, std::vector<Bouton*> *listener_, Player* player_) :
		area(area_),tower(tower_),tire(tire_), ennemy(ennemy_), listener(listener_), player(player_)
	{}

	float x1, x2, dx1, dx2;

	virtual void Draw();

};
*/