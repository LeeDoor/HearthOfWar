#pragma once
#include "includer.h"
class Player;


class Clickable
{
protected:
	bool isTargetable; // can it be a target
	bool isInitiator; // can this thing be an initiator (attacker)]
	sf::RectangleShape hitbox;

public:
	bool getIsTargetable();
	bool getIsInitiator();
	virtual int getDamage();// here we dont use it, it needs for creature and player
	virtual int getHealth();

	virtual void use(Clickable* target, Player* player); // func to use card/entity
	virtual void acceptAttack(int damage); // func for taking damage

	bool isMovedOn();
};

