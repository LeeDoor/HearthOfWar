#pragma once
#include"includer.h"
#include"Player.h"
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
	//Clickable* useCheckHeroes(bool isFirst);

	void startGame();
	bool nextTurn();
	void draw(sf::RenderWindow& window, float time, Clickable* initiator);

	bool getIsStarted();
	Player* getCurPlayer();

	void deathCheck(Player* player);
	void deathCheck();

	//void chooseClear();
	Creature* checkCreature(Player* player);
	Card* checkCard(Player* player);

	bool isMovedOn();
};

