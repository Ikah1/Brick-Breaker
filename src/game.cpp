#include "../include/game.hpp"
#include <iostream>

Ikah::Game::Game()
{   
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Brick-Breaker");
    window.setFramerateLimit(30);

    sf::Font font;
    if (!font.loadFromFile("../assets/fonts/NERDFONT-REGULAR.ttf"))
    {
        std::cout << "Error loading font" << std::endl;
    }

    //Background music
    sf::Music backgroundMusic;
    backgroundMusic.openFromFile("../assets/sounds/Space Mission.wav");
    backgroundMusic.setVolume(50);
    backgroundMusic.setLoop(true);
    backgroundMusic.play();

    //Pass Window Dimensions to brick class and create bricks
    Ikah::Bricks bricksObject;
    bricksObject.setScreenDimensions(WINDOW_WIDTH, WINDOW_HEIGHT);
    bricks = bricksObject.createBricks(10, 5);

    //Create Paddle and Ball
    Ikah::Paddle paddle(WINDOW_WIDTH, WINDOW_HEIGHT);
    Ikah::Ball ball(WINDOW_WIDTH, WINDOW_HEIGHT);
    //Score
    Ikah::Score score;
    score.getFont(font);
    score.getWindowDimensions(WINDOW_WIDTH, WINDOW_HEIGHT);
    score.createScoreText();
    //roundWon
    Ikah::RoundWon roundWon;
    roundWon.getFont(font);
    roundWon.getWindowDimensions(WINDOW_WIDTH, WINDOW_HEIGHT);
    //Settings Menu
    Ikah::Settings settings;
    settings.setFont(font);
    settings.createGUI(WINDOW_WIDTH, WINDOW_HEIGHT);

    //Background Gradient
    sf::Vertex backgroundGradient[4] = 
    {
        sf::Vertex(sf::Vector2f(0, 0), sf::Color(spanishRoast)),
        sf::Vertex(sf::Vector2f(0, WINDOW_WIDTH), sf::Color(shadowdancer)),
        sf::Vertex(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT), sf::Color(shadowdancer)),
        sf::Vertex(sf::Vector2f(WINDOW_WIDTH, 0), sf::Color(spanishRoast))
    };
    
    title.setFont(font);
    title.setCharacterSize(WINDOW_WIDTH / 12);
    title.setString("Brick Breaker");
    title.setPosition(WINDOW_WIDTH / 2 - title.getGlobalBounds().width / 2, WINDOW_HEIGHT / 2);

    toolTip.setFont(font);
    toolTip.setCharacterSize(WINDOW_WIDTH / 48);
    toolTip.setString("Use 'W & D' to move, press 'spacebar' to start, press 'Esc' for settings...");
    toolTip.setPosition(WINDOW_WIDTH / 2 - toolTip.getGlobalBounds().width / 2, WINDOW_HEIGHT / 1.5f);

    //Main Loop
    while (window.isOpen())
    {
        sf::Event event;
        dt = deltaClock.restart();
        //Check For Input Events
        while (window.pollEvent(event))
        {
            //Close Window
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                displayTitle = false;
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
            //Settings Menu
            settings.update(window);
            backgroundMusic.setVolume(settings.getMusicVolume());
            ball.setSfxVolume(settings.getSfxVolume());
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
        if (displayTitle)
        {
            window.draw(title);
            window.draw(toolTip);
        }

        if (!wonRound)
        {
            for(int i = 0; i < bricks.size(); i++)
            {
                window.draw(bricks[i]);
            }
            paddle.draw(window);
            ball.draw(window);
            score.draw(window);
            settings.draw(window);
        }
        
        if (wonRound)
        {
            roundWon.draw(window);
        }
        //End draw
        window.display();
    }
}