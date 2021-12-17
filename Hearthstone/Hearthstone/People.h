#pragma once
#define block
class People:public Card
{
protected:
	int damage; // entity's damage
	int health; // max health
public:
	// constructor
#ifdef block
	People() {}
	People(
		string name,
		int cost,
		string fraction,
		vector<string> feature,
		vector<string> funcFeat,
		string description,
		int damage,
		int health,
		int id = -1
	) {
		this->name = name;
		this->cost = cost;
		this->fraction = fraction;
		this->feature = feature;
		this->funcFeat = funcFeat;
		this->description = description;

		this->damage = damage;
		this->health = health;
		this->id = id;
	}

	People(
		string name,
		int cost,
		string fraction,
		string description,
		int damage,
		int health,
		int id = -1
	) {
		this->name = name;
		this->cost = cost;
		this->fraction = fraction;
		this->description = description;
		this->damage = damage;
		this->health = health;
		this->id = id;
	}

#endif

	void attack() {}
	void use()    {}
	void death () {}

	string doc() {
		string buff ;
		buff += id;
		buff += "  ";
		buff += name;
		buff += "\n";
		buff += description;
		buff += "\n";
		buff += cost;
		buff += " ";
		buff += health;
		buff += " ";
		buff += damage;
		return buff;
	}

	int getdamage(){return damage;}
};

