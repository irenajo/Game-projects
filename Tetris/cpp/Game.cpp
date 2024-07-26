#include "../headers/game.h"
#include <iostream>
#include "../headers/Figure.h"
//Private functions


void Game::initVariables(){
    // init current object, init matrix 
    this->window = nullptr;
    this->f = new Figure();

}
void Game::initWindow(){
    this->videoMode.height = cst::window_height;
    this->videoMode.width = cst::window_width;
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
//Functions
void Game::update(){
    this->elapsedTime = this->Clock.getElapsedTime();

    // na jednu sekundu radimo game logiku KAO I EVENT POLLING
    if(elapsedTime < sf::seconds(1)) return;

    this->Clock.restart();
    //std::cout << getDeltaTime() << std::endl;
    this->Clock.restart();
    f->update();
    f->rotate();

    this->pollEvents();
    
}

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
                        break;
                    case sf::Keyboard::Down:
                        break;
                }
               break;
        }
    }
}
void Game::render(){
    this->window->clear();

    // sf::RectangleShape r;
    // r.setSize(sf::Vector2f(50,50));
    // r.setPosition(sf::Vector2f(250,250));
    f->draw(window);
    this->window->display();
}