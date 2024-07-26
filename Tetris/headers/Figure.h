#ifndef _FIGURE_H_
#define _FIGURE_H_
#include "Constants.h"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

class Figure{
private:

struct Point{
    int x;
    int y;
    Point(int x, int y): x(x), y(y) {};
    Point(){};
};

    Point matrix_zero_pos = {500, 0};
    sf::RectangleShape rs = sf::RectangleShape(sf::Vector2f(cst::cell_size, cst::cell_size));
    int body[cst::N][cst::N];

void init_matrix(std::vector<Point> points);

public:
    Figure();

    void draw(sf::RenderWindow* w);
    void update(); 
    void rotate();
};

#endif