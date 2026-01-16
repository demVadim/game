#include <SFML/Graphics.hpp>



int main()
{
    unsigned int width = 640;
    unsigned int height = 360;
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({width,height}), "Title");
    window->setFramerateLimit(60);

    sf::CircleShape circle(64.0f);
    circle.setOrigin(circle.getGeometricCenter());
    circle.setPosition({ width / 4.0f, height / 4.0f });
    circle.setFillColor(sf::Color::Green);
    circle.setOutlineThickness(3.0f);
    circle.setOutlineColor(sf::Color::Red);
    circle.setPointCount(3);

    sf::RectangleShape rect({50.0f,80.0f});
    rect.setOrigin(rect.getSize() / 2.0f);
    rect.setPosition({ width / 2.0f, height / 2.0f });
    rect.setFillColor(sf::Color::Yellow);
    rect.setOutlineThickness(5.0f);
    rect.setOutlineColor(sf::Color::Blue);
    


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
        window->draw(circle);
        window->draw(rect);

        window->display();
    }


    delete window;
    return 0;
}