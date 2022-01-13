#pragma once
#define block
#include"headers\\CDB.h"
#include"headers\\Creature.h"
#include"headers\\Event.h"
#include"headers\\Player.h"
CDB::CDB() {
	addAll();

}

vector<Card*> CDB::getCards() {
	return cards;
}
Card* CDB::getCard(int id) {
	if (id >= cards.size()) return 0;
	return cards[id];
}
int CDB::getSize() {
	return cards.size();
}


// "add" functions for adding cards to a data base
#ifdef block
void CDB::add // creating !!!Creature!!!
(
	string name,
	int cost,
	string fraction,
	vector<Func> funcs,
	string description,
	int damage,
	int health,
	string picPath) {
	Creature* buff = new Creature{ name,cost,fraction, funcs,description,damage,health,picPath,size++ };
	cards.push_back(buff);
}

void CDB::add
(
	string name,
	int cost,
	string fraction,
	string description,
	int damage,
	int health,
	string picPath
) {
	Creature* buff = new Creature{ name,cost,fraction,description,damage,health,picPath,size++ };
	cards.push_back(buff);
}


void CDB::add // creating !!!Event!!!
(
	string name,
	int cost,
	string fraction,
	vector<Func>funcs,
	vector<int> targets,
	int damage,
	string description,
	string picPath
) {

	Event* buff = new Event{ name,cost,fraction, funcs,targets,damage, description,picPath,size++ };
	cards.push_back(buff);
}
void CDB::add
(
	string name,
	int cost,
	string fraction,
	string description,
	string picPath) {

	Event* buff = new Event{ name,cost,fraction,description,picPath,size++ };
	cards.push_back(buff);
}
#endif 

// special functions for cards
#ifdef block
void Damage(Clickable* target, Field* field, int damage) {
	target->acceptAttack(damage);
}

void Destroy(Clickable* target, Field* field, int damage) {

	target->acceptAttack(target->getHealth());
}

void SummonCreature(Clickable* target, Field* field, int cdbid) {
	Player* player;
	Creature* buff;
	player = field->getCurPlayer();
	for (int i = 0; i < 3; i++) {
		buff = new Creature;
		buff->copy(field->getDeck(true)->getCDB()->getCard(cdbid));
		player->summonCreature(buff);
	}
}

void TotalKill(Clickable* target, Field* field, int cdbid) {
	Player* player;
	Creature* buff;
	player = field->getCurPlayer();
	for (int i = 0; i < 3; i++) {
		buff = new Creature;
		buff->copy(field->getDeck(true)->getCDB()->getCard(cdbid));
		player->summonCreature(buff);
	}
}
#endif
void CDB::addAll() { // here i am adding all cards to the game
	/*0*/add("Skin Wyrm", 3, "Safe", "wooooo", 4, 4, "pic\\021.png");
	/*1*/add("Doggie", 1, "Euclid", "rrrr", 1, 1, "pic\\019-2.jpg");
	/*2*/add("Egg Timer of Deja Vu", 2, "Euclid", "shhh", 2, 2, "pic\\292.png");
	/*3*/add("Some spell", 3, "Keter", vector<Func>{Func{ "battlecry",Destroy }}, vector<int>{1,6},3, "i am event", "pic\\006.jpg");
	/*4*/add("HEALER", 2, "Safe", vector<Func>{Func{ "battlecry",SummonCreature }}, vector<int>{4},1, "i am second event", "pic\\016.jpg");
}

