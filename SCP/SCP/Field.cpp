#pragma once
#include"Field.h"
#include"Player.h"


extern sf::Vector2f DECK_POS1;
extern sf::Vector2f DECK_POS2;

Field::Field(Player* secondP, Player* firstP) {
	this->firstP = firstP;
	this->secondP = secondP;

	isTargetable = true;
	isInitiator = false;

	hitbox = sf::RectangleShape(sf::Vector2f(1500,600));
	hitbox.setPosition(50,250);
	hitbox.setFillColor(sf::Color(246, 255, 0,50));
}

Clickable* Field::useCheck(sf::Event event) {
	//checking cards in hands
	int size;
	vector<Card*> curDeck;
	curDeck = firstP->getDeck()->getHand();
	for (int i = 0; i < 2; i++) {
		size = curDeck.size();
		for (int j = 0; j < size; j++) {
			if (curDeck[j]->isMovedOn()) {
				return curDeck[j];
			}
		}
		curDeck = secondP->getDeck()->getHand();
	}

	//check for entities
	vector<Creature*> entities = firstP->getEntities();
	for (int i = 0; i < 2; i++) {
		size = entities.size();
		for (int j = 0; j < size; j++) {
			if (entities[j]->isMovedOn()) {
				return entities[j];
			}
		}
		entities = secondP->getEntities();
	}
	
	//checking field press
	if (hitbox.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)) {
		return this;
	}

	return nullptr;
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
void Field::draw(sf::RenderWindow& window, float time, Clickable* initiator) {
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
			curPlayer->getDeck()->getHand()[i]->Display(space, time, curPlayer->getCurMana(), chosen, (q == 0), isFirst, (i == size - 1), initiator);
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
			curPlayer->getEntities()[j]->viewAsEntity(sf::Vector2f(60+space*j,250+(i==0)*270), initiator);
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


	window.draw(hitbox);
	window.draw(Sdeck1);
	window.draw(Sdeck2);
	window.draw(timer);
}


bool Field::getIsStarted() {
	return isStarted;
}
Player* Field::getCurPlayer() {
	if (isFirst)return firstP;
	return secondP;
}

void Field::deathCheck(Player* player) {
	vector<Creature*>&curCreat = player->getEntities(); // mass of creatures of current player
	int size = curCreat.size();
	for (int i = 0; i < size; i++) {
		if (curCreat[i]->getHealth() <= 0) {
			Creature* buff = curCreat[i];
			curCreat.erase(curCreat.begin()+i);
			delete buff;
			size = curCreat.size();
		}
	}
}
void Field::deathCheck() {
	deathCheck(firstP);
	deathCheck(secondP);
}

Creature* Field::checkCreature(Player* player) {
	int size = player->getEntities().size();
	for (int i = 0; i < size; i++) {
		if (player->getEntities()[i]->isMovedOn()) {
			return player->getEntities()[i];
		}
	}
	return nullptr;

}

Card* Field::checkCard(Player* player) {
	int size = player->getDeck()->getHand().size();
	for (int i = 0; i < size; i++) {
		if (player->getDeck()->getHand()[i]->isMovedOn()) {
			return player->getDeck()->getHand()[i];
		}
	}
	return nullptr;
}

bool Field::isMovedOn(){ // is cursor on a field
	return hitbox.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
}