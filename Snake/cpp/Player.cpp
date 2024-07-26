#include "Player.h"
#include <iostream>

sf::RectangleShape* Player::create_cell(int pos_x, int pos_y){
    sf::RectangleShape* new_cell = new sf::RectangleShape();
    new_cell->setSize(sf::Vector2f(CELL_SIZE,CELL_SIZE));
    new_cell->setFillColor(sf::Color::Green);
    new_cell->setPosition(pos_x, pos_y);
    return new_cell;
}

Player::Player(){
    sf::RectangleShape* sh = create_cell(SCREEN_W/2, SCREEN_H/2);
    m_body.push_front(sh);
}
void Player::draw_player(sf::RenderWindow *window){
    for(sf::RectangleShape* cell: m_body){
        if (cell) window->draw(*cell);
    }
}

void Player::move_player(int delta){
    // Update the head's position
        sf::Vector2f pos = m_body[0]->getPosition();
        sf::Vector2f prev_pos = pos;
        pos.x += m_dir_x * CELL_SIZE;
        pos.y += m_dir_y * CELL_SIZE;
        m_body[0]->setPosition(pos);
        
    // Update the body's position

    for(int i = 1; i < (int)m_body.size(); i++){
        sf::Vector2f temp = prev_pos;
        prev_pos = m_body[i]->getPosition();
        m_body[i]->setPosition(temp);
    }
    if((int)m_body.size() < m_size){
        this->add_cell(prev_pos);
    }
}

bool Player::has_eaten(Food* food){
    sf::Vector2f pos = m_body[0]->getPosition();
    //True if snake head's next position is the food's position.
    if(pos.x == food->get_x() && pos.y == food->get_y()){
            //Add size to snake and move food to new random position outside of snake's body. Doesn't add cell. This is done in move_player.
            m_size++;
            sf::Vector2f new_pos;
            //while(is_in_body((new_pos = food->get_rand_position()))); TESTIRAJ DA LI OVO RADI?
            do{
                new_pos = food->get_rand_position();
            }while(is_in_body(new_pos));
            food->m_body.setPosition(new_pos);
            return true;
        }
    std::cout << ".";
    return false;
}

bool Player::is_colliding(){
    //Checks colliding with self
    sf::Vector2f head = this->m_body[0]->getPosition();
    if(is_in_body(head,1)) return true;
    //Checks colliding with wall
    if(head.x <= 0 || head.x >= SCREEN_W || head.y <= 0 || head.y >= SCREEN_H) return true;
    else return false;
}

bool Player::is_in_body(sf::Vector2f pos, int from) {
    for(int i = from; i < m_body.size(); i++){
        if(pos == m_body[i]->getPosition()) return true;
    }
    return false;
}

void Player::add_cell(sf::Vector2f pos){
    //this->create_cell(m_body[0]->getPosition().x + CELL_SIZE*m_dir_x, m_body[0]->getPosition().y + CELL_SIZE*m_dir_y)
    m_body.push_back(this->create_cell(pos.x, pos.y));
}
void Player::face_left()  { if (m_size>1 && m_dir_x) return; m_dir_x = -1; m_dir_y = 0; }
void Player::face_right() { if (m_size>1 && m_dir_x) return; m_dir_x = 1; m_dir_y = 0;  }
void Player::face_up()    { if (m_size>1 && m_dir_y) return; m_dir_x = 0; m_dir_y = -1; }
void Player::face_down()  { if (m_size>1 && m_dir_y) return; m_dir_x = 0; m_dir_y = 1;  }

int Player::get_score(){
    return m_size;
}
