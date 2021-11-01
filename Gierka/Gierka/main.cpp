#include <iostream>
#include "Game.h"

int main()
{

    // Init srand 

    std::srand(static_cast<unsigned>(time(NULL)));
    // init game engine 
    Game game;



    // game loop 

    while (game.running() && !game.getEndGame()) // while when true
    {
        // Update 
        game.update();
        // Render 

        game.render();

    }

    return 0;
}
