#include "../include/score.hpp"
#include <iostream>

void Ikah::Score::createScoreText()
{
    score = 0;
    scorePosition = sf::Vector2f(windowDimensions.x / 2 - scoreText.getGlobalBounds().width / 2, windowDimensions.y - scoreText.getCharacterSize() * 1.2f);
    //Create score text
    scoreText.setFont(font);
    scoreText.setString(std::to_string(score));
    scoreText.setCharacterSize(windowDimensions.x / 16);
    scoreText.setPosition(scorePosition);
    scoreText.setFillColor(sf::Color(blueCuracao));
    scoreText.setOutlineColor(sf::Color(pinkOrchid));
    scoreText.setOutlineThickness(scoreText.getCharacterSize() / 16);
}

void Ikah::Score::draw(sf::RenderWindow &window)
{
    window.draw(scoreText);
}

void Ikah::Score::centerScorePosition()
{
    scorePosition = sf::Vector2f(windowDimensions.x / 2 - scoreText.getGlobalBounds().width / 2, windowDimensions.y - scoreText.getCharacterSize() * 1.2f);
    scoreText.setPosition(scorePosition);
}

void Ikah::Score::setScore(int score)
{
    this->score = score;
    scoreText.setString(std::to_string(score));
}

int Ikah::Score::getScore()
{
    return this->score;
}

void Ikah::Score::getWindowDimensions(int width, int height)
{
    windowDimensions = sf::Vector2i(width, height);
}

void Ikah::Score::getFont(sf::Font &font)
{
    this->font = font;
}