#include "headers\\Screen.h"

const sf::Vector2f BUTTON_SIZE = sf::Vector2f(500, 120);

Screen::Screen(CDB* cdb) {
	this->cdb = cdb;
	deckF = new Deck(cdb);
	deckS = new Deck(cdb);

	setMenu();
	Sbg.setTexture(Tbg);

	isOpened = true;
}

Field* Screen::getField() {
	return field;
}
string Screen::getScreenType() {
	return screenType;
}
bool Screen::getIsOpened() {
	return isOpened;
}

void Screen::setCreateDeck() {
	clearButtons();
	screenType = "createDeck";
}
void Screen::setMenu() {
	screenType = "menu";
	Tbg.loadFromFile("pic\\background\\menu.png");

	//creating buttons
	clearButtons();
	
	//start game button
	buttons.push_back(new Button(this, "pic\\button\\PlayMM.png", sf::Vector2f(1300, 500), BUTTON_SIZE, &Screen::setGame));
	
	//create deck button
	buttons.push_back(new Button(this, "pic\\button\\CreateDeckMM.png", sf::Vector2f(1300, 650), BUTTON_SIZE, &Screen::setCreateDeck));
	
	//create exit button
	buttons.push_back(new Button(this, "pic\\button\\ExitMM.png", sf::Vector2f(1300, 800), BUTTON_SIZE, &Screen::exit));

}
void Screen::setGame() {
	clearButtons();

	screenType = "game";
	Tbg.loadFromFile("pic\\background\\menu.png");

	field = new Field(new Player(deckF), new Player(deckS));
	field->startGame();

	//end turn button
	buttons.push_back(new Button(this, "pic\\button\\EndTurnF.png", sf::Vector2f(1627, 505), sf::Vector2f(250,70), &Screen::nextTurn));
}

void Screen::drawCreateDeck(sf::RenderWindow& window) {
	window.clear(sf::Color::White);
}
void Screen::drawMenu(sf::RenderWindow& window) {
	window.clear(sf::Color::White);
	//draw the bg
	window.draw(Sbg);

	int size = buttons.size();
	for (int i = 0; i < size; i++) {
		buttons[i]->draw(window);
	}
}
void Screen::drawGame(sf::RenderWindow& window, float time, Clickable* initiator) {
	window.clear(sf::Color(94, 255, 204));
	field->draw(window, time, initiator);
	buttons[0]->draw(window);
}
void Screen::drawWinScreen(sf::RenderWindow& window, Player* player) {
	// we use window.clear later
	// setting "you won" text
	sf::Font font;
	font.loadFromFile("fonts\\ariali.ttf");
	sf::Text winnerText;
	winnerText.setFont(font);
	winnerText.setPosition(720, 600);
	winnerText.setCharacterSize(80);
	winnerText.setOutlineColor(sf::Color(235, 235, 235));
	winnerText.setOutlineThickness(10);

	//setting sprite of winner person

	player->getPerson()->setPosition(sf::Vector2f(810, 290));
	player->getPerson()->prepare();
	if (!player->getIsFirst()) {
		winnerText.setString("First player won!");
		winnerText.setFillColor(sf::Color(34, 153, 40));

		player->getPerson()->setTexture("pic\\person\\AllyHappy.png");

		window.clear(sf::Color(133, 255, 139)); // light green
	}
	else {
		winnerText.setString("Second player won!");
		winnerText.setFillColor(sf::Color(74, 23, 20));

		player->getPerson()->setTexture("pic\\person\\EnemyHappy.png");

		window.clear(sf::Color(252, 205, 202)); // light red

	}

	window.draw(winnerText);

	winnerText.setPosition(750,710);
	winnerText.setString("press SPACE to continue");
	winnerText.setCharacterSize(40);
	winnerText.setOutlineColor(sf::Color::Transparent);
	winnerText.setOutlineThickness(0);

	window.draw(winnerText);

	player->getPerson()->draw(window, false);
}
void Screen::draw(sf::RenderWindow& window, float time) {
	if (screenType == "menu")
		drawMenu(window);
	else if (screenType == "game")
		drawGame(window, time, initiator);
	else if (screenType == "createDeck")
		drawCreateDeck(window);


	if(screenType != "endGame")
		window.display();
}

void Screen::CloseGame(sf::RenderWindow& window) {
	window.close();
}
void Screen::exit() {
	isOpened = false;
}

void Screen::setDefaultToClick(Clickable*& initiator, vector<int>& targets) {
	initiator = nullptr;
	targets = vector<int>{ 0,2 };
}
void Screen::clearButtons() {
	int size = buttons.size();
	for (int i = 0; i < size; i++) {
		delete buttons[i];
	}
	buttons.clear();
}
void Screen::afterEvent(sf::RenderWindow& window) {
	if (screenType == "game") {
		Player* winStatus = field->deathCheck();
		if (winStatus != nullptr) {
			screenType = "endGame";
			drawWinScreen(window, winStatus);
			window.display();
		}
	}
}

void Screen::playEvent(sf::Event event) {
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::P) {
			isOpened = false;
		}
	}
	if (event.type == sf::Event::MouseButtonPressed) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			int size = buttons.size();
			for (int i = 0; i < size; i++) {
				if (buttons[i]->isMovedOn()) {
					buttons[i]->use();
					break;
				}
			}
		}
	}
	if (screenType == "game") {
		if (event.type == sf::Event::MouseButtonPressed) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				if (field->getIsStarted()) {
					buff = field->useCheck(targets);
					if (buff != nullptr) {
						if (initiator == nullptr) {
							if (buff->getIsInitiator()) {
								initiator = buff;
								targets = initiator->getTargets();
							}
						}
						else {
							if (buff->getIsTargetable()) {
								initiator->use(buff, field->getCurPlayer(), field);
								buff = nullptr;
								setDefaultToClick(initiator, targets);
							}
						}
					}
				}
			}
			else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
				if (field->getIsStarted()) {
					setDefaultToClick(initiator, targets);
				}
			}
		}
	}
	else if (screenType == "menu") {

	}
	else if (screenType == "endGame") {
		if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::Space) {
				setMenu();
			}
		}
	}
}

void Screen::nextTurn() {
	field->nextTurn();
	setDefaultToClick(initiator, targets);

	
}