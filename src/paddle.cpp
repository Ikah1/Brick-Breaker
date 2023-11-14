#include "../include/paddle.hpp"

Ikah::Paddle::Paddle(int screenWidth, int screenHeight)
{
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;

    paddleWidth = screenWidth / 10;
    paddleHeight = paddleWidth / 4;

    aPressed = false;
    dPressed = false;

    position.x = (screenWidth / 2) - (paddleWidth / 2);
    position.y = screenHeight - (paddleHeight * 4);

    velocity = sf::Vector2f(0, 0);

    paddle.setFillColor(sf::Color(mainBlue));
    paddle.setOutlineColor(sf::Color(accentColor));
    paddle.setOutlineThickness(paddleHeight / 6);
    paddle.setSize(sf::Vector2f(paddleWidth, paddleHeight));
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
            velocity.x = -SPEED;
            paddle.move(velocity *  dt.asSeconds());
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        if (paddle.getPosition().x + paddleWidth < screenWidth)
        {
            velocity.x = SPEED;
            paddle.move(velocity * dt.asSeconds());
        }
    }
}

sf::RectangleShape &Ikah::Paddle::getPaddle()
{
    return paddle;
}