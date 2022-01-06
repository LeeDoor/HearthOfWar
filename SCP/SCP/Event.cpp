#pragma once

#include"Event.h"
#include"Card.h"
Event::Event() {
	
}

Event::Event(
	string name,
	int cost,
	string type,
	vector<string> feature,
	vector<string> funcFeat,
	string description,
	string picPath,
	int id)
{
	this->name = name;
	this->cost = cost;
	this->type = type;
	this->feature = feature;
	this->funcFeat = funcFeat;
	this->description = description;
	this->id = id;
	this->picPath = picPath;
	this->gameClass = "Event";

	setTexture();
}

Event::Event(
	string name,
	int cost,
	string type,
	string description,
	string picPath,
	int id)
{
	this->name = name;
	this->cost = cost;
	this->type = type;
	this->description = description;
	this->id = id;
	this->picPath = picPath;
	this->gameClass = "Event";
	setTexture();
}

void Event::copy(Card* card) {
	Card::copy(card);
}
void Event::use() {
	cout << name << " used!\n";
}

void Event::viewBig() {
	Card::viewBig();
}
void Event::viewLow() {
	Card::viewLow();
}
void Event::drawCard(sf::RenderWindow& window) {
	Card::drawCard(window);

}


