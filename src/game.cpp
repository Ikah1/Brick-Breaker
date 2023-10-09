#include "../include/game.hpp"
#include <iostream>

Ikah::Game::Game()
{   
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Brick-Breaker");
    window.setFramerateLimit(30);

    //Background music
    sf::Music backgroundMusic;
    backgroundMusic.openFromFile("../assets/sounds/Space Mission.wav");
    backgroundMusic.setVolume(75);
    backgroundMusic.setLoop(true);
    backgroundMusic.play();


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
    //roundWon
    Ikah::RoundWon roundWon;
    roundWon.getWindowDimensions(WINDOW_WIDTH, WINDOW_HEIGHT);
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

        if (!wonRound)
        {
            //Check for updates
            paddle.update(dt);
            ball.update(dt);
            //Check for collision
            ball.collision(paddle.getPaddle(), dt, score);
            ball.brickCollision(bricks, score);
            //Check if there are no bricks left
            roundWon.noBricks(bricks);
            //Keep score centered
            score.centerScorePosition();
        }

        if (roundWon.noBricks(bricks))
        {
            wonRound = true;
            roundWon.setScoreText(score.getScore());
            roundWon.quit(window);
            ball.setBallPosition();
        }
        //clear display
        window.clear();
        window.draw(backgroundGradient, 4, sf::Quads);
        //Draw here
        for(int i = 0; i < bricks.size(); i++)
        {
            window.draw(bricks[i]);
        }
        if (!wonRound)
        {
            paddle.draw(window);
            ball.draw(window);
            score.draw(window);
        }
        
        if (wonRound)
        {
            roundWon.draw(window);
        }
        //End draw
        window.display();
    }
}