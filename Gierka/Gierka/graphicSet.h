#pragma once
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>





#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>


class GraphicSet
{
public:

	int windowHeight;
	int windowWidth;
	std::string style; 
	int FramerateLimit; 
	std::string  verticalSync;
	sf::VideoMode videoMode;
	std::string name;



	
	GraphicSet(std::string nameFile);

	GraphicSet(int windowHeight,
	int windowWidth,
	sf::RenderWindow style,
	int FramerateLimit,
	bool verticalSync);

	~GraphicSet();
};