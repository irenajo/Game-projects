#include "../headers/Game.h"

int main()
{
    //Init game engine
    Game game;
    // //Game loop
    while(game.running())
    {
        game.update();
        game.render();
    }
    
    //End of the program
    return 0;
}
