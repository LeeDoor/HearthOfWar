#pragma once

#include"includer.h"
#include"Card.h"

class Event :public Card
{
public:
	Event();

	Event(
		string name,
		int cost,
		string type,
		vector<Func>funcs,
		vector<int> targets,
		int damage,
		string description,
		string picPath,
		int id);

	Event(
		string name,
		int cost,
		string type,
		string description,
		string picPath,
		int id = -1);

	int getDamage();

	void copy(Card* card);
	void use(Clickable* target, Player* player, Field* field);

	void viewBig();
	void viewLow();
	void drawCard(sf::RenderWindow& window); 

	void selfFunc(Clickable* target, Field* field, string type);
};

