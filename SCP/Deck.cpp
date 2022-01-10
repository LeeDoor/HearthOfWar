#pragma once

#include"headers\\Deck.h"
#include"headers\\Creature.h"
#include"headers\\Event.h"
#include"headers\\CDB.h"

const int MAX_HAND_SIZE = 8;
const int DECK_SIZE = 30;

void Deck::fillHand(bool isFirst) {
	int size;
	if (isFirst)
		size = 2; // how many cards will be given to a first player
	else
		size = 3; // how many cards will be given to a second player


	for (int i = 0; i < size; i++) {
		takeCard(isFirst);
	}
}



void Deck::addCard(int id) { // adds card to deck
	Card* buff = curDB->getCard(id);
	if (buff->getGameClass() == "Creature") {
		Creature* adding = new Creature;
		adding->copy(buff);
		deck.push_back(adding);
	}
	else {
		Event* adding = new Event;
		adding->copy(buff);
		deck.push_back(adding);
	}
}
void Deck::takeCard(bool isFirst) {
	if (left.size() >= 1 && hand.size()<MAX_HAND_SIZE) {
		hand.push_back(left[left.size() - 1]);
		hand[hand.size() - 1]->AnimationTakeCard(isFirst);
		left.pop_back();
	}
}
void Deck::addLeft(int id) {
	Card* buff = deck[id];
	if (buff->getGameClass() == "Creature") {
		Creature* adding = new Creature;
		adding->copy(buff);
		left.push_back(adding);
	}
	else {
		Event* adding = new Event;
		adding->copy(buff);
		left.push_back(adding);
	}
}
Card* Deck::operator[](int id) {
	return deck[id];
}

Deck::Deck(CDB* cdb, sf::RenderWindow& window) {
	curDB = cdb;
	createDeck(window);
}

vector<Card*>  Deck::getDeck() {
	return deck;
}
vector<Card*>  Deck::getLeft() {
	return left;
}
vector<Card*>&  Deck::getHand() {
	return hand;
}


void  Deck::createDeck(sf::RenderWindow& window) {
	clear();

	int a;
	for (int i = 0; i < DECK_SIZE; i++) {
		while (true) {
			cout << i + 1 << " : ";
			a = rand() % curDB->getSize();
			if (curDB->getCard(a) != 0) {
				addCard(a);
				break;
			}
		}
	}
}
void  Deck::clear() {
	while (deck.size() > 0)deck.pop_back();
}
void  Deck::startGame(bool isFirst) {
	left.clear();
	hand.clear();

	int size = deck.size();
	for (int i = 0; i < size; i++) {
		addLeft(i);
	}
	fillHand(isFirst);
}


