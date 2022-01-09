#pragma once

#include"headers\\Player.h"


extern int MAX_ENTITY;
Player::Player(Deck* deck) {
	this->deck = deck;
}
void Player::startGame(bool isFirst) {
	deck->startGame(isFirst);
	mana = 0;
	curMana = mana;
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
vector<Creature*> &Player::getEntities() {
	return entities;
}
int Player::getCurMana() {
	return curMana;
}
void Player::minusCurMana(int cost) {
	curMana = curMana -= cost;
}


void Player::summonCreature(Creature* creature) {
	if(entities.size() < MAX_ENTITY)
		entities.push_back(creature);
}


