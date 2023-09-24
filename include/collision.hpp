#ifndef COLLISION_HPP
#include "definitions.hpp"

namespace Ikah
{
    class Collision
    {
        public:
            void paddleCollision(sf::RectangleShape &paddle, sf::CircleShape &ball);
        private:
    };
}

#endif