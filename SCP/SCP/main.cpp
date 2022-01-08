class Deck;
class Player;
class Card;
class Creature;
class Entity;
class Event;
class CDB;
class Field;

#include"includer.h"
sf::Vector2f DECK_POS1(1627, 600);
sf::Vector2f DECK_POS2(1627, 330);
sf::Vector2f HAND_POS1(150, 850);
sf::Vector2f HAND_POS2(15, 15);
int MAX_ENTITY = 5;

#include "Clickable.h"	// card data base
#include "Card.h"	// card
#include "Creature.h" // entity, creature
#include "Event.h" // Millitary Forces
#include "Deck.h"	// many cards
#include "Player.h"	// player
#include "Field.h"	// gaming field
#include "CDB.h"	// card data base



int main() {
	srand(time(NULL));

	sf::Clock clock;

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Secure Contain Attack"/*, sf::Style::Fullscreen*/);

	CDB* cardDB = new CDB;

	Deck* firstDeck = new Deck(cardDB, window);
	Deck* secondDeck = new Deck(cardDB, window);
	Player* firstPlayer = new Player(firstDeck);
	Player* secondPlayer = new Player(secondDeck);

	Field field(firstPlayer, secondPlayer);
	
	Clickable* initiator = nullptr; // we are saving initiator of some event
	Clickable* buff; // needs to check variables of initiator to accept it

	float time;
	while (window.isOpen()) {
		time = clock.restart().asMilliseconds();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Space) {
					field.nextTurn();
				}
				if (event.key.code == sf::Keyboard::LAlt) {
					field.startGame();
				}
			}
			if (event.type == sf::Event::MouseButtonPressed) {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					buff = field.useCheck(event);
					if (buff != nullptr) {
						if (initiator == nullptr) {
							if (buff->getIsInitiator())
								cout << "waiting for target\n";
								initiator = buff;
						}
						else  {
							if (buff->getIsTargetable()) {
								cout << "attack!\n";
								initiator->use(buff, field.getCurPlayer());
								initiator = nullptr;
								buff = nullptr;
							}
							else {
								cout << "didnt attack, finding new initiator\n";
								initiator = nullptr;
							}
						}
					}
				}
			}
		}
		window.clear(sf::Color(168, 196, 255));

		if (field.getIsStarted()) {
			field.deathCheck();////////////////////////////////////////
			field.draw(window, time, initiator);
		}



		window.display();

	}
}