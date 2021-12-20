#pragma once
class Player
{
private:
	//Person* person
	Deck* deck;
	vector<People*> creatures;

	int mana;
	int currMana;
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
		currMana = mana;
		bool flag = true;
		while (flag) { // there is still en errors and nothing happening
			int choose;
			cout << "enter what do you want to do:\n\t1: use card\n\t2: attack\n\t0: complete the move\n";
			cin >> choose;
			switch (choose) {
			case 1:
				cout << "enter id of the card in your hand which you want to use: ";
				cin >> choose;
				deck->useCard(choose);
				break;

			case 2:
				cout << "who will attack? enter id of the creature or -1(character): ";
				cin >> choose;
				//if(choose == -1)person.attack();
				/*else {*/
				creatures[choose]->attack();

				/*}*/

			case 0:
				flag = false;
				break;

			default:
				cout << "wrong info. try again";
			}
		}
		return (!(flag));
	}
};

