#pragma once
#define block

class CDB
{
private:
	vector<Card> cards;
	int size;
public:
	CDB() {
		addAll();
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
		People buff = { name,cost,fraction, feature,funcFeat,description,damage,health,size++ };
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
		People buff = { name,cost,fraction,description,damage,health,size++ };
		cards.push_back(buff);
	}


	void add // creating !!!MILLITARY FORCE!!!
	(
		string name, int cost,
		string fraction,
		vector<string> feature,
		vector<string> funcFeat,
		string description) {

		MilFor buff = { name,cost,fraction, feature,funcFeat,description,size++ };
		cards.push_back(buff);
	}
	void add
	(
		string name, int cost,
		string fraction,
		string description) {

		MilFor buff = { name,cost,fraction,description,size++ };
		cards.push_back(buff);
	}
#endif 

// special functions for cards
#ifdef block

#endif

	void addAll() {
		add("russian citizen", 3, "Russia", "", 3, 1);
	}

	void viewAll() {
		/*for (auto it = cards.begin(); it != cards.end(); it++) {
			
		}*/

		for (int i = 0; i < size; i++) {
			cout << cards[i].doc();
		}
	}
};

