#include "Ball.h"
#include "Player.h"
/*
    Da li cu imati duplo player.h kad se sve compiluje?
*/

Ball::Ball(sf::Vector2f startPos, int win_h, int win_w): win_height(win_h), win_width(win_w), startPos(startPos){
    body.setSize(sf::Vector2f(BALL_SIZE,BALL_SIZE));
    body.setPosition(startPos);
}

void Ball::atStartPos(){
    body.setPosition(startPos);
}

void Ball::draw(sf::RenderWindow *window){
    window->draw(body);
}

void Ball::move(float delta){
    sf::Vector2f pos = body.getPosition();
    pos.y += dir_y * speed * delta;
    pos.x += dir_x * speed * delta;
    if(pos.y < 0) {
        pos.y = 0;
        dir_y *= -1;
    }
    else if(pos.y + BALL_SIZE >= win_height) {
        pos.y = win_height - BALL_SIZE;
        dir_y *= -1;
    }
    body.setPosition(pos);
    //std::cout << "Ball x: " << pos.x << " Ball y: " << pos.y << std::endl;
}


/*
    Changes direction of ball if collided with walls.
    Returns -1 if hit left wall, 1 if hit right, 0 otherwise.
    If -1, right player scored, and vice versa.
*/
int Ball::Scored(){
    sf::Vector2f pos = body.getPosition();
    if(pos.x <= 0){
        // pos.x = 0;
        // dir_x *= -1;
        return -1;
    }    
    else if(pos.x + BALL_SIZE >= win_width){
        // pos.x = win_width - BALL_SIZE;
        // dir_x *= -1;
        return 1;
    }      
    return 0;
}

bool Ball::checkPlayerCollision(Player &left, Player &right){
    sf::Vector2f leftPos = left.getPos();
    sf::Vector2f rightPos = right.getPos();
    sf::Vector2f ball = this->body.getPosition();
    
    //left player collision
    if ( (ball.x <= leftPos.x + PLAYER_SIZE.x && ball.x >= leftPos.x) &&
        ((ball.y >= leftPos.y && ball.y <= leftPos.y + PLAYER_SIZE.y) || 
        (ball.y + BALL_SIZE >= leftPos.y && ball.y < leftPos.y + PLAYER_SIZE.y - BALL_SIZE))){
            dir_x *= -1;
            std::cout << "Collided left: bx " << ball.x << " by " << ball.y << " px " << leftPos.x << " py " << leftPos.y << ";\n";
            return true;
        }
    //right player collision
    else if ( (ball.x + BALL_SIZE >= rightPos.x && ball.x + BALL_SIZE <= rightPos.x + PLAYER_SIZE.x) &&
        ((ball.y >= rightPos.y && ball.y <= rightPos.y + PLAYER_SIZE.y) || 
        (ball.y + BALL_SIZE >= rightPos.y && ball.y < rightPos.y + PLAYER_SIZE.y - BALL_SIZE))){
            dir_x *= -1;
            std::cout << "Collided r: bx " << ball.x << " by " << ball.y << " px " << rightPos.x << " py " << rightPos.y << ";\n";
            return true;
        }
    return false;
}