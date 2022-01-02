#pragma once
class Field
{
private:
	Player* firstP;
	Player* secondP;

	bool isFirst = false;
	float stepTime = 0;
public:
	Field(Player* secondP, Player* firstP) {
		this->firstP = firstP;
		this->secondP = secondP;

	}


	void startGame() {
		firstP->startGame(true);
		secondP->startGame(false);
		isFirst = true;

		while (nextTurn(!isFirst));
		
	}

	bool nextTurn(bool isFirst) {
		isFirst = !isFirst;

		if (isFirst) {
			return firstP->step();
		}
		else return secondP->step();
	}

	void draw(sf::RenderWindow& window, float time) {
		stepTime += time;
		if (stepTime >= 5) {
			//isFirst = !isFirst;
			//stepTime = 0;
		}

		// drawing decks
		sf::Texture Tdeck;
		Tdeck.loadFromFile("pic\\coloda.png");

		//first 
		sf::Sprite Sdeck1(Tdeck);
		Sdeck1.setPosition(1627,600);

		//second
		sf::Sprite Sdeck2(Tdeck);
		Sdeck2.setPosition(1627, 330);

		//draw hands
		vector<Card*> curDeck = firstP->getDeck()->getHand();
		int size = curDeck.size();
		int space = 0;
		vector<Card*> toDraw;
		int chosen = -1;
		bool deckFirst = isFirst;
		//first

		for (int q = 0; q < 2; q++) {
			for (int i = 0; i < size; i++) {
				if (curDeck[i]->Display(space,deckFirst, (i == size - 1), chosen)) {
					space += 320;
					chosen = i;
				}
				else space += 80;
				toDraw.push_back(curDeck[i]);
			}

			curDeck = secondP->getDeck()->getHand();
			size = curDeck.size();
			space = 0;
			deckFirst = !deckFirst;
		}


		size = toDraw.size();
		for (int i = 0; i < size; i++) {
			if (chosen == i)continue;
			toDraw[i]->drawCard(window);
		}
		if (chosen != -1)toDraw[chosen]->drawCard(window);



		//timer (for what)
		sf::Text timer;
		sf::Font font;
		font.loadFromFile("ariali.ttf");
		timer.setFont(font);
		timer.setString(to_string(stepTime));
		timer.setPosition(0,0);


		window.draw(Sdeck1);
		window.draw(Sdeck2);
		window.draw(timer);
	}
};

