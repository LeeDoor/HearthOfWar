using namespace std;
#include<iostream> // 
#include<ctime> // 


class Card;
class People;
class MilFor;
class Deck;
class CDB;


#include"includer.cpp" // all other docs


int main() {
	srand(time(NULL));

	CDB* cardDB = new CDB;

	Deck a(cardDB);
	a.viewDeck();
}