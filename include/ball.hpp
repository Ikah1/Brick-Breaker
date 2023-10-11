#ifndef BALL_HPP

#include <SFML/Audio.hpp>
#include "definitions.hpp"
#include "score.hpp"

namespace Ikah
{
    class Ball
    {
        public:
            Ball(int screenWidth, int screenHeight);

            void update(sf::Time dt);
            void draw(sf::RenderWindow &window);
            void input(sf::Time dt);
            void collision(sf::RectangleShape &paddle, sf::Time dt, Score &score);
            void brickCollision(std::vector<sf::RectangleShape> &bricks, Ikah::Score &score);
            void setBallPosition();

            sf::CircleShape getBall();
        private:
            sf::CircleShape ball;
            sf::CircleShape createBall(int windowWidth);

            sf::Vector2f startingPosition;
            sf::Vector2f velocity;

            const float Y_SPEED = 500.0f;
            const float X_SPEED = 200.0f;
            int windowWidth, windowHeight;

            sf::SoundBuffer dieBuffer;
            sf::Sound dieSound;
            sf::SoundBuffer bounceSoundBuffer;
            sf::Sound bounceSound;
            sf::SoundBuffer breakSoundBuffer;
            sf::Sound breakSound;
    };
}

#endif