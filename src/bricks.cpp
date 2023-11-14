#include "../include/bricks.hpp"
#include <iostream>
#include <cmath>

Ikah::Bricks::Bricks()
{
    if (!brickTexture.loadFromFile("../assets/sprites/brick.png"))
    {
        std::cout << "Error loading brick texture." << std::endl;
    }
}

std::vector<sf::Sprite> Ikah::Bricks::createRow(int amount, int rowNumber)
{
    std::vector<sf::Sprite> brickRow;

    int gap = screenDimensions.x / pow(amount, 2);
    int offset = gap / 2;

    float brickWidth = (screenDimensions.x / amount) - gap;
    float brickHeight  = (brickWidth / 4);
    float scaleX = brickWidth / 250;
    float scaleY = brickHeight / 100;
    
    for (int i = 0; i < amount; i++)
    {
        sf::Sprite brick;
        brick.setTexture(brickTexture);
        brick.setScale(scaleX, scaleY);
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

std::vector<sf::Sprite> Ikah::Bricks::createBricks(int amountOfBricks, int rowAmount)
{
    std::vector<sf::Sprite> bricks;

    for (int i = 0; i < rowAmount; i++)
    {
        std::vector<sf::Sprite> row = createRow(amountOfBricks, i);
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


