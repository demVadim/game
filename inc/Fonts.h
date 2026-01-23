#pragma once
#include <iostream>
#include <string.h>
#include <SFML/Graphics.hpp>

class Fonts :public sf::Font
{
private:
    void InitFonts(std::string address);
public:
    Fonts(std::string address);
    ~Fonts();
};


