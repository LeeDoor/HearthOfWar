#pragma once
class MilFor :public Card
{
public:
	MilFor() {}

	MilFor(
		string name,
		int cost,
		string fraction,
		vector<string> feature,
		vector<string> funcFeat,
		string description,
		int id = -1) 
	{
		this->name = name;
		this->cost = cost;
		this->fraction = fraction;
		this->feature = feature;
		this->funcFeat = funcFeat;
		this->description = description;
		this->id = id;
	}
	
	MilFor(
		string name,
		int cost,
		string fraction,
		string description,
		int id = -1)
	{
		this->name = name;
		this->cost = cost;
		this->fraction = fraction;
		this->description = description;
		this->id = id;
	}

	void use() {}
};

