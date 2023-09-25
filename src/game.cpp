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
    //Score
    Ikah::Score score;
    score.getWindowDimensions(WINDOW_WIDTH, WINDOW_HEIGHT);
    score.createScoreText();

    //Background Gradient
    sf::Vertex backgroundGradient[4] = 
    {
        sf::Vertex(sf::Vector2f(0, 0), sf::Color(spanishRoast)),
        sf::Vertex(sf::Vector2f(0, WINDOW_WIDTH), sf::Color(shadowdancer)),
        sf::Vertex(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT), sf::Color(shadowdancer)),
        sf::Vertex(sf::Vector2f(WINDOW_WIDTH, 0), sf::Color(spanishRoast))
    };

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
        ball.brickCollision(bricks, score);
        //clear display
        window.clear();
        window.draw(backgroundGradient, 4, sf::Quads);
        //Draw here
        for(int i = 0; i < bricks.size(); i++)
        {
            window.draw(bricks[i]);
        }
        paddle.draw(window);
        ball.draw(window);
        score.draw(window);
        //End draw
        window.display();
    }
}