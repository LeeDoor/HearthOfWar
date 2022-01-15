#pragma once

#include"includer.h"
#include "Animation.h"
#include "Clickable.h"
#include "Field.h"
class Player;

struct Func {
	string feature; // battlecry deathrattle ongoing
	function <void(Clickable*, Field*, int) > func; // function of button
};

class Card :public Clickable {
protected:
	int damage = 0; // entity's damage
	int health; // max health

	int id; // special id of a card
	string gameClass;

	string picPath;
	string name;
	int cost;//how much does it cost
	string type; // danger level
	
	string description; // what is this card do
	vector<Func> funcs;

	bool isTaken; // i want to use it
	bool isChoosen;// i want to see what does it do

	Animation animation;
	float animationTimer = 0;

	//SFML
	sf::Vector2f pos;

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

	int DrawType; // 0 - big, 1 - low, 2 - back, (3 - entity only for creature)

public:
	static int ANIMATION_SPEED;

	Card();
	Card(Card* card);
	~Card();

	string getGameClass();

	string getPicPath();
	int getId();

	void setPos(sf::Vector2f pos);

	void viewLow(bool isTop = false);
	void viewBack(bool isTop = false);

	void Display(int& space, float time, int mana, bool& chosen, bool deckFirst, bool isFirst, bool isTop, Clickable* initiator);

	virtual void copy(Card* card);
	void setTexture();
	virtual void viewBig();
	virtual void drawCard(sf::RenderWindow& window, int DrawType = -1);

	//ANIMATIONS
	void AnimationTakeCard(bool isFirst, float timeLeft = 0);


};