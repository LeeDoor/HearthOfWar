#pragma once
class Card
{
protected:
	
	int id; // special id of a card

	string picPath;
	string name;
	int cost;//how much does it cost
	string type; // danger level
	vector<string> feature; // special property
	vector<string> funcFeat; // function of special property (func has same position as feature -- 0 id is battlecry, 0 id is battlecry(**){**})
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
	Card() {}
	Card(Card* card):
		id(card->id),
		picPath(card->picPath),
		name(card->name),
		cost(card->cost),
		type(card->type),
		feature(card->feature),
		funcFeat(card->funcFeat),
		description(card->description)
	{
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
			Tbg.loadFromFile("pic\\BGketer.png");
		}
		else if (type == "Thaumiel") {
			Tbg.loadFromFile("pic\\BGthaumiel.png");
		}
		else {
			Tbg.loadFromFile("pic\\BGunknown.png");
		}

		hitbox = sf::RectangleShape(sf::Vector2f(160, 200));

	}

	virtual void use() {}

	virtual void viewBig(sf::Vector2f pos) {
		hitbox = sf::RectangleShape(sf::Vector2f(320, 420));
		hitbox.setPosition(sf::Vector2f(pos.x,pos.y+50));

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
		Tdesc.setPosition(sf::Vector2f(pos.x, pos.y));
		Tdesc.setFillColor(sf::Color::Black);

		Scost = sf::Sprite(Tvalue);
		Scost.setPosition(pos);

		Tcost.setFont(font);
		Tcost.setString(to_string(cost));
		Tcost.setCharacterSize(50);
		Tcost.setPosition(sf::Vector2f(pos.x + 20, pos.y));
		Tcost.setFillColor(sf::Color::Blue);
	}
	void viewLow(sf::Vector2f pos, bool isTop = false) {
		if(isTop == false)
			hitbox = sf::RectangleShape(sf::Vector2f(80, 200));
		else {
			
			hitbox = sf::RectangleShape(sf::Vector2f(160, 200));
			hitbox.setFillColor(sf::Color(0,0,0,50));
		}
		hitbox.setPosition(pos);

		Spic = sf::Sprite(Tpic, sf::IntRect(60, 0, 160, 200));
		Spic.setPosition(sf::Vector2f(pos.x, pos.y));
	}
	void viewBack(sf::Vector2f pos) {
		Sbg = sf::Sprite(Tpic, sf::IntRect(0, 0, 160, 200));
		Sbg.setPosition(sf::Vector2f(pos.x + 20, pos.y + 15));
	}
	bool Display(sf::Vector2f pos, bool isFirst = true, bool isTop = false, int chosen = -1) {
		hitbox.setFillColor(sf::Color::Black);

		if (!isFirst) { 
			DrawType = 2;
		}
		else if (hitbox.getGlobalBounds().contains(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y) && chosen == -1) {
			DrawType = 0;
			pos.y -= 260;
		}
		else {
			DrawType = 1;
		}

		switch (DrawType) {
		case 0:
			viewBig(pos);
			return true;

		case 1:
			viewLow(pos, isTop);
			break;

		case 2:
			viewBack(pos);
		}
		return false;
	}
	void drawCard(sf::RenderWindow& window) {
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

