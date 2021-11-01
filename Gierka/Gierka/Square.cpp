#include "Square.h"


void Square::initSquare()
{
    this->square.setPosition(10.f, 10.f);
    this->square.setSize(sf::Vector2f(100.f, 100.f));
    this->square.setFillColor(sf::Color::Cyan);
    this->velocity = 10.f;
}

void Square::initColors()
{
    colorSequence.push_back(sf::Color::White);
    colorSequence.push_back(sf::Color::Blue);
    colorSequence.push_back(sf::Color::Yellow);
    colorSequence.push_back(sf::Color::Magenta);

    colorCounter = 0; 
}

Square::Square()
{
    initSquare();
    initColors();
}

Square::~Square()
{

}

void Square::changeColor()
{
    sf::Time elapsed = clock.getElapsedTime();
   
    if (elapsed > sf::seconds(krzysiu_jest_super))
    {
        square.setFillColor(this->colorSequence[this->colorCounter]);
        colorCounter++;
        if (colorCounter == colorSequence.size())
        {
            colorCounter = 0;
        }

        clock.restart();
    }
      
}

void Square::move(directions direction)
{
    if (direction == directions::up)
    {
        square.move(0.f, -this->velocity);
    }
    if (direction == directions::down)
    {
        square.move(0.f, this->velocity);
    }
    if (direction == directions::left)
    {
        square.move(-this->velocity, 0.f);
    }
    if (direction == directions::right)
    {
        square.move(this->velocity, 0.f);
    }
}

void Square::updateSquare()
{
   
}

void Square::renderSquare(sf::RenderTarget& target)
{

    target.draw(this->square);
}

