#pragma once
class Field
{
private:
	Player* firstP;
	Player* secondP;

	bool isFirst;

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

	void draw(sf::RenderWindow& window) {
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
		//first
		vector<Card*> curDeck = firstP->getDeck()->getHand();
		int size = curDeck.size();
		int space = 350;
		vector<Card*> toDraw;
		int chosen = -1;

		for (int i = 0; i < size; i++) {
			if (curDeck[i]->Display(sf::Vector2f(space, 850),isFirst, (i==size-1), chosen)) {
				space += 320;
				chosen = i;
			}
			else space += 80;
			toDraw.push_back(curDeck[i]);
		}

		size = toDraw.size();
		for (int i = 0; i < size; i++) {
			if (chosen == i)continue;
			toDraw[i]->drawCard(window);
		}
		if (chosen != -1)toDraw[chosen]->drawCard(window);
		window.draw(Sdeck1);
		window.draw(Sdeck2);
	}
};

