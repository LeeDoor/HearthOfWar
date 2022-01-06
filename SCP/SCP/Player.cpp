#pragma once

#include"Player.h"

Player::Player(Deck* deck) {
	this->deck = deck;
}
void Player::startGame(bool isFirst) {
	deck->startGame(isFirst);
	mana = 0;
}
bool Player::step(bool isFirst) {
	mana++;
	curMana = mana;
	deck->takeCard(isFirst);
	return (true);
}
Deck* Player::getDeck() {
	return deck;
}
vector<Creature*> Player::getEntities() {
	return entities;
}
int Player::getCurMana() {
	return curMana;
}


void Player::summonCreature(Creature* creature) {
	entities.push_back(creature);
}


