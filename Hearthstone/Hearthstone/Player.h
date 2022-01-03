#pragma once
class Player
{
private:
	//Person* person
	Deck* deck;
	vector<Entity*> entities;

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
	vector<Entity*> getEntities() {
		return entities;
	}
	int getCurMana() {
		return curMana;
	}

	void createEntity(Creature* creature) {
		entities.push_back(new Entity(creature));
	}
};

