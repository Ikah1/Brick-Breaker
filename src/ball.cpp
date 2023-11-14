#include "../include/ball.hpp"
#include <iostream>

Ikah::Ball::Ball(int screenWidth, int screenHeight)
{
    this->windowWidth = screenWidth;
    this->windowHeight = screenHeight;

    if (!ballTexture.loadFromFile("../assets/sprites/ball.png"))
    {
        std::cout << "failed to load ball texture" << std::endl;
    }
    ball.setTexture(ballTexture);
    ball.setScale(0.25f, 0.25f);
    setBallPosition();

    //creating sfx
    dieBuffer.loadFromFile("../assets/sounds/die sfx.wav");
    dieSound.setBuffer(dieBuffer);
    dieSound.setVolume(50);

    bounceSoundBuffer.loadFromFile("../assets/sounds/Bounce.wav");
    bounceSound.setBuffer(bounceSoundBuffer);
    bounceSound.setVolume(50);

    breakSoundBuffer.loadFromFile("../assets/sounds/Break.wav");
    breakSound.setBuffer(breakSoundBuffer);
    breakSound.setVolume(50);

    dead = true;
}

void Ikah::Ball::draw(sf::RenderWindow &window) 
{
    window.draw(ball);
}

void Ikah::Ball::update(sf::Time dt)
{
    ball.move(velocity * dt.asSeconds());
}

void Ikah::Ball::input(sf::Time dt)
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        if (dead)
        {
            //Move the ball towards the paddle if spacebar is pressed
            velocity.y = Y_SPEED;
            running = true;
            dead = false;
        }
    }
}

void Ikah::Ball::collision(sf::RectangleShape &paddle, sf::Time dt, Score &score)
{
    float ballPosX = ball.getPosition().x;
    float ballPosY = ball.getPosition().y;
    float paddlePosX = paddle.getPosition().x;
    float ballWidth = ball.getGlobalBounds().width;
    float ballHeight = ball.getGlobalBounds().height;

    //Check if ball is intersecting with paddle
    if (ball.getGlobalBounds().intersects(paddle.getGlobalBounds()))
    {
        velocity.y = -velocity.y;
        //Check if the ball hits the left or ride side of the paddle 
        float paddleWidth = paddle.getGlobalBounds().width;
        float paddleCenterX = paddlePosX + paddleWidth / 2;
        float ballCenterX = ballPosX + ballWidth / 2;
        float difference = ballCenterX - paddleCenterX;

        if (difference < 0)
        {
            velocity.x = -X_SPEED;
        }
        else if (difference > 0)
        {
            velocity.x = X_SPEED;
        }
        bounceSound.play();
    }
    //Check if ball hit either wall on the sides
    if (ballPosX <= 0 || ballPosX + ballWidth >= windowWidth)
    {
        velocity.x = -velocity.x;
        bounceSound.play();
    }
    //Check if ball hit top of the screen
    if (ballPosY <= 0)
    {
        velocity.y = -velocity.y;
        bounceSound.play();
    }

    ///Check if ball left bottom of the screen (missed with the paddle)
    if (ballPosY + ballHeight >= windowHeight)
    {
        dead = true;
        velocity = sf::Vector2f(0, 0);
        ball.setPosition(startingPosition);
        score.setScore(score.getScore() - 50);
        if (score.getScore() < 0)
        {
            score.setScore(0);
        }
        dieSound.play();
    }
}

void Ikah::Ball::brickCollision(std::vector<sf::Sprite> &bricks, Ikah::Score &score)
{
    for (int i = 0; i < bricks.size(); i++)
    {
        if (ball.getGlobalBounds().intersects(bricks[i].getGlobalBounds()))
        {
            velocity.y = -velocity.y;
            bricks.erase(bricks.begin() + i);
            score.setScore(score.getScore() + 5);
            breakSound.play();
        }
    }
}

void Ikah::Ball::setBallPosition()
{
    //Set starting position in middle of the screen
    startingPosition = sf::Vector2f(windowWidth / 2 - ball.getGlobalBounds().width / 2, windowHeight / 2 - ball.getGlobalBounds().height / 2);
    ball.setPosition(startingPosition);

    velocity = sf::Vector2f(0, 0);
}

void Ikah::Ball::setSfxVolume(int value)
{
    this->dieSound.setVolume(value);
    this->bounceSound.setVolume(value);
    this->breakSound.setVolume(value);
}

bool Ikah::Ball::setGameRunning()
{
    return running;
}
