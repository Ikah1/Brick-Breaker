#include "../include/bricks.hpp"
#include <cmath>

std::vector<sf::RectangleShape> Ikah::Bricks::createRow(int amount, int rowNumber)
{
    std::vector<sf::RectangleShape> brickRow;

    int gap = screenDimensions.x / pow(amount, 2);
    int offset = gap / 2;

    int brickWidth = (screenDimensions.x / amount) - gap;
    int brickHeight  = (brickWidth / 4);
    
    for (int i = 0; i < amount; i++)
    {
        sf::RectangleShape brick(sf::Vector2f(brickWidth, brickHeight));
        brick.setFillColor(sf::Color(lilacRose));
        brick.setOutlineColor(sf::Color(pinkOrchid));
        brick.setOutlineThickness(brickHeight / 5);
        if (i == 0)
        {
            brick.setPosition(offset, rowNumber * (brickHeight + gap) + offset);
        } else
        {
            brick.setPosition(i * (gap + brickWidth) + offset, rowNumber * (brickHeight + gap) + offset);
        }
        brickRow.push_back(brick);
    }
    return brickRow;
}

std::vector<sf::RectangleShape> Ikah::Bricks::createBricks(int amountOfBricks, int rowAmount)
{
    std::vector<sf::RectangleShape> bricks;

    for (int i = 0; i < rowAmount; i++)
    {
        std::vector<sf::RectangleShape> row = createRow(amountOfBricks, i);
        for (auto &brick : row)
        {
            bricks.push_back(brick);
        }
    }
    return bricks;
}

void Ikah::Bricks::setScreenDimensions(int width, int height)
{
    screenDimensions = sf::Vector2i(width, height);
}


