#include "../headers/game.h"
//Private functions


void Game::initVariables(){
    this->window = nullptr;
    this->player1 = new Player(sf::Vector2f(50, (windowHeight-PLAYER_SIZE.y/2)/2), windowHeight);
    this->player2 = new Player(sf::Vector2f(windowWidth - 50, (windowHeight-PLAYER_SIZE.y/2)/2), windowHeight);
    this->ball = new Ball(sf::Vector2f(windowWidth/2,windowHeight/2),windowHeight, windowWidth);
}
void Game::initWindow(){
    this->videoMode.height = this->windowHeight;
    this->videoMode.width = this->windowWidth;
    this->window = new sf::RenderWindow(this->videoMode,"naslov",sf::Style::Titlebar|sf::Style::Close);

    this->window->setFramerateLimit(60); //144hz
}
void Game::start(){
    player1->atStartPos();
    player2->atStartPos();
    ball->atStartPos();
    roundRunning = 1;
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
    this->Clock.restart();

    this->pollEvents();
    //1. loptica otisla van ekrana, daj poene
    if (!isPaused()){
        ball->move(getDeltaTime());
        int scored = ball->Scored();
        if(scored){
            if(scored == -1) player2->addPoint();
            if(scored == 1) player1->addPoint();
            roundRunning = 0;
        }
        ball->checkPlayerCollision(*player1, *player2);
    } 
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
                if (this->isPaused()) start();
                switch(this->ev.key.code){
                    case sf::Keyboard::Escape:
                        window->close();break;
                    case sf::Keyboard::W:
                        player1->move(-1, getDeltaTime());
                        break;
                    case sf::Keyboard::S:
                        player1->move(1, getDeltaTime());
                        break;
                    case sf::Keyboard::Up:
                        player2->move(-1, getDeltaTime());
                        break;
                    case sf::Keyboard::Down:
                        player2->move(1, getDeltaTime());
                        break;
                }
               break;
        }
    }
}
void Game::render(){
    this->window->clear();

    player1->draw(this->window);
    player2->draw(this->window);
    ball->draw(this->window);

    this->window->display();
}