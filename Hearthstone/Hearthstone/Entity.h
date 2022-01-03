#pragma once
class Entity {
private:
	int damage, health;

	vector<string> feature; // special property
	vector<string> funcFeat; // function of special property (func has same position as feature -- 0 id is battlecry, 0 id is battlecry(**){**})
	
	Creature* parent; // our daddy. this card will be drawing as a creator of entity. ebat ya englishman
	//SFML
	sf::Text Tdamage;
	sf::Text Thealth;
	sf::Sprite Sdamage;
	sf::Sprite Shealth;

	sf::Texture Tpic;
	sf::CircleShape circle;
public:
	Entity() {}
	Entity(Creature* parent) {
		this->damage = parent->getDamage();
		this->health = parent->getHealth();

		this->feature = parent->getFeautre();
		this->funcFeat = parent->getFuncFeat();
		
		this->Tpic.loadFromFile(parent->getPicPath());

		Creature* buff;
		buff->copy(parent);
		this->parent =buff;

	}


	void draw(sf::Vector2f pos, sf::RenderWindow& window) {
		circle = sf::CircleShape(50);
		circle.setTexture(&Tpic);

		window.draw(circle);
	}
};