#pragma once

#include"Event.h"
#include"Card.h"
Event::Event() {}

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
}

Event::Event(
	string name,
	int cost,
	string type,
	string description,
	string picPath,
	int id )
{
	this->name = name;
	this->cost = cost;
	this->type = type;
	this->description = description;
	this->id = id;
	this->picPath = picPath;
	this->gameClass = "Event";
}

void Event::copy(Card* card) {
	Card::copy(card);
}
void Event::use() {
	cout << name << " used!\n";
}

void Event::viewBig(sf::Vector2f pos) {
	Card::viewBig(pos);
}
void Event::viewLow(sf::Vector2f pos) {
	Card::viewLow(pos);
}
void Event::drawCard(sf::RenderWindow& window) {
	Card::drawCard(window);

}


