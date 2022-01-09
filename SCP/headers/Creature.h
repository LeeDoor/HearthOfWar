#pragma once

#include"includer.h"
#include"Card.h"

#define block
class Creature :public Card
{
private:
	int damage; // entity's damage
	int health; // max health
	bool isCard = true; // is it a card or an entity

	sf::Text Tdamage;
	sf::Text Thealth;
	sf::Sprite Sdamage;
	sf::Sprite Shealth;
public:
	// constructor
#ifdef block
	Creature();
	Creature(
		string name,
		int cost,
		string type,
		vector<string> feature,
		vector<string> funcFeat,
		string description,
		int damage,
		int health,
		string picPath,
		int id = -1
	);

	Creature(
		string name,
		int cost,
		string type,
		string description,
		int damage,
		int health,
		string picPath,
		int id = -1
	);



#endif
	~Creature();

	int getDamage();
	int getHealth();

	void copy(Card* card);
 
	void viewBig();
	void viewLow();
	void viewAsEntity(sf::Vector2f pos, Clickable* initiator);

	void drawCard(sf::RenderWindow& window, int DrawType = -1);

	void use(Clickable* target, Player* player);
	void attack(Clickable* target);
	void acceptAttack(int damage);
};

