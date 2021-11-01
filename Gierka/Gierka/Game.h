#pragma once

#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>
#include <fstream>
#include <map>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Const.h"
#include "Board.h"
#include "Square.h"
#include "graphicSet.h"






class Game
{
private: 



	// window
	sf::RenderWindow* window; 
	sf::VideoMode videoMode; 
	sf::Event ev; 


	// Resources 
	sf::Font font; 

	// Text 
	sf::Text uiText; 

	//Game logic 
	bool endGame; 


	// Game object 
	Square square; 
	Board board; 

	GraphicSet *graphicSet; 

	// keybinds
	std::map<std::string, int> config;

	//Private functions 
	void initVariables();
	void initWindow();
	void initGraphicSet(std::string filename);
	
	void loadConfFile();

public : 
	// Constructors / Destructors
	Game();
	virtual ~Game();


	// Accessors 
	const bool running() const;
	const bool getEndGame() const;

	// functions 


	void pollEvents();

	void update();

	void render();

	//configuration 

	

	void handleInput();
	

};