#pragma once

#include"headers\\Event.h"
#include"headers\\Card.h"
#include"headers\\Clickable.h"
#include"headers\\Player.h"
Event::Event() {
	targets = vector<int>{1,6};
}

Event::Event(
	string name,
	int cost,
	string type,
	vector<Func>funcs,
	vector<int> targets,
	int damage,
	string description,
	string picPath,
	int id)
{
	this->name = name;
	this->cost = cost;
	this->type = type;
	this->funcs = funcs;
	this->damage = damage;
	this->description = description;
	this->id = id;
	this->picPath = picPath;
	this->gameClass = "Event";
	setTexture();
	this->targets = targets;
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
	targets = vector<int>{ 1,6 };
}

int Event::getDamage() {
	return damage;
}

void Event::copy(Card* card) {
	this->damage = card->getDamage();
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



void Event::use(Clickable* target, Player* player, Field* field) {
	selfFunc(target, field,"battlecry");
	cout << "event attack ";
	vector<Card*>& cards = player->getDeck()->getHand();
	int size = cards.size();
	for (int i = 0; i < size; i++) {
		if (cards[i] == this) {
			cards.erase(cards.begin() + i);
			break;
		}
	}

}

void Event::selfFunc(Clickable* target, Field* field, string type) {
	int size = funcs.size();
	for (int i = 0; i < size; i++) {
		if (funcs[i].feature == type || type == "") {
			funcs[i].func(target, field, this->damage);
		}
	}
}