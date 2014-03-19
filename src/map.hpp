#ifndef MAP_HPP
#define MAP_HPP

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

typedef struct cell
{
    sf::Vector2f position;
    sf::Vector2f size;
    std::shared_ptr<sf::Texture> texture;
};

class Map
{
    public:
        Map(sf::RenderWindow& _window);
        ~Map();

        bool build();

    private:
        sf::RenderWindow& window;
        std::vector<cell> cells;
        sf::Texture texture1;
        sf::Texture texture2;
};

#endif // MAP_HPP
