#include "headers\\Button.h"

Button::Button(Screen* screen, string path, sf::Vector2f pos, sf::Vector2f size, void (Screen::* func)()) {
	this->screen = screen;
	this->func = func;
	Tpic.loadFromFile(path);
	Spic.setTexture(Tpic);
	hitbox = sf::RectangleShape(size);

	hitbox.setPosition(pos);
	Spic.setPosition(pos);
}

void Button::use() {
	(screen->*func)();
}

void Button::draw(sf::RenderWindow& window) {
	window.draw(Spic);
}
bool Button::isMovedOn() { // is cursor on an object
	return hitbox.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
}
