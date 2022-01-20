#include "headers\\Animation.h"
#include "cmath"
static int STEPS = 20;


sf::Vector2f Animation::calculateStep(sf::Vector2f A, sf::Vector2f B) {
	swap(A, B);
	firstStart = false;
	isStopped = false;
	step = sf::Vector2f((A.x - B.x) / STEPS, (A.y - B.y) / STEPS);
	return step;
}

bool Animation::Move(sf::Vector2f& pos) {// dont forget to reset position
	if (isStopped) {
		firstStart = true;
		turns = 0;
		step = sf::Vector2f(0,0);
		animationType = "";
		return false;
	}

	pos.x += step.x;
	pos.y += step.y;
	turns++;

	if (turns >= STEPS)
		isStopped = true;

	return true;
}