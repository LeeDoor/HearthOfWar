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

	void useCheck() {
		int size;
		Player* currentP;
		if (isFirst)
			currentP = firstP;
		else
			currentP = secondP;
		size = currentP->getDeck()->getHand().size();
		for (int i = 0; i < size;i++) {
			if (currentP->getDeck()->getHand()[i]->isMovedOn()) { 
				currentP->getDeck()->getHand()[i]->use(currentP);
				break; 
			}
		}
	}
	void startGame() {
		firstP->startGame(true);
		secondP->startGame(false);
		isFirst = true;

		while (nextTurn());
		
	}
	bool nextTurn() {
		isFirst = !isFirst;

		if (isFirst) {
			return firstP->step();
		}
		else return secondP->step();
	}
	void draw(sf::RenderWindow& window, float time, sf::Event& event) {
		stepTime += time;

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
		Player* curPlayer = firstP;
		int size;
		int space = 0;
		vector<Card*> toDraw;
		bool chosen = false; // "big" card for whatching what is it doing

		for (int q = 0; q < 2; q++) {
			size = curPlayer->getDeck()->getHand().size();
			for (int i = 0; i < size; i++) {
				curPlayer->getDeck()->getHand()[i]->Display(space, curPlayer->getCurMana(), chosen, (q == 0), isFirst, (i == size - 1));
				toDraw.push_back(curPlayer->getDeck()->getHand()[i]);
			}

			curPlayer = secondP;
			chosen = false;
			space = 0;
		}

		size = toDraw.size();
		for (int i = 0; i < size; i++) {
			toDraw[i]->drawCard(window);
		}

		// draw entities
		curPlayer = firstP;
		sf::Vector2f pos(200,520);

		for (int q = 0; q < 2; q++) {
			size = curPlayer->getEntities().size();
			for (int i = 0; i < size; i++) {
				curPlayer->getEntities()[i]->draw(pos,window);
				pos.x += 260;
			}
			pos = sf::Vector2f(200,250);
			curPlayer = secondP;
			
		}



		//timer (for what)
		sf::Text timer;
		sf::Font font;
		font.loadFromFile("ariali.ttf");
		timer.setFont(font);
		timer.setString(to_string(firstP->getCurMana()) + to_string(secondP->getCurMana()));
		timer.setPosition(0,0);


		window.draw(Sdeck1);
		window.draw(Sdeck2);
		window.draw(timer);
	}
};

