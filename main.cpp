#include <SFML/Graphics.hpp>



int main()
{
    unsigned int width = 640;
    unsigned int height = 360;
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({width,height}), "Title");
    window->setFramerateLimit(60);



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