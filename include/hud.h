#pragma once
#include "GraphicPrimitives.h"
#include "Player.h"

class hud{
private:
	Player* player;

public:
	hud(Player* player_):
		player(player_)
	{}

	void draw(int size);

	void vague(int i);

};
