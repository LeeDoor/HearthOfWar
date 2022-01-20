#pragma once
#include"headers\\Field.h"
#include"headers\\Player.h"


extern sf::Vector2f DECK_POS1;
extern sf::Vector2f DECK_POS2;

Field::Field(Player* secondP, Player* firstP) {
	this->firstP = firstP;
	this->secondP = secondP;

	isTargetable = true;
	isInitiator = false;

	hitbox = sf::RectangleShape(sf::Vector2f(1500,600));
	hitbox.setPosition(50,250);
	hitbox.setFillColor(sf::Color(0, 17, 255, 20));
}

Clickable* Field::useCheckEntities(bool isFirst) {
	//check for entities
	int size;
	vector<Creature*> entities;
	if(isFirst)
		entities = firstP->getEntities();
	else
		entities = secondP->getEntities();

	size = entities.size();
	for (int j = 0; j < size; j++) {
		if (entities[j]->isMovedOn()) {
			return entities[j];
		}
	}
	return nullptr;
}
Clickable* Field::useCheckHands(bool isFirst) {
	//checking cards's hitbox in hands
	int size;
	vector<Card*> curDeck;
	if(isFirst)
		curDeck = firstP->getDeck()->getHand();
	else 
		curDeck = secondP->getDeck()->getHand();

	size = curDeck.size();
	for (int j = 0; j < size; j++) {
		if (curDeck[j]->isMovedOn()) {
			return curDeck[j];
		}
	}
	return nullptr;
}
Clickable* Field::useCheckField() {
	//checking field press
	if (isMovedOn()) {
		return this;
	}
	return nullptr;
}
Clickable* Field::useCheckPerson(bool isFirst) {
	if (isFirst) {
		if (firstP->getPerson()->isMovedOn()) {
			return firstP->getPerson();
		}
	}
	else{
		if (secondP->getPerson()->isMovedOn()) {
			return secondP->getPerson();
		}
	}
	return nullptr;
}
//i need to fix bug then i can use enemie's entities. i send to useCheck func
//vector of targets like "123456" to see
//which targets will i check. then i choose an initiator, defaults are ally
//entities and hand. then i already have it, i am getting targets from initiator.
Clickable* Field::useCheck(vector<int>targets) {
	int size = targets.size();
	Clickable* buff;
	for (int i = 0; i < size; i++) {
		switch (targets[i]) {
		case 0:
			buff = useCheckEntities(!(isFirst^true));
			if (buff != nullptr)
				return buff;
			break;
		case 1:
			buff = useCheckEntities(!(isFirst ^ false));
			if (buff != nullptr)
				return buff;
			break;
		case 2:
			buff = useCheckHands(!(isFirst ^ true));
			if (buff != nullptr)
				return buff;
			break;
		case 3:
			buff = useCheckHands(!(isFirst ^ false));
			if (buff != nullptr)
				return buff;
			break;
		case 4:
			buff = useCheckField(); 
			if (buff != nullptr)
				return buff;
			break;
		
		case 5:
			buff = useCheckPerson(!(isFirst ^ true));
			if (buff != nullptr)
				return buff;
			break;
		case 6:
			buff = useCheckPerson(!(isFirst ^ false));
			if (buff != nullptr)
				return buff;
			break;
		
		default:
			cout << "\n\nFIELD.CPP ERROR: WRONG TYPE OF TARGET\n\n";
		}
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
	window.draw(hitbox);

	sf::Font font;
	sf::Text mana;
	font.loadFromFile("fonts\\ariali.ttf");
	mana.setFont(font);
	mana.setCharacterSize(70);
	mana.setFillColor(sf::Color::Blue);
	mana.setOutlineThickness(20);
	mana.setOutlineColor(sf::Color::White);

	mana.setString(to_string(firstP->getCurMana()));
	mana.setPosition(1400, 900);
	window.draw(mana);

	mana.setString(to_string(secondP->getCurMana()));
	mana.setPosition(1400, 30);
	window.draw(mana);

	stepTime += time;
	//drawing persons
	//first
	firstP->getPerson()->draw(window);
	secondP->getPerson()->draw(window);

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

	// draw entities
	curPlayer = firstP;
	space = 260;
	for (int i = 0; i < 2; i++) {
		size = curPlayer->getEntities().size();
		for (int j = 0; j < size; j++) {
			curPlayer->getEntities()[j]->viewAsEntity(time, sf::Vector2f(60 + space * j, 250 + (i == 0) * 270), initiator);
			curPlayer->getEntities()[j]->drawCard(window, 3);
		}
		curPlayer = secondP;
	}


	curPlayer = firstP;
	space = 0;
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

	window.draw(Sdeck1);
	window.draw(Sdeck2);
}


bool Field::getIsStarted() {
	return isStarted;
}
Player* Field::getCurPlayer() {
	if (isFirst)return firstP;
	return secondP;
}
Player* Field::getOtherPlayer() {
	if (isFirst)return secondP;
	return firstP;
}

Deck* Field::getDeck(bool isFirst) {
	Player* currPlayer;
	if (isFirst)
		currPlayer = firstP;
	else
		currPlayer = secondP;

	return currPlayer->getDeck();
}

bool Field::deathCheck(Player* player) {
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

	if (player->getPerson()->getHealth() <= 0) {
		isStarted = false;
		return true;
	}
	return false;
}
Player* Field::deathCheck() {
	if (deathCheck(firstP))return firstP;
	if (deathCheck(secondP))return secondP;
	return nullptr;
}

Creature* Field::checkCreature(Player* player) {
	int size = player->getEntities().size();
	for (int i = 0; i < size; i++) {
		if (player->getEntities()[i]->isMovedOn() ) {
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