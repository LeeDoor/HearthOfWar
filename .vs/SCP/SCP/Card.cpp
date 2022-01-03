#pragma once

#include"Card.h"

Card::Card() { setTexture(); }
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

void Card::viewLow(sf::Vector2f pos, bool isTop) {
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
void Card::viewBack(sf::Vector2f pos, bool isTop) {
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
// space - free space between cards
// mana - mana of current player
// deckFirst - is this top or bottom drawing
// isFirst - is first playing
// isTop - is it last card in the hand(needed for making correct hitbox sizes of card)
// chosen
void Card::Display(int& space, int mana, bool& chosen, bool deckFirst, bool isFirst, bool isTop) {

	hitbox.setFillColor(sf::Color::Black);
	sf::Vector2f pos(space + 150, 850);

	if (!deckFirst)
		pos = sf::Vector2f(space + 15, 15);

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

	switch (DrawType) {
	case 0:
		viewBig(pos);
		space += 320;
		chosen = true;
		break;
	case 1:
		viewLow(pos, isTop);
		space += 80;
		break;

	case 2:
		space += 80;
		viewBack(pos, isTop);
	}
	if (cost <= mana && DrawType != 2) {
		hitbox.setOutlineThickness(8);
		hitbox.setOutlineColor(sf::Color::Green);
	}
}
bool Card::isMovedOn() {
	return hitbox.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
}


