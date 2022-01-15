#pragma once

#include"headers\\Creature.h"
#include"headers\\Card.h"
#include"headers\\Clickable.h"
#include"headers\\Player.h"

extern int MAX_ENTITY;
const int TAKE_DAMAGE_ANIMATION = 1000;

#define block

//constructs block
#ifdef block
Creature::Creature() { }
Creature::Creature(
	string name,
	int cost,
	string type,
	vector<Func> funcs,
	string description,
	int damage,
	int health,
	string picPath,
	int id
) : Creature(name, cost, type, description, damage, health, picPath, id) {
	this->funcs = funcs;
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
bool Creature::getIsInitiator() {
	return isInitiator;
}
void Creature::setIsCard(bool isCard) {
	this->isCard = isCard;
}
void Creature::setHealth(int health) {
	this->health = health;
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
void Creature::viewAsEntity(float time, sf::Vector2f pos, Clickable* initiator) {
	this->pos = pos;


	hitbox = sf::RectangleShape(sf::Vector2f(160, 160));
	hitbox.setPosition(pos);
	hitbox.setTexture(&Tpic);
	hitbox.setOutlineThickness(6);
	if(this!=initiator)
			hitbox.setOutlineColor(sf::Color(145, 145, 145, 100));
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

	Ttakendmg.setFont(font);
	Ttakendmg.setCharacterSize(25);
	Ttakendmg.setPosition(sf::Vector2f(pos.x + 80, pos.y + 80));
	Ttakendmg.setOutlineColor(sf::Color::White);
	Ttakendmg.setOutlineThickness(15);

	if (isDrawingEffect) {
		animationTimer += time;
		if (animationTimer >= TAKE_DAMAGE_ANIMATION) {
			animationTimer = 0;
			isDrawingEffect = false;
		}
	}
	else animationTimer = 0;

	DrawType = 3;
}
void Creature::drawCard(sf::RenderWindow& window, int DrawType) {
	if (DrawType != -1)this->DrawType = DrawType;
	else DrawType = this->DrawType;
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
		if(isDrawingEffect)
			window.draw(Ttakendmg);
	}
}

//activity
void Creature::use(Clickable* target, Player* player, Field* field, bool isFree) {
	if (isCard) {
		if ((player->getCurMana() >= cost || isFree) && player->getEntities().size() < MAX_ENTITY) {

			if(!isFree)
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
			targets = vector<int>{ 1,6 };
		}

	}
	else {
		attack(target);
	}
}

void Creature::attack(Clickable* target) {
	isInitiator = false;
	target->acceptAttack(this->damage);
	this->acceptAttack(target->getDamage());
}
void Creature::acceptAttack(int damage){
	if (!isCard) {
		this->health -= damage;
		isDrawingEffect = true;
		Ttakendmg.setString("");
		if (damage > 0) {
			Ttakendmg.setFillColor(sf::Color::Red);
			Ttakendmg.setString("-" + to_string(abs(damage)));
		}
		else if (damage < 0) {
			Ttakendmg.setFillColor(sf::Color::Green);
			Ttakendmg.setString("+" + to_string(abs(damage)));
		}
	}
}

void Creature::step() {
	isInitiator = true;
}

