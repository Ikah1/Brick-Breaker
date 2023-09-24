#ifndef BALL_HPP

#include "definitions.hpp"

namespace Ikah
{
    class Ball
    {
        public:
            Ball(int screenWidth, int screenHeight);
            void update(sf::Time dt);
            void draw(sf::RenderWindow &window);
            void input(sf::Time dt);
            void collision(sf::RectangleShape &paddle, sf::Time dt);
            void brickCollision(std::vector<sf::RectangleShape> &bricks);
            void setVelocity(sf::Vector2f velocity);
            sf::Vector2f getVelocity();
            sf::CircleShape getBall();
        private:
            sf::CircleShape ball;
            sf::Vector2f startingPosition;
            sf::Vector2f velocity;
            const float SPEED = 300.0f;
            int ballRadius;
            int windowWidth, windowHeight;
    };
}

#endif