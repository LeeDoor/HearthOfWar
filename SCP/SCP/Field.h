#pragma once
class Player;
#include"includer.h"
class Field
{
private:
	Player* firstP;
	Player* secondP;

	bool isFirst = false;
	bool isStarted = false;
	float stepTime = 0;
public:
	Field(Player* secondP, Player* firstP);

	void useCheck();
	void startGame();
	bool nextTurn();
	void draw(sf::RenderWindow& window, float time, sf::Event& event);

	bool getIsStarted();
};

