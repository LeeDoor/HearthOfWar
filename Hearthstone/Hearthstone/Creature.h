#pragma once

#include"includer.h"
#include"Card.h"

#define block
class Creature:public Card
{
private:
	int damage; // entity's damage
	int health; // max health

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

	int getDamage();
	int getHealth();

	void copy(Card* card);

	void use(Player* currP);
	void viewBig(sf::Vector2f pos);
	void viewLow(sf::Vector2f pos);
	void drawCard(sf::RenderWindow& window);
};

