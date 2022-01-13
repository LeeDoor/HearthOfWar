#pragma once
#include"includer.h"
#include"Clickable.h"
#include"Deck.h"
class Player;
class Creature;
class Card;
class Field : public Clickable
{
private:
	Player* firstP;
	Player* secondP;

	

	bool isFirst = false; // is first playing now
	bool isStarted = false; // is game started
	
	float stepTime = 0;

	
public:
	Field(Player* secondP, Player* firstP);

	Clickable* useCheck(vector<int>targets);
	Clickable* useCheckEntities(bool isFirst);
	Clickable* useCheckHands(bool isFirst);
	Clickable* useCheckField();
	Clickable* useCheckPerson(bool isFirst);

	void startGame();
	bool nextTurn();
	void draw(sf::RenderWindow& window, float time, Clickable* initiator = nullptr);

	bool getIsStarted();
	Player* getCurPlayer();
	Deck* getDeck(bool isFirst);

	bool deathCheck(Player* player);
	Player* deathCheck();

	//void chooseClear();
	Creature* checkCreature(Player* player);
	Card* checkCard(Player* player);

	bool isMovedOn();
};

