#include "headers\\Clickable.h"

bool Clickable::getIsTargetable() {
	return isTargetable;
}
bool Clickable::getIsInitiator() {
	return isInitiator;
}
int Clickable::getDamage() {return 0;}
int Clickable::getHealth() {return 0;}
vector<int> Clickable::getTargets() {
	return targets;
}

void Clickable::use(Clickable* target, Player* player, Field* field) { cout << "wrong func called\n"; }
void Clickable::acceptAttack(int damage) {
	cout << 'Q';
}

bool Clickable::isMovedOn() { // is cursor on an object
	return hitbox.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
}