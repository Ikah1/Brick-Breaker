#ifndef BRICKS_HPP
#define BRICKS_HPP

#include "definitions.hpp"
#include <vector>

namespace Ikah
{
    class Bricks
    {
        public:
            std::vector<sf::RectangleShape> createBricks(int rowAmount, int amountOfBricks, int screenWidth, int screenHeight);
        private:
            std::vector<sf::RectangleShape> createRow(int amount, int rowNumber, int screenWidth, int screenHeight);
            const int GAP = 10;
            const int OFFSET = 5;
    };
}

#endif