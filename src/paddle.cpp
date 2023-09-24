#include "../include/paddle.hpp"
#include <iostream>

Ikah::Paddle::Paddle(int screenWidth, int screenHeight)
{
    aPressed = false;
    dPressed = false;

    position.x = (screenWidth / 2) - (PADDLE_WIDTH / 2);
    position.y = screenHeight - (PADDLE_HEIGHT * 4);

    velocity = sf::Vector2f(0, 0);

    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    paddle.setFillColor(sf::Color(FOREGROUND_COLOR));
    paddle.setSize(sf::Vector2f(PADDLE_WIDTH, PADDLE_HEIGHT));
    paddle.setPosition(position);

}

void Ikah::Paddle::draw(sf::RenderWindow &window)
{
    window.draw(paddle);
}

void Ikah::Paddle::update(sf::Time dt)
{
    input(dt);
}

void Ikah::Paddle::input(sf::Time dt)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
        if (paddle.getPosition().x > 0)
        {
            velocity.x = -SPEED *  dt.asSeconds();
            paddle.move(velocity);
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        if (paddle.getPosition().x + PADDLE_WIDTH < screenWidth)
        {
            velocity.x = SPEED * dt.asSeconds();
            paddle.move(velocity);
        }
    }
}

sf::RectangleShape &Ikah::Paddle::getPaddle()
{
    return paddle;
}