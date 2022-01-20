#pragma once

#include"includer.h"
#include"Card.h"

#define block
class Creature :public Card
{
private:
	bool isCard = true; // is it a card or an entity
	bool isDrawingEffect = false;

	sf::Text Tdamage;
	sf::Text Thealth;
	sf::Sprite Sdamage;
	sf::Sprite Shealth;

	sf::Text Ttakendmg;

	
public:
	// constructor
#ifdef block
	Creature();
	Creature(
		string name,
		int cost,
		string type,
		vector<Func> funcs,
		string description,
		int damage,
		int health,
		string picPath,
		int id = -1
	) ;

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

	void setIsCard(bool isCard);
	void setHealth(int health);
	bool getIsInitiator();

	void viewAsEntity(float time, sf::Vector2f pos, Clickable* initiator);

	void drawCard(sf::RenderWindow& window, int DrawType = -1);

	void use(Clickable* target, Player* player, Field* field,bool isFree = false);
	void attack(Clickable* target);
	void acceptAttack(int damage);
	void step();

};

