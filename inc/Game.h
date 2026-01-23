#pragma once
#include <string.h>
#include <iostream>

#include <SFML/Graphics.hpp>
#include "Times.h"

class Game
{
private:
    unsigned int width;
    unsigned int height;
    std::string title;
    sf::VideoMode vm;
    sf::RenderWindow* window;

    Times times;

    void initWindow();
    void pollEvents();
    void updating();
    void rendering();
    
public:
    Game();
    ~Game();

    void runing();
};
