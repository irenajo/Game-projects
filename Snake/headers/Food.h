#ifndef _FOOD_H_
#define _FOOD_H_

#include <SFML/Graphics.hpp>
#include "Constants.h"
class Food{
    friend class Player;
private:
    sf::RectangleShape m_body;

    sf::Vector2f get_rand_position(){   //in range 1 -> (screen_h / cell_size - 1)
        int rand_x = rand() % (SCREEN_H / CELL_SIZE - 1) + 1;
        int rand_y = rand() % (SCREEN_H / CELL_SIZE - 1) + 1;
        return sf::Vector2f(rand_x * CELL_SIZE, rand_y * CELL_SIZE);
    }
    int get_x(){
        return m_body.getPosition().x;
    }
    int get_y(){
        return m_body.getPosition().y;
    }
public:
    Food(){
        m_body.setSize(sf::Vector2f(CELL_SIZE,CELL_SIZE));
        m_body.setFillColor(sf::Color::Red);
        m_body.setPosition(get_rand_position());
    }
    void draw_food(sf::RenderWindow *window){
        window->draw(m_body);
    }
};

#endif