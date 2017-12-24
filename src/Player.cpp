#include "Player.h"

void Player::addGold(int i) {
	gold += i;
}


void Player::addScore(int i) {
	score += i;
}

void Player::buyGold(int i) {
	gold -= i;
}

void Player::setGold(int i) {
	gold = i;
}

void Player::hit() {
	life--;
}

void Player::addLife() {
	life++;
}

int Player::getGold() {
	return gold;
}

int Player::getScore() {
	return score;
}

int Player::getLife() {
	return life;
}