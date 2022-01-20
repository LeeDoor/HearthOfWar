#pragma once
#include "includer.h"
class Animation
{
private:
public:
	string animationType = "";

	bool isStopped = true;
	bool firstStart = true;
	sf::Vector2f step;
	int turns = 0;
	sf::Vector2f calculateStep(sf::Vector2f A, sf::Vector2f B);
	bool Move(sf::Vector2f& pos); // drawing animation of moving obj from A to B

	
};

