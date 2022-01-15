
#include"includer.h"
#include"Deck.h"
#include"Creature.h"
#include"Person.h"
#pragma once

class Player
{
private:
	Person* person;
	Deck* deck;
	vector<Creature*> entities;


	int mana = 0;
	int curMana = mana;

	bool isFirst = false;
public:
	Player() {}
	Player(Deck* deck);


	Deck* getDeck();
	Person* getPerson();
	bool getIsFirst();

	void startGame(bool isFirst);
	
	bool step(bool isFirst);
	vector<Creature*>& getEntities();
	int getCurMana();
	void minusCurMana(int cost);

	void summonCreature(Creature* creature);
};

