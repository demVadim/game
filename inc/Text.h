#pragma once
#include <sstream>
#include "Fonts.h"

class Text : public sf::Text
{
private:
    
    std::string oroginalStr;
    Fonts *fonts;
    void initFont(std::string font_address);
    void initString(std::string str);
public:

    Text(std::string str, std::string font_address);
    ~Text();
    void streamText(std::string str="",float var = 0.0f);
};


