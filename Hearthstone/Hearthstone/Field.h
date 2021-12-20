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
};

