#include"includer.cpp" // including


int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");

	sf::Clock clock;

	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Secure Contain Attack"/*, sf::Style::Fullscreen*/);

	CDB* cardDB = new CDB;

	Deck* firstDeck = new Deck(cardDB, window);
	Deck* secondDeck = new Deck(cardDB,window);
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
		}
		window.clear(sf::Color(168, 196, 255));

		field.draw(window, time);



		window.display();
		
	}
	



	/*
	*/
}