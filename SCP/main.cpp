class Deck;
class Player;
class Card;
class Creature;
class Entity;
class Event;
class CDB;
class Field;

#include"headers\\includer.h"
#include "headers\\Clickable.h"	// card data base
#include "headers\\Card.h"	// card
#include "headers\\Creature.h" // entity, creature
#include "headers\\Event.h" // Millitary Forces
#include "headers\\Deck.h"	// many cards
#include "headers\\Player.h"	// player
#include "headers\\Field.h"	// gaming field
#include "headers\\CDB.h"	// card data base

sf::Vector2f DECK_POS1(1627, 600);
sf::Vector2f DECK_POS2(1627, 330);
sf::Vector2f HAND_POS1(150, 850);
sf::Vector2f HAND_POS2(15, 15);
int MAX_ENTITY = 5;

#include "headers\\drawWinScreen.h"
void setDefaultToClick(Clickable*& initiator, vector<int>& targets) {
	initiator = nullptr;
	targets = vector<int>{ 0,2 };
}

void drawWinScreen(sf::RenderWindow& window, Player* player) {

	// setting "you won" text
	sf::Font font;
	font.loadFromFile("fonts\\ariali.ttf");
	sf::Text winnerText;
	winnerText.setFont(font);
	winnerText.setPosition(720, 700);
	winnerText.setCharacterSize(80);
	winnerText.setFillColor(sf::Color(74, 23, 20));
	winnerText.setOutlineColor(sf::Color(235, 235, 235));
	winnerText.setOutlineThickness(10);

	//setting sprite of winner person

	player->getPerson()->setPosition(sf::Vector2f(810, 390));
	player->getPerson()->prepare();
	if (!player->getIsFirst()) {
		winnerText.setString("First player won!");
		player->getPerson()->setTexture("pic\\person\\AllyHappy.png");
		window.clear(sf::Color(133, 255, 139)); // light green
	}
	else {
		winnerText.setString("Second player won!");
		player->getPerson()->setTexture("pic\\person\\EnemyHappy.png");
		window.clear(sf::Color(252, 205, 202)); // light red

	}


	window.draw(winnerText);
	player->getPerson()->draw(window,false);
}



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
	vector<int> targets; // where we will look for a target or an initiator

	setDefaultToClick(initiator, targets);

	float time;
	Player* winStatus;

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
					setDefaultToClick(initiator, targets);
				}
				if (event.key.code == sf::Keyboard::LAlt) {
					field.startGame();
				}
			}
			if (event.type == sf::Event::MouseButtonPressed) {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					if (field.getIsStarted()) {
						buff = field.useCheck(targets);
						if (buff != nullptr) {
							if (initiator == nullptr) {
								if (buff->getIsInitiator()) {
									initiator = buff;
									targets = initiator->getTargets();
								}
							}
							else {
								if (buff->getIsTargetable()) {
									initiator->use(buff, field.getCurPlayer());
									buff = nullptr;
									setDefaultToClick(initiator, targets);
								}
							}
						}
					}
				}
				else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
					if (field.getIsStarted()) {
						setDefaultToClick(initiator, targets);
					}
				}
			}
		}
		
		
		if (field.getIsStarted()) {
			window.clear(sf::Color(168, 196, 255));
			field.draw(window, time, initiator);
			winStatus = field.deathCheck();
			if (winStatus != nullptr) {
				drawWinScreen(window, winStatus);
			}

			window.display();
		}


	}
}