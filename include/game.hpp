#ifndef GAME_HPP
#include "definitions.hpp"
#include "bricks.hpp"
#include "paddle.hpp"
#include "ball.hpp"
#include "roundWon.hpp"
#include "settings.hpp"

namespace Ikah
{
    class Game
    {
        public: 
            Game();
        private:
            const int WINDOW_WIDTH = 1200;
            const int WINDOW_HEIGHT = 800;

            sf::Clock deltaClock;
            sf::Time dt;
            
            std::vector<sf::RectangleShape> bricks;

            bool wonRound = false;
            bool displayTitle = true;

            sf::Text title;
            sf::Text toolTip;
    };
}
#endif