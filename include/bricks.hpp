#ifndef BRICKS_HPP
#define BRICKS_HPP

#include "definitions.hpp"
#include <vector>

namespace Ikah
{
    class Bricks
    {
        public:
            Bricks();
            std::vector<sf::Sprite> createBricks(int rowAmount, int amountOfBricks);
            void setScreenDimensions(int width, int height);
        private:
            std::vector<sf::Sprite> createRow(int amount, int rowNumber);

            sf::Texture brickTexture;

            sf::Vector2i screenDimensions;
    };
}

#endif