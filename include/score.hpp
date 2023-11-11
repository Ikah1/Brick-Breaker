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
            void centerScorePosition();
            void getFont(sf::Font &font);
        private:
            sf::Text scoreText;
            sf::Vector2i windowDimensions;
            sf::Font font;
            sf::Vector2f scorePosition;

            int score;
    };
}

#endif