#include "Game.h"

void Game::initVariables()
{
	
}

void Game::initWindow()
{
	this->videoMode.height = this->graphicSet->windowHeight;
	this->videoMode.width = this->graphicSet->windowWidth;

	if (this->graphicSet->style == "true")
	{
		this->window = new sf::RenderWindow(this->videoMode, this->graphicSet->name, sf::Style::Fullscreen);
	}
	else
	{
		this->window = new sf::RenderWindow(this->videoMode, this->graphicSet->name, sf::Style::Close | sf::Style::Titlebar);

	}

	this->window->setFramerateLimit(this->graphicSet->FramerateLimit);
	if (this->graphicSet->verticalSync == "true")
	{
		this->window->setVerticalSyncEnabled(true);

	}
	// Game logic
	this->endGame = false;
}

void Game::initGraphicSet(std::string filename)
{
	this->graphicSet = new GraphicSet(filename);
}

Game::Game()
{
	this->initGraphicSet("graphicSet.txt");
	this->initWindow();
	this->initVariables();

	this->loadConfFile();

}

Game::~Game()
{
	delete this->window;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

const bool Game::getEndGame() const
{
	return this->endGame;
}

void Game::pollEvents()
{
	// Event polling
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)   // mouse click, type some letters
		{
		case sf::Event::Closed:  // closing window 
			this->window->close();
			break;


		case sf::Event::KeyPressed:
			if (this->ev.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}



void Game::update()
{

	this->pollEvents();
	if (this->endGame == false)
	{
		
		square.updateSquare();

	}
	handleInput();

}



void Game::render()
{

	this->window->clear();

	// Draw objects 
	square.renderSquare(*this->window);
	this->window->display();
}

void Game::loadConfFile()
{
	std::fstream file;
	std::string line;
	

	file.open("configurationFile.txt", std::ios::in);
	if (file.good() == true)
	{

		while (!file.eof()) // eof end of file
		{
			getline(file,line);
			std::stringstream ss(line);
			std::string name; 
			int number; 
			
			

			ss >> name;
			ss >> number; 
			
			config.insert({name,number});
		}
	}
	else
	{
		std::cout << "File didnt open"; 
		return;
	}
	
	for (auto i : config)
	{
		std::cout << i.first << i.second << std::endl; 
	}

}


void Game::handleInput()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(config.at("up"))))
	{
		square.move(directions::up);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(config.at("down"))))
	{
		square.move(directions::down);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(config.at("left"))))
	{
		square.move(directions::left);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(config.at("right"))))
	{
		square.move(directions::right);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(config.at("changeColor"))))
	{
		square.changeColor();
	}

}
