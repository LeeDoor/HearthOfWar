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
	void add // creating !!!PEOPLE!!!
		(
	string name, 
	int cost,
	string fraction,
	vector<string> feature,
	vector<string> funcFeat,
	string description,
	int damage, 
	int health ) {
		People* buff = new People { name,cost,fraction, feature,funcFeat,description,damage,health,size++ };
		cards.push_back(buff);
	}

	void add 
	(
		string name,
		int cost,
		string fraction,
		string description,
		int damage,
		int health
	) {
		People* buff = new People{ name,cost,fraction,description,damage,health,size++ };
		cards.push_back(buff);
	}


	void add // creating !!!MILLITARY FORCE!!!
	(
		string name, int cost,
		string fraction,
		vector<string> feature,
		vector<string> funcFeat,
		string description) {

		MilFor* buff = new MilFor { name,cost,fraction, feature,funcFeat,description,size++ };
		cards.push_back(buff);
	}
	void add
	(
		string name, int cost,
		string fraction,
		string description) {

		MilFor* buff = new MilFor{ name,cost,fraction,description,size++ };
		cards.push_back(buff);
	}
#endif 

// special functions for cards
#ifdef block

#endif

	void viewAll() {
		for (int i = 0; i < size; i++) {
			cards[i]->view() ;
		}
	}


	void addAll() { // here i am adding all cards to the game
		add("citizen", 3, "", "just a citizen", 3, 1);
		add("pioneer camp counselor", 5, "Russia", "", 6, 3);
	}
};

