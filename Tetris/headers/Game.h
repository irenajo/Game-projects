#ifndef _GAME_H_
#define _GAME_H_
#include <SFML/Graphics.hpp>
// #include <SFML/System.hpp>
// #include <SFML/Window.hpp>
// #include <SFML/Audio.hpp>
// #include <SFML/Network.hpp>

class Figure;

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

        //Game objects
        Figure* f;

        // << current object, matrica >>

        //Private functions
        void initVariables();
        void initWindow();

        void pollEvents();
    public:
        //Constructor/Destructor
        Game();
        virtual ~Game();
        //Accessors
        const bool running();
        const float getDeltaTime();
        //Functions
        
        // Calculates game logic. After, checks for events (inputs from user)
        void update();

        // Draws object on window alooooooooooooooooooooo
        void render();

};

#endif


