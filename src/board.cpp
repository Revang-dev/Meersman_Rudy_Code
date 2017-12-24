#include "board.h"


Dalle* board::getDalle(int i) {
	return area[i];
}

int board::size() {
	return area.size();
}

int board::sizeTower() {
	int res = 0;
	for (int i = 0; i < area.size(); i++) {
		if (!area[i]->isPosable()) {
			res++;
		}
	}
	return res;
}

int board::nbTowerSimple() {
	int res = 0;
	for (int i = 0; i < area.size(); i++) {
		if (!area[i]->isPosable() && area[i]->getTower()->getType() == 1) {
			res++;
		}
	}
	return res;
}

int board::nbTowerHeavy() {
	int res = 0;
	for (int i = 0; i < area.size(); i++) {
		if (!area[i]->isPosable() && area[i]->getTower()->getType() == 2) {
			res++;
		}
	}
	return res;
}

int board::nbTowerDefense() {
	int res = 0;
	for (int i = 0; i < area.size(); i++) {
		if (!area[i]->isPosable() && area[i]->getTower()->getType() == 3) {
			res++;
		}
	}
	return res;
}


int board::nbTowerSnipe() {
	int res = 0;
	for (int i = 0; i < area.size(); i++) {
		if (!area[i]->isPosable() && area[i]->getTower()->getType() == 4) {
			res++;
		}
	}
	return res;
}