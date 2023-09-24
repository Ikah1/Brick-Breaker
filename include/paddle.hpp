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
            const int PADDLE_WIDTH = 100;
            const int PADDLE_HEIGHT = 20;
            int screenWidth, screenHeight;
            const float SPEED = 250.0f;
            sf::Vector2f velocity;
            sf::Vector2f position;
            float x, y;
            bool aPressed, dPressed;
    };
}

#endif