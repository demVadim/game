#include <SFML/Graphics.hpp>



int main()
{

    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({1024,768}), "Title");


    while(window->isOpen())
    {


        while(const std::optional event = window->pollEvent())
        {
            if(event->is<sf::Event::Closed>()){
                
                window->close();
            }
            else if(const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()){

                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape){
                   
                    window->close(); 
                }
            }

        }

        //render
        window->clear(sf::Color(255,165,0));
        //draw

        window->display();
    }


    delete window;
    return 0;
}