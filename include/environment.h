#pragma once
#include "GraphicPrimitives.h"
#include "MyGameEngine.h"
#include "Player.h"
#include "abstractTower.h"
#include "board.h"
#include "abstractBouton.h"
#include "abstractMenu.h"
#include "abstractMeteor.h"
#include "menuDraw.h"
#include "hud.h"

class environment : public GameEngineBase,public GraphicEngineBase,public ControlEngineBase{
private:

	std::vector<abstractMeteor*> movingListener;
	std::vector<abstractBouton*> listenable;
	std::vector<abstractBouton*> buyingL;
	menuDraw menuBuy;
	board game;
	Player player;
	hud HUD;
	bool stop;
	bool buying;
	int type;
	bool init;
	int nbTower;
	int vague;
	bool gameOver;

public:
	environment()
		:player(Player()), game(board(13, 5)),
		movingListener(), stop(true), buying(false), type(1), menuBuy(menuDraw()), HUD(hud(&player)), init(true), nbTower(4), vague(1), gameOver(false)
		{
		initBouton();

	}

	Player* getPlayer();

	board getBoard();

	std::vector<abstractMeteor*> getMeteor();

	void addMovable(abstractMeteor* obj);

	void updateTower();

	void addTower(int i);

	void sellTower(int i);

	void initBouton();

	void updateMeteor();

	void changeStateAll();

	void initWave(int lvl);

	bool clickable(int posX, int posY,float minPosX, float minPosY, float maxPosX, float maxPosY);

	void setStop();

	bool hasHitTower(abstractMeteor* obj);

	void setBuying();

	void changeType(int i);

	void playerHit(int k);

	/**********************************************************/
	virtual void idle();

	virtual void Draw();

	virtual void MouseCallback(int bouton, int state, int x, int y);

};
