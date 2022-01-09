#pragma once
#include"headers\\Card.h"
#include"headers\\Animation.h"

int::Card::ANIMATION_SPEED = 20;
extern sf::Vector2f DECK_POS1;
extern sf::Vector2f DECK_POS2;

extern sf::Vector2f HAND_POS1;
extern sf::Vector2f HAND_POS2;

Card::Card() {
	this->isTargetable = false;
	this->isInitiator = true;
	this->targets = vector<int>{4};
}
Card::~Card() {

}

Card::Card(Card* card) :
	id(card->id),
	picPath(card->picPath),
	name(card->name),
	cost(card->cost),
	type(card->type),
	feature(card->feature),
	funcFeat(card->funcFeat),
	description(card->description)
{
	setTexture();
}

string Card::getGameClass() {
	return gameClass;
}
vector<string> Card::getFeautre() {
	return feature;
}
vector<string> Card::getFuncFeat() {
	return funcFeat;
}
string Card::getPicPath() {
	return picPath;
}
int Card::getId() {
	return id;
}

void Card::setPos(sf::Vector2f pos) {
	this->pos = pos;
}

void Card::viewLow(bool isTop) { // viewing small version of card in hand
	if (isTop == false)
		hitbox = sf::RectangleShape(sf::Vector2f(80, 200));
	else {

		hitbox = sf::RectangleShape(sf::Vector2f(160, 200));
		hitbox.setFillColor(sf::Color(0, 0, 0, 50));
	}
	hitbox.setPosition(pos);

	Spic = sf::Sprite(Tpic, sf::IntRect(60, 0, 160, 200));
	Spic.setPosition(sf::Vector2f(pos.x, pos.y));
}
void Card::viewBack(bool isTop) { // viewing backside of a card
	if (isTop == false)
		hitbox = sf::RectangleShape(sf::Vector2f(80, 200));
	else {

		hitbox = sf::RectangleShape(sf::Vector2f(160, 200));
		hitbox.setFillColor(sf::Color(0, 0, 0, 50));
	}
	hitbox.setPosition(pos);
	hitbox.setOutlineThickness(2);
	hitbox.setOutlineColor(sf::Color::Black);

	Sbg = sf::Sprite(Tbg, sf::IntRect(0, 0, 160, 200));
	Sbg.setPosition(sf::Vector2f(pos.x, pos.y));
}
void Card::viewBig() {
	hitbox = sf::RectangleShape(sf::Vector2f(320, 420));
	hitbox.setPosition(pos);

	Sbg = sf::Sprite(Tbg);
	Sbg.setPosition(pos);

	Spic = sf::Sprite(Tpic);
	Spic.setPosition(sf::Vector2f(pos.x + 20, pos.y + 15));

	Ttitle.setFont(font);
	Ttitle.setString(name);
	Ttitle.setCharacterSize(20);
	Ttitle.setPosition(sf::Vector2f(pos.x + 20, pos.y + 210));
	Ttitle.setFillColor(sf::Color::Black);

	Tdesc.setFont(font);
	Tdesc.setString(description);
	Tdesc.setCharacterSize(14);
	Tdesc.setPosition(sf::Vector2f(pos.x + 20, pos.y + 275));
	Tdesc.setFillColor(sf::Color::Black);

	Scost = sf::Sprite(Tvalue);
	Scost.setPosition(pos);

	Tcost.setFont(font);
	Tcost.setString(to_string(cost));
	Tcost.setCharacterSize(50);
	Tcost.setPosition(sf::Vector2f(pos.x + 20, pos.y));
	Tcost.setFillColor(sf::Color::Blue);
}
// space - free space between cards
// mana - mana of current player
// deckFirst - is this top or bottom drawing
// isFirst - is first playing
// isTop - is it last card in the hand(needed for making correct hitbox sizes of card)
// chosen - is there any picked cards
// target - if this object equals target, border is yellow to show it.
void Card::Display(int& space, float time, int mana, bool& chosen, bool deckFirst, bool isFirst, bool isTop, Clickable* initiator) { // function decides which type of drawing we will be using
	if(animation.animationType == "takeCard")
	{
		AnimationTakeCard(isFirst,time);
		DrawType = 1;
	}
	else {
		hitbox.setFillColor(sf::Color::Black);

		if (!deckFirst)
			pos = sf::Vector2f(space + 15, 15);
		else
			pos = sf::Vector2f(space + 150, 850);

		if (isFirst != deckFirst) {
			DrawType = 2;
		}
		else if (isMovedOn() && chosen == false) {
			DrawType = 0;
			if (isFirst)
				pos.y -= 200;
		}
		else {
			DrawType = 1;
		}
		setPos(pos);
		switch (DrawType) {
		case 0:
			viewBig();
			space += 320;
			chosen = true;
			break;
		case 1:
			viewLow(isTop);
			space += 80;
			break;

		case 2:
			space += 80;
			viewBack(isTop);
		}
		if (this == initiator) {
			hitbox.setOutlineThickness(8);
			hitbox.setOutlineColor(sf::Color::Yellow);
		}
		else if (cost <= mana && DrawType != 2) {
			hitbox.setOutlineThickness(8);
			hitbox.setOutlineColor(sf::Color::Green);
		}
	}
}


void Card::copy(Card* card) {
	this->id = card->id;
	this->picPath = card->picPath;
	this->name = card->name;
	this->cost = card->cost;
	this->type = card->type;
	this->feature = card->feature;
	this->funcFeat = card->funcFeat;
	this->description = card->description;
	this->gameClass = card->gameClass;
	setTexture();
}
void Card::setTexture() {
	Tpic.loadFromFile(picPath, sf::IntRect(0, 0, 280, 180));
	Tvalue.loadFromFile("pic\\BGvalue.png");


	if (!font.loadFromFile("fonts\\ariali.ttf"))
	{
		cout << "efaefaf";
	}
	if (type == "Keter") {
		Tbg.loadFromFile("pic\\BGketer.png");
	}
	else if (type == "Euclid") {
		Tbg.loadFromFile("pic\\BGeuclid.png");
	}
	else if (type == "Safe") {
		Tbg.loadFromFile("pic\\BGsafe.png");
	}
	else if (type == "Thaumiel") {
		Tbg.loadFromFile("pic\\BGthaumiel.png");
	}
	else {
		Tbg.loadFromFile("pic\\BGunknown.png");
	}

	hitbox = sf::RectangleShape(sf::Vector2f(160, 200));

}
void Card::drawCard(sf::RenderWindow& window, int DrawType) {
	if (DrawType != -1)this->DrawType = DrawType;
	else DrawType = this->DrawType;
	hitbox.setFillColor(sf::Color::Transparent);
	window.draw(hitbox);
	switch (DrawType) {
	case 0:
		window.draw(Sbg);
		window.draw(Spic);
		window.draw(Ttitle);
		window.draw(Tdesc);
		window.draw(Scost);
		window.draw(Tcost);
		break;
	case 1:
		window.draw(Spic);
		break;
	case 2:
		window.draw(Sbg);
		break;
	}
}

void Card::AnimationTakeCard(bool isFirst, float timeLeft) {
	if (animation.firstStart) {
		sf::Vector2f startPos;
		sf::Vector2f endPos;
		if (isFirst) {
			startPos = DECK_POS1;
			endPos = HAND_POS1;
		}
		else {
			startPos = DECK_POS2;
			endPos = HAND_POS2;
		}
		animation.calculateStep(startPos, endPos);
		animation.animationType = "takeCard";
		pos = startPos;
	}
	else {
		animationTimer += timeLeft;
		if (animationTimer >= ANIMATION_SPEED) {
			animationTimer = 0;
			animation.Move(pos);
			viewBig();
		}

	}
	
}

