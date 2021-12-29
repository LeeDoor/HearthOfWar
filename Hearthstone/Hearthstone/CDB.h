#pragma once
#define block

class CDB
{
private:
	vector<Card*> cards;
	int size;
public:
	CDB() {
		addAll();
	}

	vector<Card*> getCards() {
		return cards;
	}

	Card* getCard(int id) {
		if (id >= cards.size()) return 0;
		return cards[id];
	}
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
	string picPath) {
		Creature* buff = new Creature{ name,cost,fraction, feature,funcFeat,description,damage,health,picPath,size++ };
		cards.push_back(buff);
	}

	void add 
	(
		string name,
		int cost,
		string fraction,
		string description,
		int damage,
		int health,
		string picPath
	) {
		Creature* buff = new Creature{ name,cost,fraction,description,damage,health,picPath,size++ };
		cards.push_back(buff);
	}


	void add // creating !!!Event!!!
	(
		string name,
		int cost,
		string fraction,
		vector<string> feature,
		vector<string> funcFeat,
		string description
	) {

		Event* buff = new Event{ name,cost,fraction, feature,funcFeat,description,size++ };
		cards.push_back(buff);
	}
	void add
	(
		string name, int cost,
		string fraction,
		string description) {

		Event* buff = new Event{ name,cost,fraction,description,size++ };
		cards.push_back(buff);
	}
#endif 

// special functions for cards
#ifdef block

#endif



	void addAll() { // here i am adding all cards to the game
		add("Skin Wyrm",			 3, "Safe",		"", 4, 4,	"pic\\021.png");
		add("Egg Timer of Deja Vu",	 2, "Euclid",   "", 2, 2,	"pic\\292.png");
	}
};

