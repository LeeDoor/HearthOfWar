#pragma once
class Card
{
protected:
	
	int id; // special id of a card


	string name;
	int cost;//how much does it cost
	string fraction; // fraction, nation (own country)
	vector<string> feature; // special property
	vector<string> funcFeat; // function of special property (func has same position as feature -- 0 id is battlecry, 0 id is battlecry(**){**})
	string description; // what is this card do
public:
	virtual void use() {}
	virtual string view() { return name; }

};

