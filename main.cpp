#include <iostream>
#include <SFML/Graphics.hpp>

enum diretions {down,left,up,right};

int main()
{
    unsigned int width = 640;
    unsigned int height = 360;
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({width,height}), "Title");
    window->setFramerateLimit(60);

    //todo sprite
    sf::Texture texture;

    if (!texture.loadFromFile("sprite/BODY_skeleton.png")){

        std::cerr<<"error load file skeleton"<< std::endl;
        return -1;         
    }

    sf::Sprite sprite(texture);

    sf::IntRect dir[4];

    for (int i = 0; i < 4; i++)
    {
        dir[i] = sf::IntRect( { {0 , 64*i},{64,64} } );
    }
    
    sprite.setTextureRect(dir[up]);
    sprite.setOrigin({64,64});
    sprite.setPosition({width/2.0f,height/2.0f});

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

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::S)){

            sprite.move({0.0f,1.0f});
            sprite.setTextureRect(dir[up]);            

        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::W)){

            sprite.move({0.0f,-1.0f});
            sprite.setTextureRect(dir[down]);
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::D)){

            sprite.move({1.0f,0.0f});
            sprite.setTextureRect(dir[right]);
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::A)){

            sprite.move({-1.0f,0.0f});
            sprite.setTextureRect(dir[left]);
        }
        //render
        window->clear(sf::Color(255,165,0));
        //draw
        window->draw(sprite);

        window->display();
    }


    delete window;
    return 0;
}