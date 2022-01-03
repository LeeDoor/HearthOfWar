#pragma once
#define block

#include"includer.h"
#include"Card.h"
class CDB
{
private:
	vector<Card*> cards;
	int size;
public:
	CDB();

	vector<Card*> getCards();
	Card* getCard(int id);
	int getSize();


	// "add" functions for adding cards to a data base
#ifdef block
	void add // creating !!!Creature!!!
	(
		string name,
		int cost,
		string fraction,
		vector<string> feature,
		vector<string> funcFeat,
		string description,
		int damage,
		int health,
		string picPath);

	void add
	(
		string name,
		int cost,
		string fraction,
		string description,
		int damage,
		int health,
		string picPath
	);


	void add // creating !!!Event!!!
	(
		string name,
		int cost,
		string fraction,
		vector<string> feature,
		vector<string> funcFeat,
		string description,
		string picPath
	);
	void add
	(
		string name,
		int cost,
		string fraction,
		string description,
		string picPath);
#endif 

	// special functions for cards
#ifdef block

#endif
	void addAll();
};

