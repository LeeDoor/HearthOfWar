#pragma once
#include"includer.h"
#include"Field.h"
#include"Button.h"

class Screen
{
private:
	string screenType; // which sceen is now
	//  menu	game	createDeck

	CDB* cdb;

	Field* field;
	Deck* deckF;
	Deck* deckS;

	sf::Texture Tbg;
	sf::Sprite Sbg;

	vector<Button*> buttons;
public:
	Screen(CDB* cdb, sf::RenderWindow& window);

	void setCreateDeck();
	void setMenu();
	void setGame();

	void drawCreateDeck(sf::RenderWindow& window);
	void drawMenu(sf::RenderWindow& window);
	void drawGame(sf::RenderWindow& window, float time, Clickable* initiator);

	void exit(sf::RenderWindow& window);

	void clearButtons();
};

