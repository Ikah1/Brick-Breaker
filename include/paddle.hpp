#ifndef PADDLE_HPP

#include "definitions.hpp"

namespace Ikah
{
    class Paddle
    {
        public:
            Paddle(int screenWidth, int screenHeight);
            void update(sf::Time dt);
            void draw(sf::RenderWindow &window);
            sf::RectangleShape &getPaddle();
        private:
            void input(sf::Time dt);
            
            sf::RectangleShape paddle;

            int paddleWidth, paddleHeight;
            int screenWidth, screenHeight;

            const float SPEED = 350.0f;
            float x, y;

            bool aPressed, dPressed;

            sf::Vector2f velocity;
            sf::Vector2f position;
    };
}

#endif