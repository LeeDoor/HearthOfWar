#pragma once

#include"includer.h"
class Player;

class Card
{
protected:
	
	int id; // special id of a card
	string gameClass;

	string picPath;
	string name;
	int cost;//how much does it cost
	string type; // danger level
	vector<string> feature; // special property
	vector<string> funcFeat; // function of special property (func has same position as feature -- 0 id is battlecry, 1 id is deathrattle(**){**})
	string description; // what is this card do

	bool isTaken; // i want to use it
	bool isChoosen;// i want to see what does it do

	//SFML
	sf::Vector2f pos;
	sf::Vector2f rez;

	sf::Texture Tbg;
	sf::Texture Tpic;
	sf::Texture Tvalue;
	sf::Sprite Sbg;
	sf::Sprite Spic;
	sf::Sprite Scost;
	sf::Font font;
	sf::Text Ttitle;
	sf::Text Tdesc;
	sf::Text Tcost;

	int DrawType; // 0 - big, 1 - low, 2 - back
	sf::RectangleShape hitbox;
	
public:
	Card();
	Card(Card* card);

	string getGameClass();

	vector<string> getFeautre();
	vector<string> getFuncFeat();
	string getPicPath();

	void viewLow(sf::Vector2f pos, bool isTop = false);
	void viewBack(sf::Vector2f pos, bool isTop = false);
	
	void Display(int& space, int mana, bool& chosen, bool deckFirst = true, bool isFirst = true, bool isTop = false);

	bool isMovedOn();

	virtual int getDamage() { return -1; }
	virtual int getHealth() { return -1; }
	virtual void copy(Card* card) {
		this->id = card->id;
		this->picPath = card->picPath;
		this->name = card->name;
		this->cost = card->cost;
		this->type = card->type;
		this->feature = card->feature;
		this->funcFeat = card->funcFeat;
		this->description = card->description;
		this->gameClass = card->gameClass;
		setTexture();
	}
	void setTexture() {
		Tpic.loadFromFile(picPath, sf::IntRect(0, 0, 280, 180));
		Tvalue.loadFromFile("pic\\BGvalue.png");


		if (!font.loadFromFile("ariali.ttf"))
		{
			cout << "efaefaf";
		}
		if (type == "Keter") {
			Tbg.loadFromFile("pic\\BGketer.png");
		}
		else if (type == "Euclid") {
			Tbg.loadFromFile("pic\\BGeuclid.png");
		}
		else if (type == "Safe") {
			Tbg.loadFromFile("pic\\BGsafe.png");
		}
		else if (type == "Thaumiel") {
			Tbg.loadFromFile("pic\\BGthaumiel.png");
		}
		else {
			Tbg.loadFromFile("pic\\BGunknown.png");
		}

		hitbox = sf::RectangleShape(sf::Vector2f(160, 200));

	}
	virtual void use(Player* currP) {

	}
	virtual void viewBig(sf::Vector2f pos) {
		hitbox = sf::RectangleShape(sf::Vector2f(320, 420));
		hitbox.setPosition(pos);

		Sbg = sf::Sprite(Tbg);
		Sbg.setPosition(pos);

		Spic = sf::Sprite(Tpic);
		Spic.setPosition(sf::Vector2f(pos.x + 20, pos.y + 15));

		Ttitle.setFont(font);
		Ttitle.setString(name);
		Ttitle.setCharacterSize(20);
		Ttitle.setPosition(sf::Vector2f(pos.x + 20, pos.y + 210));
		Ttitle.setFillColor(sf::Color::Black);

		Tdesc.setFont(font);
		Tdesc.setString(description);
		Tdesc.setCharacterSize(14);
		Tdesc.setPosition(sf::Vector2f(pos.x + 20, pos.y + 275));
		Tdesc.setFillColor(sf::Color::Black);

		Scost = sf::Sprite(Tvalue);
		Scost.setPosition(pos);

		Tcost.setFont(font);
		Tcost.setString(to_string(cost));
		Tcost.setCharacterSize(50);
		Tcost.setPosition(sf::Vector2f(pos.x + 20, pos.y));
		Tcost.setFillColor(sf::Color::Blue);
	}
	virtual void drawCard(sf::RenderWindow& window) {
		window.draw(hitbox);
		switch (DrawType) {
		case 0:
			window.draw(Sbg);
			window.draw(Spic);
			window.draw(Ttitle);
			window.draw(Tdesc);
			window.draw(Scost);
			window.draw(Tcost);
			break;
		case 1:
			window.draw(Spic);
			break;
		case 2:
			window.draw(Sbg);
			break;
		}
	}

};

