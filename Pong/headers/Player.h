#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <iostream>
#include <SFML/Graphics.hpp>

static sf::Vector2f PLAYER_SIZE = sf::Vector2f(15,70);
static int PLAYER_SPEED = 25;

class Player{
private:
    sf::RectangleShape body;
    sf::Vector2f startPos;
    int speed = PLAYER_SPEED;
    int score = 0;
    int screenHeight;

public:
    // C/D
    Player(sf::Vector2f startPos, int screenHeight);

    // S/G
    sf::Vector2f const getPos();

    // Public Functions
    void atStartPos();
    void draw(sf::RenderWindow *window);
    void move(int direction, float delta);
    void addPoint();


};

#endif