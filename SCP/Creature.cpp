#pragma once

#include"Creature.h"
#include"Card.h"
#include"Clickable.h"
#include"Player.h"

extern int MAX_ENTITY;

#define block

//constructs block
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
void Creature::copy(Card* card) {
	Card::copy(card);
	this->damage = card->getDamage();
	this->health = card->getHealth();
}
#endif

Creature::~Creature() {}

//getters
int Creature::getDamage() {
	return damage;
}
int Creature::getHealth() {
	return health;
}

//viewing
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
void Creature::viewAsEntity(sf::Vector2f pos, Clickable* initiator) {
	this->pos = pos;


	hitbox = sf::RectangleShape(sf::Vector2f(160, 160));
	hitbox.setPosition(pos);
	hitbox.setTexture(&Tpic);
	hitbox.setOutlineThickness(6);
	if(this!=initiator)hitbox.setOutlineColor(sf::Color(145, 145, 145, 100));
	else hitbox.setOutlineColor(sf::Color::Yellow);

	/*
	Scost = sf::Sprite(Tvalue);
	Scost.setScale(0.5,0.5);
	Scost.setPosition(pos);

	Tcost.setFont(font);
	Tcost.setString(to_string(cost));
	Tcost.setCharacterSize(25);
	Tcost.setPosition(sf::Vector2f(pos.x+5, pos.y));
	Tcost.setFillColor(sf::Color::Blue);
	*/

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
void Creature::drawCard(sf::RenderWindow& window, int DrawType) {
	Card::drawCard(window, DrawType);
	if (DrawType == 0) {
		window.draw(Sdamage);
		window.draw(Tdamage);
		window.draw(Shealth);
		window.draw(Thealth);
	}
	else if (DrawType == 3) {
		hitbox.setFillColor(sf::Color::White);
		/*
		window.draw(Scost);
		window.draw(Tcost);
		*/
		window.draw(hitbox);
		window.draw(Sdamage);
		window.draw(Tdamage);
		window.draw(Shealth);
		window.draw(Thealth);
	}
}

//activity
void Creature::use(Clickable* target, Player* player) {
	if (isCard/* && typeid(*target).name() == "class Field"*/) {
		if (player->getCurMana() >= cost) {
			player->minusCurMana(cost);
			//summoning creature for our player
			player->summonCreature(this);

			//removing card from hand
			vector<Card*>& cards = player->getDeck()->getHand();
			int size = cards.size();
			for (int i = 0; i < size; i++) {
				if (cards[i] == this) {
					cards.erase(cards.begin() + i);
					break;
				}
			}
			isCard = false;
			isTargetable = true;
			targets = vector<int>{ 1/*,6*/ };
		}
	}
	else {
		attack(target);
	}
}

void Creature::attack(Clickable* target) {
	//if (/*typeid(*target).name() == "class Creature"*/) {
	target->acceptAttack(this->damage);
	this->health -= target->getDamage();
	//}
	/* function for character
	else if (typeid(*target).name() == "class Character") {
		target->acceptAttack(this->damage);
	}
	*/
}
void Creature::acceptAttack(int damage){
	//if(!isCard)
	this->health -= damage;
}