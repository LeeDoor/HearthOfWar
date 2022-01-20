#pragma once
#include"includer.h"
class Screen;
class Button
{
private:
	Screen* screen;

	sf::RectangleShape hitbox;
	void (Screen::* func)(); // function of button


	sf::Texture Tpic;
	sf::Sprite Spic;
public:
	Button(Screen* screen, string path, sf::Vector2f pos, sf::Vector2f size, void (Screen::* func)());

	void use(); // calls function "func"
	void draw(sf::RenderWindow& window);
	bool isMovedOn();
};

