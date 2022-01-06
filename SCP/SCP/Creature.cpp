#pragma once

#include"Creature.h"
#include"Card.h"
#include"Player.h"

#define block
#ifdef block
Creature::Creature() { }
Creature::Creature(
	string name,
	int cost,
	string type,
	vector<string> feature,
	vector<string> funcFeat,
	string description,
	int damage,
	int health,
	string picPath,
	int id
) {
	this->name = name;
	this->cost = cost;
	this->type = type;
	this->feature = feature;
	this->funcFeat = funcFeat;
	this->description = description;

	this->damage = damage;
	this->health = health;
	this->id = id;
	this->picPath = picPath;
	this->gameClass = "Creature";

	setTexture();
}

Creature::Creature(
	string name,
	int cost,
	string type,
	string description,
	int damage,
	int health,
	string picPath,
	int id
) {
	this->name = name;
	this->cost = cost;
	this->type = type;
	this->description = description;
	this->damage = damage;
	this->health = health;
	this->id = id;
	this->picPath = picPath;

	this->gameClass = "Creature";
	setTexture();
}
#endif

int Creature::getDamage() {
	return damage;
}
int Creature::getHealth() {
	return health;
}

void Creature::copy(Card* card) {
	Card::copy(card);
	this->damage = card->getDamage();
	this->health = card->getHealth();
}

void Creature::viewBig() {
	Card::viewBig();
	Sdamage = sf::Sprite(Tvalue);
	Sdamage.setPosition(sf::Vector2f(pos.x - 12, pos.y + 350));

	Tdamage.setFont(font);
	Tdamage.setString(to_string(damage));
	Tdamage.setCharacterSize(50);
	Tdamage.setPosition(sf::Vector2f(pos.x + 8, pos.y + 350));
	Tdamage.setFillColor(sf::Color::Red);

	Shealth = sf::Sprite(Tvalue);
	Shealth.setPosition(sf::Vector2f(pos.x + 262, pos.y + 350));

	Thealth.setFont(font);
	Thealth.setString(to_string(health));
	Thealth.setCharacterSize(50);
	Thealth.setPosition(sf::Vector2f(pos.x + 282, pos.y + 350));
	Thealth.setFillColor(sf::Color::Green);
}
void Creature::viewLow() {
	Card::viewLow();
}
void Creature::viewAsEntity(sf::Vector2f pos) {
	this->pos = pos;


	hitbox = sf::RectangleShape(sf::Vector2f(160, 160));
	hitbox.setPosition(pos);
	hitbox.setTexture(&Tpic);
	hitbox.setOutlineThickness(6);
	hitbox.setOutlineColor(sf::Color(145, 145, 145, 100));

	Scost = sf::Sprite(Tvalue);
	Scost.setScale(0.5,0.5);
	Scost.setPosition(pos);

	Tcost.setFont(font);
	Tcost.setString(to_string(cost));
	Tcost.setCharacterSize(25);
	Tcost.setPosition(sf::Vector2f(pos.x+5, pos.y));
	Tcost.setFillColor(sf::Color::Blue);

	Sdamage = sf::Sprite(Tvalue);
	Sdamage.setScale(0.5, 0.5);
	Sdamage.setPosition(sf::Vector2f(pos.x, pos.y + 130));

	Tdamage.setFont(font);
	Tdamage.setString(to_string(damage));
	Tdamage.setCharacterSize(25);
	Tdamage.setPosition(sf::Vector2f(pos.x+5, pos.y + 130));
	Tdamage.setFillColor(sf::Color::Red);

	Shealth = sf::Sprite(Tvalue);
	Shealth.setScale(0.5, 0.5);
	Shealth.setPosition(sf::Vector2f(pos.x+130, pos.y + 130));

	Thealth.setFont(font);
	Thealth.setString(to_string(health));
	Thealth.setCharacterSize(25);
	Thealth.setPosition(sf::Vector2f(pos.x + 135, pos.y + 130));
	Thealth.setFillColor(sf::Color::Green);

	DrawType = 3;
}


void Creature::use(Player* currP) {
	cout << "AAAAAAAAAAAAAAA";

	Creature* buff = new Creature;
	buff->copy(this);
	currP->summonCreature(buff);

	vector<Card*>& curDeck = currP->getDeck()->getHand();
	int size = curDeck.size();
	for (int i = 0; i < size; i++) {
		if (curDeck[i]->getId() == this->id) {
			curDeck.erase(curDeck.begin() + i);
			break;
		}
	}
}

void Creature::drawCard(sf::RenderWindow& window, int DrawType) {
	Card::drawCard(window,DrawType);
	if (DrawType == 0) {
		window.draw(Sdamage);
		window.draw(Tdamage);
		window.draw(Shealth);
		window.draw(Thealth);
	}
	else if (DrawType == 3) {
		hitbox.setFillColor(sf::Color::White);
		window.draw(hitbox);
		window.draw(Scost);
		window.draw(Tcost);

		window.draw(Sdamage);
		window.draw(Tdamage);
		window.draw(Shealth);
		window.draw(Thealth);
	}
}