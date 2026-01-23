#include "Game.h"

inline void Game::initWindow(){
    unsigned int width=640;
    unsigned int height=360;
    title = "sfml game";
    vm = sf::VideoMode({width,height});
    window = new sf::RenderWindow(vm,title);
    window->setFramerateLimit(60);
}

void Game::pollEvents(){

    while(const std::optional event = window->pollEvent()){
            
        if(event->is<sf::Event::Closed>()){
                
                window->close();
            }
            else if(const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()){

                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape){
                   
                    window->close(); 
                }
            }

        }
}

void Game::updating(){

    pollEvents();

    times.nextDeltaTime();
    std::cout<<times.getDeltaTime()<<std::endl;
}

void Game::rendering(){

        window->clear(sf::Color(255,165,0));
        //draw
        window->display();
}

Game::Game(){
    initWindow();
}

Game::~Game(){
    delete window;
}

void Game::runing(){

    while(window->isOpen()){
        
        updating();
        rendering();
    }
    
}
