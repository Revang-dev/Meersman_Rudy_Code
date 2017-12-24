#include "environment.h"
#include "basicTower.h"
#include "defenseTower.h"
#include "snipeTower.h"
#include "heavyTower.h"
#include "startBouton.h"
#include "sellBouton.h"
#include "buyBouton.h"
#include "buyTowerBouton.h"
#include "abstractMeteor.h"
#include "basicMeteor.h"
#include "armageddonMeteor.h"
#include "weakMeteor.h"
#include "heavyMeteor.h"




Player* environment::getPlayer() {
	return &player;
}

board environment::getBoard() {
	return game;
}

std::vector<abstractMeteor*> environment::getMeteor() {
	return movingListener;
}

/***************************************************************/

void environment::initWave(int level) {
	if (vague < 4) {
		for (int k = 0; k < level; k++) {
			for (int j = 1; j < game.sizeTower(); j++) {
				movingListener.push_back(new weakMeteor(-0.005, rand() % 4, 1.1, (rand() % (level + 1) * 40)));
			}
		}
	}
	else if (vague < 8) {
		for (int k = 0; k < level; k++) {
				movingListener.push_back(new basicMeteor(-0.005, rand() % 4, 1.1, (rand() % (level + 1) * 40)));
				if (game.nbTowerDefense() > 0 || game.nbTowerHeavy() > 0 || game.nbTowerSnipe() > 0) {
					movingListener.push_back(new basicMeteor(-0.005, rand() % 4, 1.1, (rand() % (level + 1) * 40)));
			}
		}
	}
	else if (vague < 15) {
		for (int k = 0; k < level; k++) {
				movingListener.push_back(new basicMeteor(-0.005, rand() % 4, 1.1, (rand() % (level + 1) * 40)));
				if (game.nbTowerDefense() > 0 || game.nbTowerHeavy() > 0) {
					movingListener.push_back(new heavyMeteor(-0.005, rand() % 4, 1.1, (rand() % (level + 1) * 40)));
			}
		}
	}

	else {
		for (int k = 0; k < level; k++) {
			//for (int a = 1; a < game.sizeTower(); a++) {
			movingListener.push_back(new basicMeteor(-0.005, rand() % 4, 1.1, (rand() % (level + 1) * 40)));
			int type = rand() % 2;
	
			if (type ==0) {
				movingListener.push_back(new heavyMeteor(-0.005, rand() % 4, 1.1, (rand() % (level + 1) * 40)));
			}
			else{ 
				movingListener.push_back(new armageddonMeteor(-0.005, rand() % 4, 1.1, (rand() % (level + 1) * 40)));
				}

			//}
		}
	}
}

void environment::initBouton() {
	listenable.push_back(new startBouton(0.0, -0.1, this));
	listenable.push_back(new sellBouton(0.5, -0.4, this));
	listenable.push_back(new buyBouton(-0.5, -0.4, this, false));
	buyingL.push_back(new buyTowerBouton((-1.0f + (0.3f * 1)) + (0.02 + (0.0286*(5 / 2))), -0.8, this, 1));
	buyingL.push_back(new buyTowerBouton((-1.0f + (0.3f * 2)) + (0.02 + (0.0286*(5 / 2))), -0.8, this, 2));
	buyingL.push_back(new buyTowerBouton((-1.0f + (0.3f * 3)) + (0.02 + (0.0286*(5 / 2))), -0.8, this, 3));
	buyingL.push_back(new buyTowerBouton((-1.0f + (0.3f * 4)) + (0.02 + (0.0286*(5 / 2))), -0.8, this, 4));
	buyingL.push_back(new buyBouton(0.7, -0.8, this, true));
	menuBuy.initBuy(buyingL);
}

void environment::setStop() {
	stop = !stop;
}

void environment::setBuying() {
	buying = !buying;
}

void environment::changeType(int i){
	type = i;
}

bool environment::hasHitTower(abstractMeteor* obj) {
	for (int i = 0; i < 13; i++) {
		if (!game.getDalle(i + (13 * obj->getRow()))->isPosable()) {
			if (obj->getX() >= game.getDalle(i + (13 * obj->getRow()))->getPosX() - 0.15f
				&& obj->getX() <= game.getDalle(i + (13 * obj->getRow()))->getPosX()) {
				int vie = obj->getLife();
				obj->hit(game.getDalle(i + (13 * obj->getRow()))->getTower()->getLife());
				obj->nowInvul();
				game.getDalle(i + (13 * obj->getRow()))->getTower()->isHit(vie);
				game.getDalle(i + (13 * obj->getRow()))->getTower()->nowInvul();
				return true;
			}
		}
	}
	return false;
}

void environment::playerHit(int k) {
	if (movingListener[k]->getX() < -1.0) {
		player.hit();
		movingListener.erase(movingListener.begin() + k);
	}
	if (player.getLife() <= 0) {
		stop = true;
		gameOver = true;
	}
}

void environment::changeStateAll() {
	for (int k = 0; k < listenable.size(); k++) {
		listenable[k]->changeState(false);
		listenable[k]->desactived();
	}
	for (int j = 0; j < buyingL.size(); j++) {
		buyingL[j]->changeState(false);
		buyingL[j]->desactived();
	}
}

bool environment::clickable(int posX, int posY, float minPosX, float minPosY, float maxPosX, float maxPosY){
	float floatX = posX / 400.0f - 1.0f;
	float floatY = (posY / 300.0f - 1.0f) * -1;
	return (floatX  < minPosX + maxPosX && floatX  > minPosX &&
		floatY < minPosY + maxPosY && floatY  > minPosY);
}

void environment::sellTower(int i) {
	player.addGold(game.getDalle(i)->getTower()->getPrice() / 2);
	game.getDalle(i)->removeTower();

}

void environment::addTower(int i) {
	if (game.sizeTower() >= 4 * (2 + vague/10)) {
		type = 0;
	}
	if (type == 1) {
		if (init) {
			nbTower--;
			game.getDalle(i)->putTower(new basicTower(game.getDalle(i)->getPosX() + 0.07f, game.getDalle(i)->getPosY() + 0.07f, this));
			game.getDalle(i)->getTower()->shot();
		}
		else if(player.getGold() >= 500) {
			game.getDalle(i)->putTower(new basicTower(game.getDalle(i)->getPosX() + 0.07f, game.getDalle(i)->getPosY() + 0.07f, this));
			player.buyGold(game.getDalle(i)->getTower()->getPrice());
			game.getDalle(i)->getTower()->shot();
		}
	}
	else if (type == 2 && player.getGold() >= 2000) {
			game.getDalle(i)->putTower(new heavyTower(game.getDalle(i)->getPosX() + 0.07f, game.getDalle(i)->getPosY() + 0.07f, this));
			player.buyGold(game.getDalle(i)->getTower()->getPrice());
			game.getDalle(i)->getTower()->shot();
	}
	else if (type == 3 && player.getGold() >= 1000) {
		game.getDalle(i)->putTower(new defenseTower(game.getDalle(i)->getPosX() + 0.07f, game.getDalle(i)->getPosY() + 0.07f, this));
		player.buyGold(game.getDalle(i)->getTower()->getPrice());
		game.getDalle(i)->getTower()->shot();
	}
	else if (type == 4 && player.getGold() >= 1000) {
		game.getDalle(i)->putTower(new snipeTower(game.getDalle(i)->getPosX() + 0.07f, game.getDalle(i)->getPosY() + 0.07f, this));
		player.buyGold(game.getDalle(i)->getTower()->getPrice());
		game.getDalle(i)->getTower()->shot();
	}
}

void environment::addMovable(abstractMeteor* obj) {
	movingListener.push_back(obj);
}

void environment::updateTower() {
	for (int i = 0; i < game.size(); i++) {
		if (!game.getDalle(i)->isPosable()) {
			if (game.getDalle(i)->getTower()->getLife() <= 0) {
				game.getDalle(i)->removeTower();
			}
		}
	}
}

void environment::updateMeteor() {
	bool arma = false;
	float posX;
	for (int i = 0; i < movingListener.size(); i++) {
		if (movingListener[i]->getLife() <= 0) {
			if (movingListener[i]->deadArmageddon()) {
				arma =true;
				posX = movingListener[i]->getX();
			}
			if (player.getGold() < 10000) {
				player.addGold(movingListener[i]->getScore());
				if (player.getGold() > 10000) {
					player.setGold(10000);
				}
			}
			player.addScore(movingListener[i]->getMoney());
			movingListener.erase(movingListener.begin() + i);

		}
	}
	if (arma) {
		movingListener.push_back(new basicMeteor(-0.005, rand() % 4, posX,0));
		movingListener.push_back(new basicMeteor(-0.005, rand() % 4, posX,0));
	}
	if (movingListener.size() < 1 && !stop) {
		for (int k = 0; k < game.size(); k++) {
			if (!game.getDalle(k)->isPosable())
				game.getDalle(k)->getTower()->notInvul();
		}
		stop = true;
		for (int z = 0; z < game.size(); z++){
			if (!game.getDalle(z)->isPosable())
				game.getDalle(z)->getTower()->resetAllForcedShot();
		}
		vague++;
		initWave(vague);
		changeStateAll();
	}
}


/****************************************************************/

void environment::idle() {
	if (nbTower == 0) {
		stop = false;
		init = false;
		initWave(vague);
		nbTower = -1;
	}
	if (!stop) {

		for (int i = 0; i < game.size(); i++) {
			if (!game.getDalle(i)->isPosable()) {
				game.getDalle(i)->getTower()->resetAllShot();
				game.getDalle(i)->getTower()->getShotMove();
				game.getDalle(i)->getTower()->hit();
				game.getDalle(i)->getTower()->shot();
			}
		}
		for (int k = 0; k < movingListener.size(); k++) {
			movingListener[k]->move();
			hasHitTower(movingListener[k]);
			playerHit(k);
		}
		updateMeteor();
	}
	updateTower();
}

void environment::Draw() {
	glutReshapeWindow(800, 600);
	HUD.draw(game.size());
	HUD.vague(vague);
	for (int i = 0; i < game.size(); i++) {
		game.getDalle(i)->draw();
		if (!stop && !game.getDalle(i)->isPosable()) {
			game.getDalle(i)->getTower()->getShotDraw();
		}
	}
	if (!gameOver) {
		if (!stop) {
			for (int k = 0; k < movingListener.size(); k++) {
				movingListener[k]->draw();
			}
		}
		if (!init) {
			if (!buying) {
				for (int l = 0; l < listenable.size(); l++) {
					listenable[l]->draw();
				}
			}
			else {
				menuBuy.drawMenu();
			}
		}
		else if (nbTower >= 0) {
			GraphicPrimitives::drawText2D(new char[17]{ 'P','l', 'a', 'c', 'e', 'z',' ','v','o','s',' ', 'T','o','u','r','s' ,'\0' }, 0.0 - (0.0286* 7.5) - 0.0143, 0.0, 1.0f, 1.0f, 1.0f, 1.0f);
			GraphicPrimitives::drawText2D(new char[57]{ 'L','e', ' ', 'j', 'e', 'u',' ','d','e','m', 'a', 'r','r','e','r','a',' ', 'q','u','a','n','d' ,' ', 'v', 'o','u','s',' ', 'a','u','r','e','z' , ' ', 'p','l','a','c','e',' '
				,'t','o','u','t','e','s',' ','v','o','s',' ','t','o','u','r','s','\0' }, 0.0 - (0.0286* 19.5) - (0.0143 * 4.5), -0.1, 1.0f, 1.0f, 1.0f, 1.0f);
			GraphicPrimitives::drawText2D(strcat(new char[18]{ 'T','o', 'u', 'r', 's', ' ','a',' ','p','l','a', 'c','e','r',' ' ,':' ,' ','\0' }, _itoa(nbTower, new char[1], 10)), 0.0 - (0.0286* 9.0), -0.2, 1.0f, 1.0f, 1.0f, 1.0f);
		}
	}else{
		GraphicPrimitives::drawText2D(new char[10]{ 'G','a', 'm', 'e', ' ', 'O','v','e','r' ,'\0' }, 0.0 - (0.0286* 7.5) - 0.0143, 0.0, 1.0f, 0.0f, 0.0f, 1.0f);
	}
}

void environment::MouseCallback(int button, int state, int posX, int posY) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		//bouton play pour mettre en route le jeu
		if (stop) {
			for (int i = 0; i < game.size(); i++) {
				if (clickable(posX, posY, game.getDalle(i)->getPosX(), game.getDalle(i)->getPosY(), 0.155f, 0.155f) && type != 0) {
					if (type == 5 && !game.getDalle(i)->isPosable()) {
						sellTower(i);
					}
					else if (game.getDalle(i)->isPosable()) {
						addTower(i);
					}
				}
			}
			if (!buying) {
				for (int k = 0; k < listenable.size(); k++) {
					if (clickable(posX, posY, listenable[k]->getPosX(), listenable[k]->getPosY(), 0.2f, 0.1f)) {
						if (!listenable[k]->getState()) {
							changeStateAll();
						}
						listenable[k]->act();
					}
				}
			}
			else {
				for (int k = 0; k < buyingL.size(); k++) {
					if (clickable(posX, posY, buyingL[k]->getPosX(), buyingL[k]->getPosY(), 0.2f, 0.1f)) {
						changeStateAll();
						buyingL[k]->act();
					}
				}
			}
		}
	}
}

