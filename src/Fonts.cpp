#include "Fonts.h"

void Fonts::InitFonts(std::string address){

    if (!this->openFromFile(address))
    {
        std::cerr<<"ERROR::FONTS::INITFONTS"<<address<<std::endl;
    }

    this->setSmooth(false);
    
}

Fonts::Fonts(std::string address){

    InitFonts(address);
}

Fonts::~Fonts()
{
}
