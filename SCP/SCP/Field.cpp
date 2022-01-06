#pragma once
#include"Field.h"
#include"Player.h"

extern sf::Vector2f DECK_POS1;
extern sf::Vector2f DECK_POS2;

Field::Field(Player* secondP, Player* firstP) {
	this->firstP = firstP;
	this->secondP = secondP;

}

void Field::useCheck() {
	int size;
	Player* currentP;
	if (isFirst)
		currentP = firstP;
	else
		currentP = secondP;
	size = currentP->getDeck()->getHand().size();
	for (int i = 0; i < size; i++) {
		if (currentP->getDeck()->getHand()[i]->isMovedOn()) {
			currentP->getDeck()->getHand()[i]->use(currentP);
			break;
		}
	}
}
void Field::startGame() {
	firstP->startGame(true);
	secondP->startGame(false);
	isStarted = true;				
	isFirst = true;

}
bool Field::nextTurn() {
	isFirst = !isFirst;

	if (isFirst) {
		return firstP->step(isFirst);
	}
	else return secondP->step(isFirst);
}
void Field::draw(sf::RenderWindow& window, float time, sf::Event& event) {
	stepTime += time;

	// drawing decks
	sf::Texture Tdeck;
	Tdeck.loadFromFile("pic\\coloda.png");

	//first 
	sf::Sprite Sdeck1(Tdeck);
	Sdeck1.setPosition(DECK_POS1);

	//second
	sf::Sprite Sdeck2(Tdeck);
	Sdeck2.setPosition(DECK_POS2);

	//draw hands
	Player* curPlayer = firstP;
	int size;
	int space = 0;
	vector<Card*> toDraw;
	bool chosen = false; // "big" card for whatching what is it doing

	for (int q = 0; q < 2; q++) {
		size = curPlayer->getDeck()->getHand().size();
		for (int i = 0; i < size; i++) {
			curPlayer->getDeck()->getHand()[i]->Display(space, time, curPlayer->getCurMana(), chosen, (q == 0), isFirst, (i == size - 1));
			toDraw.push_back(curPlayer->getDeck()->getHand()[i]);
		}

		curPlayer = secondP;
		chosen = false;
		space = 0;
	}

	size = toDraw.size();
	for (int i = 0; i < size; i++) {
		toDraw[i]->drawCard(window);
	}

	// draw entities
	curPlayer = firstP;
	space = 260;
	for (int i = 0; i < 2; i++) {
		size = curPlayer->getEntities().size();
		for (int j = 0; j < size; j++) {
			curPlayer->getEntities()[j]->viewAsEntity(sf::Vector2f(60+space*j,250+(i==0)*270));
			curPlayer->getEntities()[j]->drawCard(window,3);
		}
		curPlayer = secondP;
	}

	//timer (for what)
	sf::Text timer;
	sf::Font font;
	font.loadFromFile("fonts\\ariali.ttf");
	timer.setFont(font);
	timer.setString(to_string(firstP->getCurMana()) + to_string(secondP->getCurMana()));
	timer.setPosition(0, 0);


	window.draw(Sdeck1);
	window.draw(Sdeck2);
	window.draw(timer);
}


bool Field::getIsStarted() {
	return isStarted;
}