#ifndef _BALL_H_
#define _BALL_H_

#include <iostream>
#include <SFML/Graphics.hpp>

static int BALL_SPEED = 2;
static int BALL_SIZE = 15;

class Player;

class Ball{
private:
    sf::RectangleShape body;
    sf::Vector2f startPos;
    int speed = BALL_SPEED; //mozes izbaciti ovo
    int win_height, win_width;
    int dir_y = 1;
    int dir_x = 1;

public:
    Ball(sf::Vector2f startPos, int win_h, int win_w);
    void atStartPos();
    void move(float delta);
    void draw(sf::RenderWindow *window);
    int Scored();
    bool checkPlayerCollision(Player &left, Player &right);

};

#endif