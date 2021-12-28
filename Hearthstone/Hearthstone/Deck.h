#pragma once
class Deck
{
private:
	vector<Card*> deck;
	vector<Card*> left;
	vector<Card*> hand;
	CDB* curDB;
	const int DECK_SIZE = 10;


	void fillHand(bool isFirst) {
		int size;
		if (isFirst)
			size = 3; // how many cards will be given to a first player
		else
			size = 4; // how many cards will be given to a second player


		for (int i = 0; i < size; i++) {
			takeCard();
		}
	}


	void addCard(int id) { // adds card to deck
		deck.push_back(curDB->getCard(id));
	}

public:
	Card* operator[](int id) {
		return deck[id];
	}

	Deck(CDB* cdb, sf::RenderWindow& window) {
		curDB = cdb;
		createDeck(window);
	}

	vector<Card*> getDeck() {
		return deck;
	}
	vector<Card*> getLeft() {
		return left;
	}
	vector<Card*> getHand() {
		return hand;
	}


	void createDeck(sf::RenderWindow& window) {
		clear();

		int a;
		for (int i = 0; i < DECK_SIZE; i++) {
			while (true) {
				cout << i + 1 << " : ";
				a = rand()%2;
				if (curDB->getCard(a) != 0) {
					deck.push_back(new Card(curDB->getCard(a)));
					break;
				}

			}

		}
	}
	void clear() {
		while (deck.size() > 0)deck.pop_back();
	}
	void startGame(bool isFirst) {
		int size = deck.size();
		for (int i = 0; i < size; i++) {
			left.push_back(new Card(deck[i]));
		}
		fillHand(isFirst);
	}


	void takeCard() {
		if (left.size() >= 1) {
			hand.push_back(left[left.size() - 1]);
			left.pop_back();
		}
	}

	static void randomFill(int*& mass, int size, int l, int r) {
		if (l > r) swap(l, r);
		for (int i = 0; i < size; i++) {
			mass[i] = rand()%(r-l+1)+l;
		}
	}
};

