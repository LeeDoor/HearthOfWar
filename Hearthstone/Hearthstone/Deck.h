#pragma once
class Deck
{
private:
	vector<Card*> deck;
	CDB* curDB;
	const int deckSize = 10;

public:
	Card* operator[](int id) {
		return deck[id];
	}

	Deck(CDB* cdb) {
		curDB = cdb;
		createDeck();
	}

	void createDeck() {
		clear();

		curDB->viewAll();
		int a;
		cout << "\nenter 10 ids of cards you want to add to your deck: ";
		for (int i = 0; i < deckSize; i++) {
			while (true) {
				cout << i + 1 << " : ";
				cin >> a;
				if (curDB->getCard(a) != 0) {
					deck.push_back(curDB->getCard(a));
					break;
				}

			}

		}

		cout << "\nnow your deck is:\n";
		viewDeck();
	}

	void clear() {
		while (deck.size() > 0)deck.pop_back();
	}

	void addCard(int id) {
		deck.push_back(curDB->getCard(id));
	}

	void viewDeck() {
		for (int i = 0; i < deck.size(); i++) {
			 deck[i]->view();
		}
	}
};

