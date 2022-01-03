#pragma once

#include"Player.h"

Player::Player(Deck* deck) {
	this->deck = deck;
}
void Player::startGame(bool isFirst) {
	deck->startGame(isFirst);
	mana = 0;
}
void Player::viewField() {
	//enter smth here
}
bool Player::step() {
	mana++;
	curMana = mana;
	return (false);
}
Deck* Player::getDeck() {
	return deck;
}
/*
vector<Entity*> Player::getEntities() {
	return entities;
}
*/
int Player::getCurMana() {
	return curMana;
}



