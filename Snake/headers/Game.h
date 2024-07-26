#ifndef _GAME_H_
#define _GAME_H_
#include <SFML/Graphics.hpp>
#include "Player.h"
// #include <SFML/System.hpp>
// #include <SFML/Window.hpp>
// #include <SFML/Audio.hpp>
// #include <SFML/Network.hpp>

/*
    POMERI POSLE VVVV
*/
class Food;

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

        bool has_ended = false;

        //Game objects
        Player* player;
        Food* food;
        //Private functions
        void initVariables();
        void initWindow();

        void pollEvents();
        /*
            Starts new round. Doesn't update points, only positions.
        */
    public:
        int windowWidth = SCREEN_W;
        int windowHeight = SCREEN_H;
        //Constructor/Destructor
        Game();
        virtual ~Game();
        //Accessors
        const bool running();
        const float getDeltaTime();
        void game_end();
        void game_start();
        //Functions
        void update();
        void render();

};

#endif


