#pragma once

#include"headers\\Player.h"


extern int MAX_ENTITY;
Player::Player(Deck* deck) {
	this->deck = deck;
}

Deck* Player::getDeck() {
	return deck;
}

Person* Player::getPerson() {
	return person;
}
bool Player::getIsFirst() {
	return isFirst;
}


void Player::startGame(bool isFirst) {
	this->isFirst = isFirst;
	deck->startGame(isFirst);
	person = new Person(isFirst);
	person->prepare();
	mana = 1;
	curMana = mana;

	entities.clear();
}
bool Player::step(bool isFirst) {
	if(mana<=9)
		mana++;
	curMana = mana;
	deck->takeCard(isFirst);

	int size = getEntities().size();
	for (int i = 0; i < size; i++) {
		getEntities()[i]->step();
	}

	return (true);
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


