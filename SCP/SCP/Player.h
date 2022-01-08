
#include"includer.h"
#include"Deck.h"
#include"Creature.h"
#pragma once

class Player
{
private:
	//Person* person
	Deck* deck;
	vector<Creature*> entities;

	int mana;
	int curMana;
public:
	Player() {}
	Player(Deck* deck);
	void startGame(bool isFirst);
	
	bool step(bool isFirst);
	Deck* getDeck();
	vector<Creature*>& getEntities();
	int getCurMana();

	void summonCreature(Creature* creature);
};

