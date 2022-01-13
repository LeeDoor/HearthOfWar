#pragma once
#include "includer.h"
class Player;
class Field;

class Clickable
{
protected:
	bool isTargetable; // can it be a target
	bool isInitiator; // can this thing be an initiator (attacker)]
	sf::RectangleShape hitbox; 
	
	vector<int> targets; // need to accepting attack to other objects
	//0/1 -- curr/enem entities
	//2/3 -- curr/enem hands
	//4 - field
	////5/6 -- curr/enem heroes

public:
	bool getIsTargetable();
	bool getIsInitiator();
	virtual int getDamage();// here we dont use it, it needs for creature and player
	virtual int getHealth();
	vector<int> getTargets();

	virtual void use(Clickable* target, Player* player, Field* field); // func to use card/entity
	virtual void acceptAttack(int damage); // func for taking damage

	bool isMovedOn();
};

