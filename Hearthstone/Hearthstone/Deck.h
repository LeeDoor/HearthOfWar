#pragma once
class Deck
{
private:
	vector<Card*> deck;
	vector<Card*> left;
	vector<Card*> hand;
	CDB* curDB;
	const int deckSize = 10;


	void fillHand(bool isFirst) {
		int* takenIDs;
		int size;
		if (isFirst)
			size = 3; // how many cards will be given to a first player
		else
			size = 4; // how many cards will be given to a second player

		takenIDs = new int[size];
		for (int i = 0; i < size; i++) {
			takenIDs[i] = rand() % left.size();

			hand.push_back(left[takenIDs[i]]);
			left.erase(left.begin() + takenIDs[i]);
		}
	}
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
		int size = deck.size();
		for (int i = 0; i < size; i++) {
			 deck[i]->view();
		}
	}

	void viewHand() {
		int size = hand.size();
		for (int i = 0; i < size; i++) {
			hand[i]->view();
		}
	}


	void startGame(bool isFirst) {
		left = deck;
		fillHand(isFirst);
	}

	void useCard(int id) {
		hand[id + 1]->use();
	}

	static void randomFill(int*& mass, int size, int l, int r) {
		if (l > r) swap(l, r);
		for (int i = 0; i < size; i++) {
			mass[i] = rand()%(r-l+1)+l;
		}
	}
};

