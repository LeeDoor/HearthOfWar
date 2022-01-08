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

	Clickable* useCheck(sf::Event event);
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

