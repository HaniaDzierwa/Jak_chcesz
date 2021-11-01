#pragma once

#include <vector>
#include <ctime>
#include <sstream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Const.h"
 
class Square
{
private:
	// Game object 
	sf::RectangleShape square; 
	float velocity; 
	std::vector <sf::Color> colorSequence;
	sf::Clock clock; 
	
	int colorCounter;
	void initSquare();
	void initColors(); 
	





public:
	// Constructors / Destructors
	Square();
	virtual ~Square();

	void changeColor();
	void move(directions direction);
	void updateSquare();
	void renderSquare(sf::RenderTarget& target);
};
