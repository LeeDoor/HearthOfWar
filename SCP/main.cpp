

#include"headers\\includer.h"
#include "headers\\Clickable.h"	// card data base
#include "headers\\Card.h"	// card
#include "headers\\Creature.h" // entity, creature
#include "headers\\Event.h" // Millitary Forces
#include "headers\\Deck.h"	// many cards
#include "headers\\Player.h"	// player
#include "headers\\Field.h"	// gaming field
#include "headers\\CDB.h"	// card data base
#include "headers\\Screen.h"// screens of the game
#include "headers\\Button.h"	// pressable buttons

sf::Vector2f DECK_POS1(1627, 600);
sf::Vector2f DECK_POS2(1627, 330);
sf::Vector2f HAND_POS1(150, 850);
sf::Vector2f HAND_POS2(15, 15);
int MAX_ENTITY = 5;
const float UPDATE_TIME = 50; // 50 milliseconds - delay between updates
#include "headers\\drawWinScreen.h"


int main() {
	srand(time(NULL));

	sf::Clock clock;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Secure Contain Attack"/*sf::Style::Fullscreen*/);
	CDB* cardDB = new CDB;
	Screen screen(cardDB);


	float CurrTime;
	float timer;
	Player* winStatus;
	while (window.isOpen()) {
		CurrTime = clock.restart().asMilliseconds();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed || !screen.getIsOpened())
				screen.CloseGame(window);

			screen.playEvent(event);
		}
		screen.afterEvent(window);

		timer += CurrTime;
		screen.draw(window, CurrTime);

	}
}

