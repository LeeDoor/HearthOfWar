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
		buff->use(target,player,field,true);
	}
}
void SummonCreatures019(Clickable* target, Field* field, int cdbid) {
	Player* player;
	Creature* buff;
	player = field->getCurPlayer();

	buff = new Creature;
	buff->copy(field->getDeck(true)->getCDB()->getCard(5));
	buff->use(target, player, field, true);
	for (int i = 0; i < 2; i++) {
		buff = new Creature;
		buff->copy(field->getDeck(true)->getCDB()->getCard(cdbid));
		buff->use(target, player, field, true);
	}
}
void SetEnemyHealth(Clickable* target, Field* field, int damage) {
	Player* player;
	Creature* buff;
	player = field->getOtherPlayer();
	int size = player->getEntities().size();
	for (int i = 0; i < size; i++) {
		player->getEntities()[i]->acceptAttack(player->getEntities()[i]->getHealth() - damage);
	}
}
#endif
void CDB::addAll() { // here i am adding all cards to the game
	/*0*/add("the Door", 4, "Euclid", "", 2, 6, "pic\\004.png");
	/*1*/add("Fountain of Youth", 2, "Safe", vector<Func>{Func{ "battlecry",Damage }}, vector<int>{0},-6, "restores 6 health to an\nally creature", "pic\\006.png");
	/*2*/add("Zombie Plague", 2, "Euclid", vector<Func>{Func{ "battlecry",SetEnemyHealth }}, vector<int>{4},1, "sets enemy's creatures's health to 1", "pic\\008.png");
	/*3*/add("Sentient Micro-Organism", 2, "Keter", vector<Func>{Func{ "battlecry",Destroy }}, vector<int>{1},0, "kills enemy's creature", "pic\\008.png");
	/*4*/add("small vaguely humanoid", 8, "Keter", vector<Func>{Func{ "battlecry",SummonCreatures019 }}, vector<int>{4}, 6, "summons vase 1-8 and 2 dogs 2-2", "pic\\019.png");
	/*5*/add("the Vase", 4, "Keter", "", 1, 8, "pic\\019.png");
	/*6*/add("small vaguely humanoid", 1, "Keter", "", 2, 2, "pic\\019-2.png");
	/*7*/add("Skin Wyrm", 3, "Safe", "", 4, 4, "pic\\021.png");
	/*8*/add("Egg Timer of Deja vu", 2, "Euclid", "", 2, 3, "pic\\292.png");
	/*9*/add("Black Shuck", 5, "Euclid", "", 6, 4, "pic\\023.png");
	/*10*/add("Young Girl", 3, "Euclid", "", 5, 1, "pic\\053.png");

}

