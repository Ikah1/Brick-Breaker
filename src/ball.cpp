#include "../include/ball.hpp"
#include <iostream>

Ikah::Ball::Ball(int screenWidth, int screenHeight)
{
    this->windowWidth = screenWidth;
    this->windowHeight = screenHeight;

    ball = createBall(windowWidth);
    setBallPosition();

    //creating sfx
    dieBuffer.loadFromFile("../assets/sounds/die sfx.wav");
    dieSound.setBuffer(dieBuffer);
    dieSound.setVolume(85);
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
        //Move the ball towards the paddle if spacebar is pressed
        velocity.y = Y_SPEED;
    }
}

void Ikah::Ball::collision(sf::RectangleShape &paddle, sf::Time dt, Score &score)
{
    //Check if ball is intersecting with paddle
    if (ball.getGlobalBounds().intersects(paddle.getGlobalBounds()))
    {
        velocity.y = -velocity.y;
        //Check if ball hit left side of the paddle
        if (ball.getPosition().x >= paddle.getPosition().x && ball.getPosition().x + ball.getRadius() * 2 < paddle.getPosition().x + paddle.getGlobalBounds().width / 2)
        {
            velocity.x = -X_SPEED;
        }
        //Check if ball hit right side of the paddle
        if (ball.getPosition().x > paddle.getPosition().x + paddle.getGlobalBounds().width / 2 && ball.getPosition().x + (ball.getRadius() * 2) <= paddle.getPosition().x + paddle.getSize().x)
        {
            velocity.x = X_SPEED;
        }
    }
    //Check if ball hit either wall on the sides
    if (ball.getPosition().x <= 0 || ball.getPosition().x + (ball.getRadius() * 2) >= windowWidth)
    {
        velocity.x = -velocity.x;
    }
    //Check if ball hit top of the screen
    if (ball.getPosition().y <= 0)
    {
        velocity.y = -velocity.y;
    }

    ///Check if ball left bottom of the screen (missed with the paddle)
    if (ball.getPosition().y + ball.getRadius() * 2 >= windowHeight)
    {
        velocity = sf::Vector2f(0, 0);
        ball.setPosition(startingPosition);
        score.setScore(score.getScore() - 50);
        if (score.getScore() < 0)
        {
            score.setScore(0);
            dieSound.play();
        }
    }
}

void Ikah::Ball::brickCollision(std::vector<sf::RectangleShape> &bricks, Ikah::Score &score)
{
    for (int i = 0; i < bricks.size(); i++)
    {
        if (ball.getGlobalBounds().intersects(bricks[i].getGlobalBounds()))
        {
            velocity.y = -velocity.y;
            bricks.erase(bricks.begin() + i);
            score.setScore(score.getScore() + 5);
        }
    }
}

void Ikah::Ball::setBallPosition()
{
    //Set starting position in middle of the screen
    startingPosition = sf::Vector2f(windowWidth / 2 - ball.getRadius(), windowHeight / 2 - ball.getRadius());
    ball.setPosition(startingPosition);

    velocity = sf::Vector2f(0, 0);
}

sf::CircleShape Ikah::Ball::createBall(int windowWidth)
{
    sf::CircleShape ball;
    int ballRadius = windowWidth / 80;
    ball.setFillColor(sf::Color(blueCuracao));
    ball.setOutlineColor(sf::Color(pinkOrchid));
    ball.setOutlineThickness(ballRadius / 4);
    ball.setRadius(ballRadius);
    return ball;
}

sf::CircleShape Ikah::Ball::getBall()
{
    return ball;
}
