#pragma once
#define block
class Creature:public Card
{
protected:
	int damage; // entity's damage
	int health; // max health

	sf::Text Tdamage;
	sf::Text Thealth;
	sf::Sprite Sdamage;
	sf::Sprite Shealth;
public:
	// constructor
#ifdef block
	Creature() {}
	Creature(
		string name,
		int cost,
		string type,
		vector<string> feature,
		vector<string> funcFeat,
		string description,
		int damage,
		int health,
		string picPath,
		int id = -1
	) {
		this->name = name;
		this->cost = cost;
		this->type = type;
		this->feature = feature;
		this->funcFeat = funcFeat;
		this->description = description;

		this->damage = damage;
		this->health = health;
		this->id = id;
		this->picPath = picPath;


		setTexture();
	}

	Creature(
		string name,
		int cost,
		string type,
		string description,
		int damage,
		int health,
		string picPath,
		int id = -1
	) {
		this->name = name;
		this->cost = cost;
		this->type = type;
		this->description = description;
		this->damage = damage;
		this->health = health;
		this->id = id;
		this->picPath = picPath;

		setTexture();
	}

	void setTexture() {
		Tpic.loadFromFile(picPath, sf::IntRect(0, 0, 280, 180));
		Tvalue.loadFromFile("pic\\BGvalue.png");
		

		if (!font.loadFromFile("BLOODY.TTF"))
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
	}

#endif

	void attack() {}
	void use()    {}
	void death () {}

	void view(sf::RenderWindow& window, sf::Vector2f pos) {
		Sbg = sf::Sprite(Tbg);
		Sbg.setPosition(pos);
		
		Spic = sf::Sprite(Tpic);
		Spic.setPosition(sf::Vector2f(pos.x+20, pos.y+15));

		Ttitle.setFont(font);
		Ttitle.setString(name);
		Ttitle.setCharacterSize(20);
		Ttitle.setPosition(sf::Vector2f(pos.x+20,pos.y+210));
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
		Tcost.setPosition(sf::Vector2f(pos.x+20, pos.y));
		Tcost.setFillColor(sf::Color::Blue);
		
		Sdamage = sf::Sprite(Tvalue);
		Sdamage.setPosition(sf::Vector2f(pos.x-12,pos.y+350));

		Tdamage.setFont(font);
		Tdamage.setString(to_string(damage));
		Tdamage.setCharacterSize(50);
		Tdamage.setPosition(sf::Vector2f(pos.x + 8, pos.y + 350));
		Tdamage.setFillColor(sf::Color::Red);

		Shealth = sf::Sprite(Tvalue);
		Shealth.setPosition(sf::Vector2f(pos.x +262, pos.y + 350));

		Thealth.setFont(font);
		Thealth.setString(to_string(health));
		Thealth.setCharacterSize(50);
		Thealth.setPosition(sf::Vector2f(pos.x + 282, pos.y + 350));
		Thealth.setFillColor(sf::Color::Green);
		
		window.draw(Sbg);
		window.draw(Spic);
		window.draw(Ttitle);
		window.draw(Tdesc);
		window.draw(Scost);
		window.draw(Tcost);
		window.draw(Sdamage);
		window.draw(Tdamage);
		window.draw(Shealth);
		window.draw(Thealth);
	}

};

