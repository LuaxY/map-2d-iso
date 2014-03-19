#include <iostream>
#include <SFML/Graphics.hpp>

#include "map.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 600, 32), "map-2d-iso", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);

    Map map1(window);

    while(window.isOpen())
    {
        sf::Event event;

        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        if(!map1.build())
            return -1;

        window.display();
    }

    return EXIT_SUCCESS;
}
