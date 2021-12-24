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
		int id = -1) 
	{
		this->name = name;
		this->cost = cost;
		this->type = type;
		this->feature = feature;
		this->funcFeat = funcFeat;
		this->description = description;
		this->id = id;
	}
	
	Event(
		string name,
		int cost,
		string type,
		string description,
		int id = -1)
	{
		this->name = name;
		this->cost = cost;
		this->type = type;
		this->description = description;
		this->id = id;
	}

	void use() {}
};

