#include "Figure.h"

Figure::Figure(){
        //vector of points for shape, 
        std::vector<Point> points = { {0, 1}, {1, 1}, {2, 1}, {3,1} };
        init_matrix(points);
    }

void Figure::init_matrix(std::vector<Point> points){ //niz od i,j gde zelimo da stavimo jedinicu.
    for (int i = 0; i < cst::N; ++i) {
        for (int j = 0; j < cst::N; ++j) {
            body[i][j] = 0;
        }
    }
    for(auto p : points){
        body[p.x][p.y] = 1;
    }
}

void Figure::draw(sf::RenderWindow* w){
       for (int i = 0; i < cst::N; i++){ //body size
        for (int j = 0; j < cst::N; j++){
            if (body[i][j] == 1) {
                // put a cell to this position, give it color and print it
                sf::Vector2f a  = sf::Vector2f(matrix_zero_pos.x + cst::cell_size*j, matrix_zero_pos.y + cst::cell_size*i);
                rs.setPosition(a);
                w->draw(rs);
                //std::cout << "x : " << a.x << " y : " << a.y << std::endl;
            }
        }
    }
}

void Figure::update(){
        // if is in midair
        matrix_zero_pos.y += cst::cell_size;
    }

void Figure::rotate(){
        for (int i = 0; i < 2; i++) //INACE MORA FLOOR(EXP) OVDE !!!
        {
            int j = 0; //for (int j = 0; i < 4-i-1; i++)
            {
                /* code */
                int tmp = body[i][i+j];
                body[i][i+j] = body[cst::N - i - j][i];
                body[cst::N - i - j - 1][i] = body[cst::N-i-1][cst::N-i-j-1];
                body[cst::N-i-1][cst::N-i-j-1] = body[i+j][cst::N-i-1];
                body[i+j][cst::N-i-1] = tmp;
            }
            std::cout << "IZVRSENA ROTACIJA" << std::endl;

                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        std::cout << body[i][j] << " ";
                    }
                    std::cout << "\n";
                }
            /* code */ // ?????????????????????????????????????
        }
    }