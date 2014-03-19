#include "map.hpp"
#include <iostream>

Map::Map(sf::RenderWindow& _window) :
    window(_window)
{
    texture1.loadFromFile("ressources/sprites/grass1.png");
    texture1.setSmooth(true);

    texture2.loadFromFile("ressources/sprites/sand1.png");
    texture2.setSmooth(true);

    int maxy = 17, maxx = 15;

    for(int y = 0, cellid = 0; y < maxy; y++)
    {
        for(int x = 0; x < maxx; x++, cellid++)
        {
            cell current_cell;
            current_cell.position = sf::Vector2f(x * 55.f, y * 28.f);
            current_cell.size = sf::Vector2f(55.f, 28.f);
            current_cell.texture.reset(&texture1);

            cells.push_back(current_cell);
        }

        if(y != maxy -1)
        {
            for(int x = 0; x < maxx - 1; x++, cellid++)
            {
                cell current_cell;
                current_cell.position = sf::Vector2f(x * 55.f + 27.5f, y * 28.f + 14.f);
                current_cell.size = sf::Vector2f(55.f, 28.f);
                current_cell.texture.reset(&texture2);

                cells.push_back(current_cell);
            }
        }
    }
}

Map::~Map()
{
}

bool Map::build()
{
    for(int i = 0; i < (int)cells.size(); i++)
    {
        sf::Sprite sprite(*(cells[i].texture), sf::IntRect(0, 0, 55, 28));
        sprite.setPosition(cells[i].position);
        window.draw(sprite);
    }

    return true;
}
