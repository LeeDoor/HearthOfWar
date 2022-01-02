#pragma once
class Event :public Card
{
public:
	Event() {}

	Event(
		string name,
		int cost,
		string type,
		vector<string> feature,
		vector<string> funcFeat,
		string description, 
		string picPath,
		int id = -1) 
	{
		this->name = name;
		this->cost = cost;
		this->type = type;
		this->feature = feature;
		this->funcFeat = funcFeat;
		this->description = description;
		this->id = id;
		this->picPath = picPath;
		this->gameClass = "Event";
	}
	
	Event(
		string name,
		int cost,
		string type,
		string description, 
		string picPath,
		int id = -1)
	{
		this->name = name;
		this->cost = cost;
		this->type = type;
		this->description = description;
		this->id = id;
		this->picPath = picPath;
		this->gameClass = "Event";
	}

	void copy(Card* card) {
		Card::copy(card);
	}
	void use() {}

	void viewBig(sf::Vector2f pos) {
		Card::viewBig(pos);
	}
	void viewLow(sf::Vector2f pos) {
		Card::viewLow(pos);
	}
	void drawCard(sf::RenderWindow& window) {
		Card::drawCard(window);
		
	}
};

