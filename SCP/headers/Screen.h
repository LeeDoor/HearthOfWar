#pragma once
#include"includer.h"
#include"Field.h"
#include"Button.h"

class Screen
{
private:
	string screenType; // which sceen is now
	//  menu	game	createDeck	endGame

	CDB* cdb;

	Field* field;
	Deck* deckF;
	Deck* deckS;

	sf::Texture Tbg;
	sf::Sprite Sbg;

	Clickable* initiator = nullptr; // we are saving initiator of some event
	Clickable* buff; // needs to check variables of initiator to accept it
	vector<int> targets; // where we will look for a target or an initiator

	vector<Button*> buttons;

	bool isOpened = true;
public:
	Screen(CDB* cdb);

	Field* getField();
	string getScreenType();
	bool getIsOpened();

	void setCreateDeck();
	void setMenu();
	void setGame();

	void drawCreateDeck(sf::RenderWindow& window);
	void drawMenu(sf::RenderWindow& window);
	void drawGame(sf::RenderWindow& window, float time, Clickable* initiator);
	void drawWinScreen(sf::RenderWindow& window, Player* player);
	void draw(sf::RenderWindow& window, float time);

	void CloseGame(sf::RenderWindow& window);
	void exit();

	void clearButtons();
	void setDefaultToClick(Clickable*& initiator, vector<int>& targets);
	void afterEvent(sf::RenderWindow& window);

	void playEvent(sf::Event event);
	void nextTurn();
};

