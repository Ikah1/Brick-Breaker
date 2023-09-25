#ifndef SCORE_HPP
#define SCORE_HPP

#include "definitions.hpp"

namespace Ikah
{
    class Score
    {
        public:
            void createScoreText();
            void draw(sf::RenderWindow &window);
            void setScore(int score);
            int getScore();
            void getWindowDimensions(int width, int height);
        private:
            sf::Text scoreText;
            int score;
            sf::Vector2i windowDimensions;
            sf::Font font;
    };
}

#endif