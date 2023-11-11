#ifndef ROUND_WON
#define ROUND_WON

#include "definitions.hpp"
#include <vector>

namespace Ikah
{
    class RoundWon
    {
        public:
            RoundWon();
            void draw(sf::RenderWindow &window);
            bool noBricks(std::vector<sf::RectangleShape> bricks);
            void getWindowDimensions(int width, int height);
            void getFont(sf::Font &font);
            void quit(sf::RenderWindow &window);
            void setScoreText(int score);
        private:
            void createDialogBox();
            
            sf::RectangleShape quitButton;
            sf::Text quitText;
            sf::Text winText;
            sf::Text scoreText;
            sf::Font font;
            
            int windowWidth, windowHeight;
            bool wonRound = false;

    };
}

#endif