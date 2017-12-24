#include <iostream>

#include "Engine.h"
#include "ControlEngineBase.h"
#include "GameEngineBase.h"
#include "GraphicEngineBase.h"
#include "environment.h"

int main(int argc, char* argv[]) {
	Engine e(argc, argv);

	environment* env = new environment;
	GraphicEngineBase* ge = env;
	GameEngineBase* gme = env;
	ControlEngineBase* ce = env;


	e.setGraphicEngine(ge);
	e.setGameEngine(gme);
	e.setControlEngine(ce);
	e.start();
	return 0;
}
