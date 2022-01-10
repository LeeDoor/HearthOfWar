#pragma once
#include"headers\\Clickable.h"
#include"headers\\includer.h"


class Person :public Clickable
{
private:
	int health;
	
	//SFML
	sf::Font font;

	sf::Vector2f pos;
	sf::Texture Tpic;
	sf::Sprite Spic;
	sf::Text Thp;

	bool isFirst;

public:
	Person(bool isFirst);

	int getHealth();
	void setTexture(string path); // set texture by path
	void setPosition(sf::Vector2f pos);
	void acceptAttack(int damage); // func for taking damage
	void update(); // changing hp parameter

	void prepare();// setting positions, colors, fonts etc
	void draw(sf::RenderWindow& window, bool drawHp = true);
};

