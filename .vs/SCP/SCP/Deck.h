#pragma once

#include"includer.h"
#include"Card.h"
#include"CDB.h"

class Deck
{
private:
	vector<Card*> deck;
	vector<Card*> left;
	vector<Card*> hand;
	CDB* curDB;
	const int DECK_SIZE = 10;


	void fillHand(bool isFirst);


	void addCard(int id);
	void takeCard();
	void addLeft(int id);

public:
	Card* operator[](int id);

	Deck(CDB* cdb, sf::RenderWindow& window);

	vector<Card*> getDeck();
	vector<Card*> getLeft();
	vector<Card*> getHand();


	void createDeck(sf::RenderWindow& window);
	void clear();
	void startGame(bool isFirst);
};

