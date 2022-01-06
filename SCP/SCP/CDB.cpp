#pragma once
#define block
#include"CDB.h"
#include"Creature.h"
#include"Event.h"
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
	vector<string> feature,
	vector<string> funcFeat,
	string description,
	int damage,
	int health,
	string picPath) {
	Creature* buff = new Creature{ name,cost,fraction, feature,funcFeat,description,damage,health,picPath,size++ };
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
	vector<string> feature,
	vector<string> funcFeat,
	string description,
	string picPath
) {

	Event* buff = new Event{ name,cost,fraction, feature,funcFeat,description,picPath,size++ };
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

#endif
void CDB::addAll() { // here i am adding all cards to the game
	add("Skin Wyrm", 3, "Safe", "1545461", 4, 4, "pic\\021.png");
	add("Egg Timer of Deja Vu", 2, "Euclid", "1231231", 2, 2, "pic\\292.png");
	add("Some spell", 5, "Keter", "some fucking event", "pic\\006.jpg");
}
