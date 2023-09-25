#include "../include/ball.hpp"
#include <iostream>

Ikah::Ball::Ball(int screenWidth, int screenHeight)
{
    this->windowWidth = screenWidth;
    this->windowHeight = screenHeight;

    ballRadius = screenWidth / 80;

    velocity.x = 0;
    velocity.y = 0;

    startingPosition.x = screenWidth / 2 - ballRadius;
    startingPosition.y = screenHeight / 2 - ballRadius;

    ball.setFillColor(sf::Color(blueCuracao));
    ball.setOutlineColor(sf::Color(pinkOrchid));
    ball.setOutlineThickness(ballRadius / 4);
    ball.setPosition(startingPosition);
    ball.setRadius(ballRadius);
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
        velocity.y = SPEED;
    }
}

void Ikah::Ball::collision(sf::RectangleShape &paddle, sf::Time dt)
{
    if (ball.getGlobalBounds().intersects(paddle.getGlobalBounds()))
    {
        if (ball.getPosition().x >= paddle.getPosition().x && ball.getPosition().x + (ballRadius * 2) <= paddle.getPosition().x + (paddle.getSize().x / 2))
        {
            velocity.x = -SPEED;
        }

        if (ball.getPosition().x >= paddle.getPosition().x + (paddle.getSize().x / 2) && ball.getPosition().x + (ballRadius * 2) <= paddle.getPosition().x + paddle.getSize().x)
        {
            velocity.x = SPEED;
        }
        velocity.y = -velocity.y;
    }

    if (ball.getPosition().x <= 0 || ball.getPosition().x + (ballRadius * 2) >= windowWidth)
    {
        velocity.x = -velocity.x;
    }

    if (ball.getPosition().y <= 0)
    {
        velocity.y = -velocity.y;
    }

    if (ball.getPosition().y + ballRadius * 2 >= windowHeight)
    {
        velocity = sf::Vector2f(0, 0);
        ball.setPosition(startingPosition);
    }
}

void Ikah::Ball::brickCollision(std::vector<sf::RectangleShape> &bricks, Ikah::Score &score)
{
    for (int i = 0; i < bricks.size(); i++)
    {
        if (ball.getGlobalBounds().intersects(bricks[i].getGlobalBounds()))
        {
            velocity = -velocity;
            bricks.erase(bricks.begin() + i);
            score.setScore(score.getScore() + 5);
        }
    }
}

void Ikah::Ball::setVelocity(sf::Vector2f velocity)
{
    this->velocity = velocity;
}

sf::Vector2f Ikah::Ball::getVelocity()
{
    return velocity;
}

sf::CircleShape Ikah::Ball::getBall()
{
    return ball;
}
