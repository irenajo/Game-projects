#include "../headers/game.h"
#include <iostream>

//Private functions

void Game::initVariables(){
    this->window = nullptr;
    this->player = new Player();
    this->food = new Food();
}
void Game::initWindow(){
    this->videoMode.height = this->windowHeight;
    this->videoMode.width = this->windowWidth;
    this->window = new sf::RenderWindow(this->videoMode,"naslov",sf::Style::Titlebar|sf::Style::Close);

    this->window->setFramerateLimit(60); //144hz
}

//Constructior/Destructor
Game::Game(){
    this->initVariables();
    this->initWindow();
}
Game::~Game(){
    delete this->window;
}
//Accessors
const bool Game::running(){
    return this->window->isOpen();
}
const float Game::getDeltaTime(){
    return this->intendedFps*this->elapsedTime.asSeconds();
}
void Game::game_end(){
    has_ended = true;
    std::cout << "Game ended. Score: " << player->get_score() << std::endl;
}

void Game::game_start(){
    has_ended = false;
    std::cout << "Game started." << player->get_score() << std::endl;
    delete player;
    delete food;
    this->player = new Player();
    this->food = new Food();
}
//Functions
void Game::update(){
    this->pollEvents();
    if(has_ended) return;
    this->elapsedTime = this->Clock.getElapsedTime();
    if(elapsedTime < sf::seconds(0.1)) return;
    this->Clock.restart();

    player->move_player(getDeltaTime()); //DELTA?
    player->has_eaten(food);
    if (player->is_colliding()) game_end();

}
/*
    Provera event-ova. Pomeranje igraca.
    deltatime nekako mora uticati na brzinu lopte i igraca.
*/
void Game::pollEvents(){
    while(this->window->pollEvent(this->ev)){
        switch(this->ev.type){
            case sf::Event::Closed:
                this->window->close();break;
            case sf::Event::KeyPressed:
                switch(this->ev.key.code){
                    case sf::Keyboard::Escape:
                        window->close();break;
                    case sf::Keyboard::Up:
                        player->face_up();
                        break;
                    case sf::Keyboard::Down:
                        player->face_down();
                        break;
                    case sf::Keyboard::Left:
                        player->face_left();
                        break;
                    case sf::Keyboard::Right:
                        player->face_right();
                        break;
                    case sf::Keyboard::R:
                        if(has_ended) game_start();
                }
               break;
        }
    }
}
void Game::render(){
    this->window->clear();
    food->draw_food(this->window);
    player->draw_player(this->window);
    this->window->display();
}