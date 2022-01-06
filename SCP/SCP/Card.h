#pragma once

#include"includer.h"
#include "Animation.h"
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
	sf::RectangleShape hitbox;

public:
	static int ANIMATION_SPEED;

	Card();
	Card(Card* card);

	string getGameClass();

	vector<string> getFeautre();
	vector<string> getFuncFeat();
	string getPicPath();
	int getId();

	void setPos(sf::Vector2f pos);

	void viewLow(bool isTop = false);
	void viewBack( bool isTop = false);

	void Display(int& space, float time, int mana, bool& chosen, bool deckFirst, bool isFirst, bool isTop);

	bool isMovedOn();

	virtual int getDamage() ;
	virtual int getHealth() ;
	virtual void copy(Card* card);
	void setTexture();
	virtual void use(Player* currP);
	virtual void viewBig();
	virtual void drawCard(sf::RenderWindow& window, int DrawType = -1);

	//ANIMATIONS
	void AnimationTakeCard(bool isFirst, float timeLeft = 0);
	
};

