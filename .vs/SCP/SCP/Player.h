
#include"includer.h"
#include"Deck.h"
#pragma once

class Player
{
private:
	//Person* person
	Deck* deck;
	//vector<Entity*> entities;

	int mana;
	int curMana;
public:
	Player() {}
	Player(Deck* deck);
	void startGame(bool isFirst);
	void viewField();
	bool step();
	Deck* getDeck();
	//vector<Entity*> getEntities();
	int getCurMana();

};

