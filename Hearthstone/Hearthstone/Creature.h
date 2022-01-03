#pragma once
#define block
class Creature:public Card
{
private:
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
		this->description = description;

		this->damage = damage;
		this->health = health;
		this->id = id;
		this->picPath = picPath;
		this->gameClass = "Creature";

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

		this->gameClass = "Creature";
		setTexture();
	}



#endif

	int getDamage() {
		return damage;
	}
	int getHealth() {
		return health;
	}

	void copy(Card* card) {
		Card::copy(card);
		this->damage = card->getDamage();
		this->health = card->getHealth();
	}

	void use(Player* currP) {
		cout << name << " used for " << cost << "!\n";

		currP->createEntity(this);
	}
	void viewBig(sf::Vector2f pos) {
		Card::viewBig(pos);
		Sdamage = sf::Sprite(Tvalue);
		Sdamage.setPosition(sf::Vector2f(pos.x - 12, pos.y + 350));

		Tdamage.setFont(font);
		Tdamage.setString(to_string(damage));
		Tdamage.setCharacterSize(50);
		Tdamage.setPosition(sf::Vector2f(pos.x + 8, pos.y + 350));
		Tdamage.setFillColor(sf::Color::Red);

		Shealth = sf::Sprite(Tvalue);
		Shealth.setPosition(sf::Vector2f(pos.x + 262, pos.y + 350));

		Thealth.setFont(font);
		Thealth.setString(to_string(health));
		Thealth.setCharacterSize(50);
		Thealth.setPosition(sf::Vector2f(pos.x + 282, pos.y + 350));
		Thealth.setFillColor(sf::Color::Green);
	}
	void viewLow(sf::Vector2f pos) {
		Card::viewLow(pos);
	}
	void drawCard(sf::RenderWindow& window) {
		Card::drawCard(window);
		if(DrawType == 0) {
			window.draw(Sdamage);
			window.draw(Tdamage);
			window.draw(Shealth);
			window.draw(Thealth);
		}
	}
};

