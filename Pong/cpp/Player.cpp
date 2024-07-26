#include "Player.h"

Player::Player(sf::Vector2f startPos, int screenHeight){
    body.setSize(PLAYER_SIZE);
    body.setPosition(startPos);
    this->startPos = startPos;
    this->screenHeight = screenHeight;
}

void Player::atStartPos(){
    body.setPosition(startPos);
}

sf::Vector2f const Player::getPos(){
    return this->body.getPosition();
}

void Player::draw(sf::RenderWindow *window){
    window->draw(body);
}

void Player::move(int direction, float delta){
    sf::Vector2f pos = body.getPosition();
    pos.y += delta * speed * direction;
    if(pos.y <= 0) pos.y = 0;
    if(pos.y + body.getSize().y >= screenHeight) pos.y = screenHeight - body.getSize().y;
    body.setPosition(pos);
}

void Player::addPoint(){
    score++;
    std::cout << "Player new score: " << score << std::endl;
}