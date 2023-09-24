#include "../include/game.hpp"
#include <iostream>

Ikah::Game::Game()
{   
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Brick-Breaker");
    window.setFramerateLimit(30);

    //Pass Window Dimensions to brick class and create bricks
    bricksObject.setScreenDimensions(WINDOW_WIDTH, WINDOW_HEIGHT);
    bricks = bricksObject.createBricks(10, 5);

    //Create Paddle and Ball
    Ikah::Paddle paddle(WINDOW_WIDTH, WINDOW_HEIGHT);
    Ikah::Ball ball(WINDOW_WIDTH, WINDOW_HEIGHT);

    //Main Loop
    while (window.isOpen())
    {

        sf::Event event;
        dt = deltaClock.restart();
        //Check For Input Events
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
        window.clear(sf::Color(spanishRoast));
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