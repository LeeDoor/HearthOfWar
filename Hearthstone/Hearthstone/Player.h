#pragma once
class Player
{
private:
	//Person* person
	Deck* deck;
	vector<Creature*> creatures;

	int mana;
	int curMana;
public:
	Player(){}
	Player(Deck* deck) {
		this->deck = deck;
	}

	void startGame(bool isFirst) {
		deck->startGame(isFirst);
		mana = 0;
	}

	void viewField() {
		//enter smth here
	}

	bool step() {
		mana++;
		curMana = mana;
		return (false);
	}

	Deck* getDeck() {
		return deck;
	}
	vector<Creature*> getCreatures() {
		return creatures;
	}
	int getCurMana() {
		return curMana;
	}
};

