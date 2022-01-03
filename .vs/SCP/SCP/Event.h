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
		vector<string> feature,
		vector<string> funcFeat,
		string description,
		string picPath,
		int id = -1);

	Event(
		string name,
		int cost,
		string type,
		string description,
		string picPath,
		int id = -1);

	void copy(Card* card);
	void use();

	void viewBig(sf::Vector2f pos);
	void viewLow(sf::Vector2f pos);
	void drawCard(sf::RenderWindow& window);
};

