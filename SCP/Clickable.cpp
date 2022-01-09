#include "headers\\Clickable.h"

bool Clickable::getIsTargetable() {
	return isTargetable;
}
bool Clickable::getIsInitiator() {
	return isInitiator;
}
int Clickable::getDamage() {return 1;}
int Clickable::getHealth() {return 1;}
vector<int> Clickable::getTargets() {
	return targets;
}

void Clickable::use(Clickable* target, Player* player) {}
void Clickable::acceptAttack(int damage) {}

bool Clickable::isMovedOn() { // is cursor on an object
	return hitbox.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
}