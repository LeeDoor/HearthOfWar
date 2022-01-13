#pragma once

#include"includer.h"
#include"Card.h"
//#include"CDB.h"
class CDB;
class Deck
{
private:
	vector<Card*> deck;
	vector<Card*> left;
	vector<Card*> hand;
	CDB* curDB;


	void fillHand(bool isFirst);


	void addCard(int id);
	
	void addLeft(int id);

public:
	Card* operator[](int id);

	Deck(CDB* cdb);
	CDB* getCDB();
	vector<Card*> getDeck();
	vector<Card*> getLeft();
	vector<Card*>& getHand();

	void takeCard(bool isFirst);
	void createDeck();
	void clear();
	void startGame(bool isFirst);
};

