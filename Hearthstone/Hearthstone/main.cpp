

#include"includer.cpp" // all other docs


int main() {
	srand(time(NULL));

	CDB* cardDB = new CDB;

	Deck* firstDeck = new Deck(cardDB);
	firstDeck->viewDeck();

	Deck* secondDeck = new Deck(cardDB);
	secondDeck->viewDeck();

	Player* firstPlayer  = new Player(firstDeck);
	Player* secondPlayer = new Player(secondDeck);

	Field field(firstPlayer, secondPlayer);
	field.startGame();
}