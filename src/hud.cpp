#include "hud.h"

void hud::draw(int size) {
	char* stra = new char[6];
	char* strp = new char[10];
	char* strl = new char[2];
	float position = 1.0 - (0.155f * (size / 13)) - 0.15f;
	GraphicPrimitives::drawOutlinedRect2D(-1.0f, position, 2.0f, 0.1, 1.0f, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D(strcat(new char[14]{ 'R','E', 'S', 'S', 'O', 'U','R','C','E','S',' ', ':',' ','\0' }, _itoa(player->getGold(), stra, 10)), -0.9, position + 0.025f, 1.0f, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D(strcat(new char[9]{ 'S', 'C', 'O', 'R', 'E',' ', ':',' ','\0' }, _itoa(player->getScore(), strp, 10)), 0.0f, position + 0.025f, 1.0f, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D(new char[7]{ 'V', 'I', 'E',' ', ':',' ','\0' }, 0.55f, position + 0.025f, 1.0f, 1.0f, 1.0f, 1.0f);
	for (int i = 0; i < player->getLife(); i++) {
		if (i > 5) {
			GraphicPrimitives::drawFillRect2D(0.68f + (0.03*i), position + 0.023, 0.02, 0.05, 0.0, 1.0, 0.0, 1.0);
		}
		else if (i > 3) {
			GraphicPrimitives::drawFillRect2D(0.68f + (0.03*i), position + 0.023, 0.02, 0.05, 1.0, 1.0, 0.0, 1.0);
		}
		else if (i > 1) {
			GraphicPrimitives::drawFillRect2D(0.68f + (0.03*i), position + 0.023, 0.02, 0.05, 1.0, 0.5, 0.0, 1.0);
		}
		else {
			GraphicPrimitives::drawFillRect2D(0.68f + (0.03*i), position + 0.023, 0.02, 0.05, 1.0, 0.0, 0.0, 1.0);
		}
	}
}

void hud::vague(int i) {
	float posY = 1.0 - ((1 * 0.155f) + (0.155f / 2.0)) - 0.07;
	if (i >= 100) {
		GraphicPrimitives::drawText2D(new char[2]{'X', '\0' }, 0 - 1.0 + (6 * 0.155f) + 0.0627, posY, 1.0f, 1.0f, 1.0f, 1.0f);
	}
	else {
		int j = 1;
		int k = i;
		while (k > 0) {
			GraphicPrimitives::drawText2D(strcat(new char[1]{ '\0' }, _itoa(k % 10, new char[1], 10)), 0 - 1.0 + ((6 + j) * 0.155f) + 0.0627, posY, 1.0f, 1.0f, 1.0f, 1.0f);
			j--;
			k = k / 10;
		}
	}

	GraphicPrimitives::drawText2D(new char[2]{ 'V','\0' },-1.0 + (0 * 0.155f) + 0.0627, posY, 1.0f, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D(new char[2]{ 'A','\0' }, -1.0 + (1 * 0.155f) + 0.0627, posY, 1.0f, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D(new char[2]{ 'G' ,'\0' }, -1.0 + (2 * 0.155f) + 0.0627, posY, 1.0f, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D(new char[2]{ 'U','\0' }, -1.0 + (3 * 0.155f) + 0.0627, posY, 1.0f, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D(new char[2]{ 'E','\0' }, 0 - 1.0 + (4 * 0.155f) + 0.0627, posY, 1.0f, 1.0f, 1.0f, 1.0f);
}