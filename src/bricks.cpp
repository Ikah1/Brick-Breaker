#include "../include/bricks.hpp"

std::vector<sf::RectangleShape> Ikah::Bricks::createRow(int amount, int rowNumber, int screenWidth, int screenHeight)
{
    std::vector<sf::RectangleShape> brickRow;
    int brickWidth = (screenWidth / amount) - GAP;
    int brickHeight  = (brickWidth / 4);
    for (int i = 0; i < amount; i++)
    {
        sf::RectangleShape brick(sf::Vector2f(brickWidth, brickHeight));
        brick.setFillColor(sf::Color(FOREGROUND_COLOR));
        if (i == 0)
        {
            brick.setPosition(OFFSET, rowNumber * (brickHeight + GAP));
        } else
        {
            brick.setPosition(i * (GAP + brickWidth) + OFFSET, rowNumber * (brickHeight + GAP));
        }
        brickRow.push_back(brick);
    }
    return brickRow;
}

std::vector<sf::RectangleShape> Ikah::Bricks::createBricks(int amountOfBricks, int rowAmount, int screenWidth, int screenHeight)
{
    std::vector<sf::RectangleShape> bricks;

    for (int i = 0; i < rowAmount; i++)
    {
        std::vector<sf::RectangleShape> row = createRow(amountOfBricks, i, screenWidth, screenHeight);
        for (auto &brick : row)
        {
            bricks.push_back(brick);
        }
    }
    return bricks;
}


