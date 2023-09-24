#ifndef BRICKS_HPP
#define BRICKS_HPP

#include "definitions.hpp"
#include <vector>

namespace Ikah
{
    class Bricks
    {
        public:
            std::vector<sf::RectangleShape> createBricks(int rowAmount, int amountOfBricks);
            void setScreenDimensions(int width, int height);
        private:
            std::vector<sf::RectangleShape> createRow(int amount, int rowNumber);

            sf::Vector2i screenDimensions;
    };
}

#endif