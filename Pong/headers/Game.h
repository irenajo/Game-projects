#ifndef _GAME_H_
#define _GAME_H_
#include <SFML/Graphics.hpp>
// #include <SFML/System.hpp>
// #include <SFML/Window.hpp>
// #include <SFML/Audio.hpp>
// #include <SFML/Network.hpp>

#include "Player.h"
#include "Ball.h"
class Player;
/*
    Game engine class
*/

class Game
{
    private:
        //Variables
        sf::RenderWindow* window;
        sf::Event ev;
        sf::VideoMode videoMode;
        
        int intendedFps = 144;
        sf::Clock Clock;
        sf::Time elapsedTime;

        int roundRunning = 0;

        //Game objects
        Player* player1; //levi, W/S
        Player* player2; //desni, arrowkeys
        Ball* ball;

        //Private functions
        void initVariables();
        void initWindow();

        void pollEvents();
        int isPaused(){ return !roundRunning; }; 
        /*
            Starts new round. Doesn't update points, only positions.
        */
        void start();

    public:
        int windowWidth = 800;
        int windowHeight = 600;
        //Constructor/Destructor
        Game();
        virtual ~Game();
        //Accessors
        const bool running();
        const float getDeltaTime();
        //Functions
        void update();
        void render();

};

#endif


