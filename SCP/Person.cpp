#include "headers\\Person.h"

Person::Person(bool isFirst) {
	this->isFirst = isFirst;
	hitbox = sf::RectangleShape(sf::Vector2f(300,300));
	this->isInitiator = false;
	this->isTargetable = true;
	health = 6;
	if (isFirst) {
		pos = sf::Vector2f(1600, 765);
		Tpic.loadFromFile("pic\\person\\AllyStandart.png");
	}
	else {
		pos = sf::Vector2f(1600, 15);
		Tpic.loadFromFile("pic\\person\\EnemyStandart.png");
	}
}

int Person::getHealth() {
	return health;
}

void Person::setTexture(string path) {
	Tpic.loadFromFile(path);
	prepare();
}

void Person::acceptAttack(int damage) {
	this->health -= damage;
}

void Person::update() {
	Thp.setString(to_string(health));
}

void Person::prepare() {
	hitbox.setPosition(pos);
	Spic.setPosition(pos);
	Spic.setTexture(Tpic);

	font.loadFromFile("fonts\\ariali.ttf");
	Thp.setFont(font);
	Thp.setString(to_string(health));
	Thp.setPosition(sf::Vector2f(pos.x + 130, pos.y + 230));
	Thp.setCharacterSize(50);
	Thp.setFillColor(sf::Color::Red);
	Thp.setOutlineColor(sf::Color::White);
	update();
}
void Person::setPosition(sf::Vector2f pos) {
	this->pos = pos;
}

void Person::draw(sf::RenderWindow& window, bool drawHp) {
	update();

	window.draw(Spic);
	if(drawHp)window.draw(Thp);
}
