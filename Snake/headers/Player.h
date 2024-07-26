#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <deque>
#include <SFML/Graphics.hpp>
#include "Constants.h"
#include "Food.h"
class Food;

class Player{
private:
    std::deque<sf::RectangleShape*> m_body;
    int m_speed = S_SPEED;
    char m_dir_y = 0; // -1 up, 1 down, 0 if no movement
    char m_dir_x = 1; // 1 left, -1 right, 0 if no movement
    int m_size = 1;

    sf::RectangleShape* create_cell(int pos_x, int pos_y);
    //int from explains from which cell in body should we check for collision with pos. By default it checks whole body, from head.
    bool is_in_body(sf::Vector2f pos, int from = 0);

public:
    Player();
    void draw_player(sf::RenderWindow *window);
    //Vrv nam ne treba delta, kolko treba u update da racunamo samo kad prodje odredjeno vreme!
    void move_player(int delta);
    bool has_eaten(Food* food);
    bool is_colliding();

    void add_cell(sf::Vector2f pos);
    void face_left();
    void face_right();
    void face_up();
    void face_down();

    int get_score();
};

#endif