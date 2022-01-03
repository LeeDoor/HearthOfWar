class Deck;
class Player;
class Card;
class Creature;
class Entity;
class Event;
class CDB;
class Field;

#include"includer.h"

#include "Card.h"	// card
#include "Creature.h" // entity, creature
#include "Event.h" // Millitary Forces
#include "Deck.h"	// many cards
#include "Player.h"	// player
#include "Field.h"	// gaming field
#include "CDB.h"	// card data base

int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");

	sf::Clock clock;

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Secure Contain Attack"/*, sf::Style::Fullscreen*/);

	CDB* cardDB = new CDB;

	Deck* firstDeck = new Deck(cardDB, window);
	Deck* secondDeck = new Deck(cardDB, window);
	Player* firstPlayer = new Player(firstDeck);
	Player* secondPlayer = new Player(secondDeck);

	Field field(firstPlayer, secondPlayer);
	field.startGame();

	while (window.isOpen()) {
		float time;
		time = clock.getElapsedTime().asSeconds();
		clock.restart();

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Space) {
					field.nextTurn();
				}
			}
			if (event.type == sf::Event::MouseButtonPressed) {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					field.useCheck();
				}
			}
		}
		window.clear(sf::Color(168, 196, 255));

		field.draw(window, time, event);



		window.display();

	}
}