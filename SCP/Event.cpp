#pragma once

#include"headers\\Event.h"
#include"headers\\Card.h"
#include"headers\\Clickable.h"
#include"headers\\Player.h"
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

void Event::viewBig() {
	Card::viewBig();
}
void Event::viewLow() {
	Card::viewLow();
}
void Event::drawCard(sf::RenderWindow& window) {
	Card::drawCard(window);

}



void Event::use(Clickable* target, Player* player) {
	//here we need to write an algoritm to find targetable classes 
	if (true/*typeid(*target).name() == "class Field"*/) {
		// special event function

		//removing card from hand
		vector<Card*> cards = player->getDeck()->getHand();
		int size = cards.size();
		for (int i = 0; i < size; i++) {
			if (cards[i] == this) {
				cards.erase(cards.begin() + i);
				break;
			}
		}
	}
}

