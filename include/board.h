#pragma once
#include "Engine.h"
#include "Dalle.h"

class board  {
	std::vector<Dalle*> area;
	int width;
	int height;
public:
	board(int largeur,int hauteur) :width(largeur),height(hauteur) {
		for (int i = 1; i < height; i++) {
			for (int k = 0; k <= width; k++) {
				area.push_back(new Dalle(-1.0f + ((2.0/width)*k),  0.95f - (0.155*i)));
			}
		}
	}
	Dalle* getDalle(int i);
	int size();
	int sizeTower();
	int nbTowerSimple();
	int nbTowerHeavy();
	int nbTowerSnipe();
	int nbTowerDefense();
};
