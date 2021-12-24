#pragma once
class Card
{
protected:
	
	int id; // special id of a card

	string picPath;
	string name;
	int cost;//how much does it cost
	string type; // danger lever
	vector<string> feature; // special property
	vector<string> funcFeat; // function of special property (func has same position as feature -- 0 id is battlecry, 0 id is battlecry(**){**})
	string description; // what is this card do

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
	
public:
	virtual void use() {}
	virtual void view(sf::RenderWindow& window, sf::Vector2f pos) {  }

};

