#include "../include/game.hpp"
#include <iostream>

Ikah::Game::Game()
{   
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Brick-Breaker", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(30);

    bricks = bricksObject.createBricks(10, 5, WINDOW_WIDTH, WINDOW_HEIGHT);

    Ikah::Paddle paddle(WINDOW_WIDTH, WINDOW_HEIGHT);
    Ikah::Ball ball(WINDOW_WIDTH, WINDOW_HEIGHT);

    while (window.isOpen())
    {
        sf::Event event;
        dt = deltaClock.restart();
        while(window.pollEvent(event))
        {
            //Close Window
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
            ball.input(dt);
        }
        //update here
        paddle.update(dt);
        ball.update(dt);
        ball.collision(paddle.getPaddle(), dt);
        ball.brickCollision(bricks);
        //clear display
        window.clear(sf::Color(BACKGROUND_COLOR));
        //Draw here
        for(int i = 0; i < bricks.size(); i++)
        {
            window.draw(bricks[i]);
        }
        paddle.draw(window);
        ball.draw(window);
        //End draw
        window.display();
    }
}